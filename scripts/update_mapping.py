import argparse
import os
from pathlib import Path

import ghidra_helpers

SCRIPT_PATH = Path(os.path.realpath(__file__)).parent

def updateMapping(ghidra_directory: str, ghidra_project: str, ghidra_program: str, output_mapping_file:str):
    ghidra_helpers.runAnalyze(
        ghidra_directory,
        ghidra_project,
        process=ghidra_program,
        pre_scripts=[["GenerateMapping.java", output_mapping_file]],
    )


def main():
    parser = argparse.ArgumentParser(
        description="Export a ghidra database to csv file",
    )
    parser.add_argument("GHIDRA_REPO_NAME")
    parser.add_argument("--project", help="Project name", required=True)
    parser.add_argument("--program", help="Program to export", required=True)
    parser.add_argument("--output", help="Output csv file", required=True)
    args = parser.parse_args()

    updateMapping(args.GHIDRA_REPO_NAME, args.project, args.program, args.output)


if __name__ == "__main__":
    main()
