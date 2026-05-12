from pathlib import Path

from generate_sources import generateSources
from generate_ninja import generateNinja
from generate_objdiff import generateObjdiffConfig
from export_ghidra_objs import exportObjs
from project import DecompUnit
import os


def configureProject(base_dir: Path):
    os.chdir(base_dir)
    engineUnit = DecompUnit("Engine", "me2", "ME2.dll")
    gameUnit = DecompUnit("Game code", "mkp", "gratka3d.exe")
    configure([engineUnit, gameUnit])

def configure(decompUnits: list[DecompUnit]):
    for unit in decompUnits:
        # exportObjs(unit)
        generateSources(unit)
        
    generateNinja(decompUnits, Path("."))
    generateObjdiffConfig(decompUnits, Path("./build/orig"), Path("./build/src"), Path("."))

if __name__ == "__main__":
    configureProject(Path(__file__).parent.parent)