
import json
from pathlib import Path
import os.path
from project import Function, FunctionType

ME_CONFIG_PATH = "config\\me2\\"
ME_SRC_PATH = "src\\me2"


def generateSources(mapping_file:str, units_listing:str, source_dir: Path, include_dir: Path):
    funByNamespaces = {}
    with open(mapping_file) as mapping_f:
        for csvLine in mapping_f.read().splitlines():
            function = Function.create(csvLine)
            ns = function.namespace
            if ns in funByNamespaces:
                funByNamespaces[ns].append(function)
            else:
                funByNamespaces[ns] = [function]

    with open(units_listing) as units_f:
        for unitLine in units_f.read().splitlines():
            unitParts = unitLine.split(',')
            unitName = unitParts[0]
            unitNamespaces = unitParts[1:]
            generateUnitSources(funByNamespaces, unitName, unitNamespaces, source_dir, include_dir)

def generateUnitSources(funByNamespaces, unitName, unitNamespaces, source_dir, include_dir):
    header_file = include_dir / (unitName + ".h") 
    if not header_file.exists():
        with header_file.open("w") as file:
            generateUnitHeader(file, funByNamespaces, unitName, unitNamespaces)

    source_file = source_dir / (unitName + '.cpp')
    if not source_file.exists():
        with source_file.open("w") as file:
            generateUnitSource(file, funByNamespaces, unitName, unitNamespaces)

def generateUnitHeader(headerFile, funByNamespaces, unitName, unitNamespaces):
    all_huge_class_name = make_all_huge_name(unitName)
    headerFile.write(f"#ifndef {all_huge_class_name}\n")
    headerFile.write(f"#define {all_huge_class_name}\n\n")
    headerFile.write("#include <globals.h>\n\n")
    for ns in unitNamespaces:
        generateUnitHeaderClass(headerFile, funByNamespaces, ns)
    headerFile.write("#endif")

def make_all_huge_name(name: str):
    result = ""
    for c in name:
        if c >= 'A' and c <= 'Z':
            result += '_'
        result += c
    return result.upper()  

def generateUnitHeaderClass(headerFile, funByNamespaces, ns):
    headerFile.write(f"class {ns} {{\n")
    if ns in funByNamespaces:
        nsFunctions = funByNamespaces[ns]
        headerFile.write("public:\n")
        for fun in nsFunctions:
            generateUnitHeaderFunction(headerFile, fun)
    headerFile.write("};\n\n")

def generateUnitHeaderFunction(headerFile, fun: Function):
    headerFile.write(f"\t/* {fun.start:X} */ ")
    if fun.type is FunctionType.STATIC:
        headerFile.write("static ")
    if fun.type is not FunctionType.CONSTRUCTOR:
        headerFile.write(f"{fun.returnType} ")
    headerFile.write(f"{fun.name}(")
    headerFile.write(", ".join(f"{arg} param_{param_idx+1}" for param_idx, arg in enumerate(fun.args)))
    if fun.hasVarArgs:
        if len(fun.args) > 0:
            headerFile.write(", ")
        headerFile.write("...")
    headerFile.write(");\n")

def generateUnitSource(source_file, funByNamespaces, unitName, unitNamespaces):
    source_file.write(f"#include \"{unitName}.h\"\n\n")
    for ns in unitNamespaces:
        if ns in funByNamespaces:
            for fun in funByNamespaces[ns]:
                generateUnitSourceFunction(source_file, fun)

def generateUnitSourceFunction(source_file, fun: Function):
    source_file.write(f"/* {fun.start:X}-{fun.end:X} {fun.size:05X}\t*/\n")
    if fun.type is not FunctionType.CONSTRUCTOR:
        source_file.write(f"{fun.returnType} ")
    source_file.write(f"{fun.namespace}::{fun.name}(")
    source_file.write(", ".join(f"{arg} param_{param_idx+1}" for param_idx, arg in enumerate(fun.args)))
    if fun.hasVarArgs:
        if len(fun.args) > 0:
            source_file.write(", ")
        source_file.write("...")
    source_file.write(") {\n")
    if fun.returnType != 'void' and fun.type is not FunctionType.CONSTRUCTOR:
        source_file.write("\treturn 0;\n")
    source_file.write("}\n\n")

if __name__ == "__main__":
    workspacePath = Path(__file__).parent.parent
    configPath = workspacePath / ME_CONFIG_PATH
    
    srcPath = workspacePath / ME_SRC_PATH
    generateSources(str(configPath / "mapping.csv"), str(configPath / "units_listing.csv"),
                     workspacePath/"src"/"me2", workspacePath/"include"/"me2")