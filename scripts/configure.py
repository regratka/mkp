from pathlib import Path

from generate_sources import generateSources
from generate_ninja import generateNinja
from generate_objdiff import generateObjdiffConfig
from export_ghidra_objs import exportObjs
from helpers import load_mappings, load_units
import os


def configureProject():
    me2configPath = Path("config") / "me2"
    me2buildPath = Path("build") / "me2"
    me2includePath = Path("include") / "me2"
    me2srcPath = Path("src") / "me2"
    me2importFile = Path("orig") / "ME2.dll"
    configure(me2configPath, me2buildPath, me2includePath, me2srcPath, me2importFile)

def configure(config_dir: Path, build_dir: Path, include_dir: Path, src_dir: Path, importFile: Path):
    
    units = load_units(str(config_dir/"units_listing.csv"))
    mappings = load_mappings(str(config_dir/"mapping.csv"))
    exportObjs(str(config_dir/"mapping.csv"), str(config_dir/"units_listing.csv"), str(build_dir/"orig"), str(importFile))
    generateSources(mappings, units, src_dir, include_dir)
    generateNinja(units, mappings, build_dir/"src", src_dir, include_dir, config_dir.parent.parent)
    generateObjdiffConfig(build_dir/"orig", build_dir/"src", units, mappings, config_dir.parent.parent)


if __name__ == "__main__":
    os.chdir(Path(__file__).parent.parent)
    configureProject()