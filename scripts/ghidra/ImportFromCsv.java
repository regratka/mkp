/*
 * LICENSE
 */
// Description
//@author roblabla
//@category exports
//@keybinding
//@menupath Skeleton
//@toolbar Skeleton
import ghidra.app.script.GhidraScript;
import ghidra.app.util.NamespaceUtils;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Namespace;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.util.exception.DuplicateNameException;
import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Iterator;

public class ImportFromCsv extends GhidraScript
{
    @Override protected void run() throws Exception
    {
        File inFile = askFile("Input CSV", "");

        Scanner sc = new Scanner(inFile);

        // Give name to everything
        while (sc.hasNextLine())
        {
            String v = sc.nextLine();
            String[] values = v.split(";");
            String mangledName = values[0];
            String name = values[1];
            Address addr = this.toAddr(values[2]);
            Long size = Long.decode(values[3]);
            AddressSet range = new AddressSet(addr, size > 0 ? addr.add(size - 1) : addr);

            // Get the parent namespace.
            List<String> namespaceElems = new ArrayList<>(Arrays.asList(name.split("::")));
            String funName = namespaceElems.removeLast();

            Namespace curNamespace = this.getCurrentProgram().getGlobalNamespace();
            for (String curElem : namespaceElems)
            {
                Namespace ns;
                if ((ns = this.getNamespace(curNamespace, curElem)) != null)
                {
                    curNamespace = ns;
                }
                else
                {
                    // Create the namespace
                    curNamespace = this.getCurrentProgram().getSymbolTable().createNameSpace(curNamespace, curElem,
                                                                                             SourceType.USER_DEFINED);
                    printf("Created namespace %s\n", curNamespace.getName(true));
                }
            }

            // Check if a function already exists.
            Function fun = this.getFunctionContaining(addr);

            if (fun == null)
            {
                printf("No function exist for %s at %x - creating\n", name, addr.getOffset());
                fun = getCurrentProgram().getFunctionManager().createFunction(funName, curNamespace, addr, range, SourceType.USER_DEFINED);
            }
            //  else if(!fun.getBody().contains(range)) { // Fixes function boundaries with try-catch
            //     printf("Updating the body scope for %s from %s to %s\n", name, fun.getBody().toString(), range.toString());
            //     Iterator<Function> overFuns = getCurrentProgram().getFunctionManager().getFunctionsOverlapping(range);
            //     while(overFuns.hasNext()) {
            //         Function overlap = overFuns.next();
            //         getCurrentProgram().getFunctionManager().removeFunction(overlap.getEntryPoint());
            //     }
            //     fun = getCurrentProgram().getFunctionManager().createFunction(funName, curNamespace, addr, range, SourceType.USER_DEFINED);
            //     printf("Created function %s at adresses %s\n", name, fun.getBody().toString());
            // }
            fun.setParentNamespace(curNamespace);
            try
            {
                fun.setName(funName, SourceType.USER_DEFINED);
            } catch (DuplicateNameException ex)
            {
                printf("DuplicateNameException for %s at %x\n", name, addr.getOffset());
            }

            if (!mangledName.isEmpty() && getCurrentProgram().getSymbolTable().getGlobalSymbol(mangledName, addr) == null) {
                printf("Creating label %s\n", mangledName);
                createLabel(addr, mangledName, false);
                createLabel(addr, mangledName, curNamespace, false, SourceType.USER_DEFINED);
            }
        }

        // Go over the switchD, and fix them. Sometimes they have duplicate
        // symbols, which leads to problem in the delinker extension.
        HashSet set = new HashSet<>();
        for (Symbol sym : this.getCurrentProgram().getSymbolTable().getSymbolIterator())
        {
            if (sym.getName().startsWith("caseD"))
            {
                String fullyQualifiedName =
                    NamespaceUtils.getNamespaceQualifiedName(sym.getParentNamespace(), sym.getName(), false);
                if (!set.add(fullyQualifiedName))
                {
                    sym.setName(sym.getName() + "__default", SourceType.USER_DEFINED);
                }
            }
        }
    }
}
