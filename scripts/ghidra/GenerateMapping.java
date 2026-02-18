// Generate mapping.toml
//@category TH06

import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.Pointer;
import ghidra.program.model.data.TypeDef;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Parameter;
import java.io.File;
import java.nio.file.Files;

public class GenerateMapping extends GhidraScript
{

    private String transformType(DataType ty)
    {
        // MOD
        if (ty == null) {
           return "void";
        }
        
        switch (ty.toString())
        {
        case "bool":
        case "char":
        case "uchar":
        case "short":
        case "ushort":
        case "int":
        case "uint":
        case "long":
        case "ulong":
        case "float":
        case "double":
            return ty.toString();

        case "i8":
            return "char";
        case "undefined":
        case "undefined1":
        case "byte":
        case "u8":
            return "uchar";

        case "i16":
            return "short";
        case "undefined2":
        case "u16":
            return "ushort";

        case "i32":
            return "int";
        case "undefined4":
        case "u32":
            return "uint";
            
        case "f32":
            return "float";
        case "f64":
            return "double";
        }
        if (ty instanceof Pointer)
        {
            Pointer ptr = (Pointer)ty;
            DataType pointee = ptr.getDataType();
            return transformType(pointee) + "*";
        }
        if (ty instanceof TypeDef)
        {
            TypeDef typedef = (TypeDef)ty;
            return transformType(typedef.getBaseDataType());
        }
        return ty.getName();
    }

    public String generateCsv()
    {
        StringBuilder builder = new StringBuilder();

        FunctionIterator funcIter = currentProgram.getListing().getFunctions(true);
        while (funcIter.hasNext())
        {
            Function func = funcIter.next();

            if (func.isThunk())
            {
                continue;
            }

            builder.append(func.getName(true));
            builder.append(";0x");
            builder.append(Long.toHexString(func.getEntryPoint().getOffset()));
            builder.append(";0x");
            builder.append(Long.toHexString(func.getBody().getNumAddresses()));
            builder.append(";");
            builder.append(func.getCallingConventionName());
            builder.append(";");
            builder.append(func.hasVarArgs() ? "varargs" : "");
            builder.append(";");
            builder.append(transformType(func.getReturnType()));
            for (Parameter p : func.getParameters())
            {
                builder.append(";");
                builder.append(transformType(p.getDataType()));
            }
            builder.append("\n");
        }

        return builder.toString();
    }

    // TODO: handle duplicated
    public String generateToml()
    {
        StringBuilder builder = new StringBuilder();

        FunctionIterator funcIter = currentProgram.getListing().getFunctions(true);
        while (funcIter.hasNext())
        {
            Function func = funcIter.next();

            if (func.isThunk())
            {
                continue;
            }

            builder.append("[[function]]\n");

            builder.append("name = \"");
            builder.append(func.getName(true));
            builder.append("\"\n");

            builder.append("address = 0x");
            builder.append(Long.toHexString(func.getEntryPoint().getOffset()));
            builder.append("\n");

            builder.append("size = 0x");
            builder.append(Long.toHexString(func.getBody().getNumAddresses()));
            builder.append("\n");
            builder.append("\n");
        }

        return builder.toString();
    }

    @Override public void run() throws Exception
    {
        String mappingData = generateCsv();
        File outputMapping = askFile("mapping.csv", "Save");
        Files.write(outputMapping.toPath(), mappingData.getBytes());
    }
}
