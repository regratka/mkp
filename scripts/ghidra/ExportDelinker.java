/*
 * LICENSE
 */
// Description
//@author renzo904
//@category exports
//@keybinding
//@menupath Skeleton
//@toolbar Skeleton
import static java.util.Map.entry;

import ghidra.app.analyzers.RelocationTableSynthesizerAnalyzer;
import ghidra.app.script.GhidraScript;
import ghidra.app.services.Analyzer;
import ghidra.app.util.DomainObjectService;
import ghidra.app.util.Option;
import ghidra.app.util.exporter.CoffRelocatableObjectExporter;
import ghidra.app.util.importer.MessageLog;
import ghidra.framework.model.DomainFile;
import ghidra.framework.model.DomainObject;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.GhidraClass;
import ghidra.program.model.listing.Function;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Namespace;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import java.io.File;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;

public class ExportDelinker extends GhidraScript
{
    @Override protected void run() throws Exception
    {
        // First run the Relocation Table Synthesizer, to pickup any potentially
        // new globals in the reloc table.
        Analyzer analyzer = new RelocationTableSynthesizerAnalyzer();
        analyzer.added(currentProgram, currentProgram.getMemory(), monitor, new MessageLog());

        // Then, export the COFFs.
        CoffRelocatableObjectExporter exporter = new CoffRelocatableObjectExporter();

        List<Option> exporterOptions = exporter.getOptions(new DomainObjectService() {
            @Override public DomainObject getDomainObject()
            {
                return currentProgram;
            }
        });

        exporter.setOptions(exporterOptions);

        File inFile = askFile("Config File", "Select");
        File preferredNamesFile = askFile("Preferred File", "Select");

        Map<String, Set<String>> preferredNamesByClass = new HashMap<>();

        Scanner sc = new Scanner(preferredNamesFile);
        while (sc.hasNextLine()) {
            String v = sc.nextLine();
            String[] values = v.split(";");
            String mangledName = values[0];
            String name = values[1];
            if (mangledName.isEmpty()) {
                continue;
            }

            List<String> namespaceElems = new ArrayList<>(Arrays.asList(name.split("::")));
            namespaceElems.removeLast();
            String fullClassName = String.join("::", namespaceElems);
			Set<String> prefNames = preferredNamesByClass.get(fullClassName);
			if (prefNames == null) {
				prefNames = new HashSet<>();
				preferredNamesByClass.put(fullClassName, prefNames);
			}
			prefNames.add(mangledName);
        }


        File outDir = askDirectory("Output Folder", "Select");

        String configFile = Files.readString(inFile.toPath(), StandardCharsets.UTF_8);
        Iterable<String> iterable = () -> configFile.lines().iterator();
        for (String objDataStr : iterable)
        {
            List<String> objData = new ArrayList<>(Arrays.asList(objDataStr.split(",")));

            String objClass = objData.remove(0);

            File outFile = new File(outDir, objClass + ".obj");

            AddressSet set = new AddressSet();
        
            exporter.getActiveSymbolPreference().clearCustomPreferrences();
            for (String ghidraClassName : objData)
            {
                printf("Handling %s.obj - class %s\n", objClass, ghidraClassName);
                
                Set<String> classNames = preferredNamesByClass.get(ghidraClassName);
                if (classNames != null) {
                    for (String name : classNames) {
                        exporter.getActiveSymbolPreference().addPreferredName(name);
                    }
                }

                List<String> ghidraClassNameParts = new ArrayList<>(Arrays.asList(ghidraClassName.split("::")));
                String finalPart = ghidraClassNameParts.removeLast();

                Namespace curNs = null;
                for (String nsPart : ghidraClassNameParts)
                {
                    curNs = this.getNamespace(curNs, nsPart);
                }

                Symbol sym;
                if ((sym = this.getSymbol(finalPart, curNs)) == null)
                {
                    printf("Cannot find namespace or function %s, skipping.\n", ghidraClassName);
                    continue;
                }
                if (!(sym.getObject() instanceof Namespace))
                {
                    printf("Namespace %s is not a namespace or a function, skipping.\n", ghidraClassName);
                    continue;
                }

                Namespace ns = (Namespace)sym.getObject();
                set = set.union(ns.getBody());

                for (Symbol symbolAdd : currentProgram.getSymbolTable().getSymbols(ns)) {
                    Function funAt = this.getFunctionAt(symbolAdd.getAddress());
                    if (funAt != null) {
                        set = set.union(funAt.getBody());
                    }
                }
            }

            if (set.isEmpty())
            {
                printf("No namespaces found for %s.obj, skipping.\n", objClass);
                continue;
            }
            
            boolean success = exporter.export(outFile, currentProgram, set, monitor);
            if (!success) {
                printf("Failed exporting %s.obj to %s file.\n", objClass, outFile);
                printf("Export log: %s.\n", exporter.getMessageLog().toString());
            }
        }
    }
}