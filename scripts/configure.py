from pathlib import Path

import argparse
from generate_sources import generateSources
from generate_ninja import generateNinja
from generate_objdiff import generateObjdiffConfig
from export_ghidra_objs import exportObjs
from project import DecompUnit
import os


def configureProject(base_dir: Path):
    parser = argparse.ArgumentParser(
        description="Configure decompilation project",
    )
    parser.add_argument("--skipexport", action='store_true')
    args = parser.parse_args()

    os.chdir(base_dir)
    engineUnit = DecompUnit("Engine", "me2", "ME2.dll", 
                            "/Zi /O2 /GR /G6 /GX /I include/ /I include/me2 /I tools/msvc66/include /I tools/Multimedia/Common/Include /I tools/Multimedia/DirectShow/BaseClasses /I tools/dx81/include /I tools/jni /I tools")
    gameUnit = DecompUnit("Game code", "mkp", "gratka3d.exe", 
                          "/Zi /O2 /GR /GX /I include/ /I include/me2 /I include/mkp /I tools/msvc66/include /I tools/Multimedia/Common/Include /I tools/Multimedia/DirectShow/BaseClasses /I tools/dx81/include /I tools/jni  /I tools")
    configure([engineUnit, gameUnit], args.skipexport)

def configure(decompUnits: list[DecompUnit], skipExport: bool):
    if not skipExport:
        for unit in decompUnits:
            exportObjs(unit)

    for unit in decompUnits:
        generateSources(unit)
        
    generateNinja(decompUnits, Path("."))
    generateObjdiffConfig(decompUnits, Path("./build/orig"), Path("./build/src"), Path("."))

if __name__ == "__main__":
    configureProject(Path(__file__).parent.parent)