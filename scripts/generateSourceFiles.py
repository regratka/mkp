
import json
from pathlib import Path
import os.path

ME_CONFIG_PATH = "config\\me2\\symbols.json"
ME_SRC_PATH = "src\\me2"


def load_config(config_file_path: Path):
    with open(str(config_file_path)) as config_f:
        return json.load(config_f)

def make_all_huge_name(name: str):
    result = ""
    for c in name:
        if c >= 'A' and c <= 'Z':
            result += '_'
        result += c
    return result.upper()
    
def generate_header(header_path: Path, class_name: str):
    all_huge_class_name = make_all_huge_name(class_name)
    with header_path.open("w") as file:
        file.write(f"#ifndef {all_huge_class_name}\n")
        file.write(f"#define {all_huge_class_name}\n\n")
        file.write("#include <globals.h>\n\n")
        file.write(f"class {class_name} {{\n\n}};\n\n")
        file.write("#endif")
        return
    
def generate_source_file(source_file_path: Path, class_name: str):
    with source_file_path.open("w") as file:
        file.write(f"#include \"{class_name}.h\"") 
        return
    

def generates_class_files(class_config, main_src_path: Path):
    subpath_str = class_config["subpath"] if "subpath" in class_config else ""
    class_src_path = main_src_path / subpath_str

    if not class_src_path.exists():
        class_src_path.mkdir(parents=True, exist_ok=True)
    
    header_path = class_src_path / (class_config["name"] + ".h")
    if not header_path.exists():
        generate_header(header_path, class_config["name"])

    src_file_path = class_src_path / (class_config["name"] + ".cpp")
    if not src_file_path.exists():
       generate_source_file(src_file_path, class_config["name"])

def main(config_path: Path, src_path: Path):
    config = load_config(config_path)
    for class_conf in config:
        generates_class_files(class_conf, src_path)


if __name__ == "__main__":
    workspacePath = Path(__file__).parent.parent
    configPath = workspacePath / ME_CONFIG_PATH
    srcPath = workspacePath / ME_SRC_PATH
    main(configPath, srcPath)