from pathlib import Path
import json

WORKSPACE_PATH = Path(__file__).parent.parent

def generateObjdiffConfig(target_dir: Path, base_dir: Path, units: list, output_dir: Path):
    config = {}
    config["custom_make"] = "ninja"
    config["target_dir"] = str(target_dir)
    config["base_dir"] = str(base_dir)
    config["build_base"] = True
    config["build_target"] = False
    config["watch_patterns"] = ["*.c","*.cpp","*.h","*.hpp"]
    conf_units = []

    for unit in units:
        conf_unit = {}
        conf_unit["name"] = unit
        conf_unit["target_path"] = str(target_dir / (unit + ".obj"))
        conf_unit["base_path"] = str(base_dir / (unit + ".obj"))
        conf_unit["reverse_fn_order"] = False
        conf_units.append(conf_unit)
    config["units"] = conf_units
    
    with (output_dir/"objdiff.json").open("w") as file:
        json.dump(config, file, indent=4)

if __name__ == "__main__":
    generateObjdiffConfig(Path("build/me2/orig"), Path("build/me2/src"), ["cVideoPlayer"], WORKSPACE_PATH/"objdiff.json")
    
