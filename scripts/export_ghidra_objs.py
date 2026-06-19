#!/usr/bin/env nix-shell
#!nix-shell -p python311 -i python3
import os
from pathlib import Path
import tempfile
from project import DecompUnit

import ghidra_helpers

SCRIPT_PATH = Path(os.path.realpath(__file__)).parent

def exportObjs(unit: DecompUnit):
    os.makedirs(str(unit.buildOrig), exist_ok=True)
    with tempfile.TemporaryDirectory() as tempdir:
        ghidra_helpers.runAnalyze(
            str(tempdir),
            "ProjectTempName",
            import_file=str(unit.filePath),
            analysis=True,
            post_scripts=[
                ["ImportFromCsv.java", str(unit.configPath/"mapping.csv")],
                [
                    "ExportDelinker.java", 
                    str(unit.configPath/"units_listing.csv"),
                    str(unit.configPath/"mapping.csv"),
                    str(unit.buildOrig),
                ],
            ],
        )

if __name__ == "__main__":
    mapping_csv = SCRIPT_PATH.parent / "config" / "me2" /"mapping.csv"
    export_directory = SCRIPT_PATH.parent / "build" / "orig" / "me2"
    import_file= SCRIPT_PATH.parent / "orig" / "ME2.dll"
    units_listing_file = SCRIPT_PATH.parent / "config" / "me2" / "units_listing.csv"
    exportObjs(str(mapping_csv), str(units_listing_file), str(export_directory), str(import_file))
