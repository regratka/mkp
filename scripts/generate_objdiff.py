from pathlib import Path
import json
from helpers import has_functions
from project import DecompUnit

WORKSPACE_PATH = Path(__file__).parent.parent

def generateObjdiffConfig(decompUnits: list[DecompUnit], master_target_dir: Path, master_base_dir: Path, output_dir: Path):
    config = {}
    config["custom_make"] = "ninja"
    config["target_dir"] = str(master_target_dir)
    config["base_dir"] = str(master_base_dir)
    config["build_base"] = True
    config["build_target"] = False
    config["watch_patterns"] = ["*.c","*.cpp","*.h","*.hpp"]


    progress_categories = []
    for decompUnit in decompUnits:
        category_progress = {}
        category_progress["id"] = decompUnit.progress_category
        category_progress["name"] = decompUnit.progress_category
        progress_categories.append(category_progress)
    config["progress_categories"] = progress_categories

    conf_units = []
    for decompUnit in decompUnits:
        for unit, namespaces in decompUnit.units.items():
            if not has_functions(namespaces, decompUnit.mappings):
                continue
            conf_unit = {}
            conf_unit["name"] = decompUnit.directory_name+"/"+unit
            conf_unit["target_path"] = str(decompUnit.buildOrig / (unit + ".obj"))
            conf_unit["base_path"] = str(decompUnit.buildSrc / (unit + ".obj"))
            conf_unit["reverse_fn_order"] = False

            metadata = {}
            if unit in decompUnit.completed:
                metadata["complete"] = True
            metadata["progress_categories"] = [decompUnit.progress_category]
            conf_unit["metadata"] = metadata

            conf_units.append(conf_unit)

    config["units"] = conf_units
    
    with (output_dir/"objdiff.json").open("w") as file:
        json.dump(config, file, indent=4)

if __name__ == "__main__":
    generateObjdiffConfig(Path("build/me2/orig"), Path("build/me2/src"), ["cVideoPlayer"], WORKSPACE_PATH/"objdiff.json")
    
