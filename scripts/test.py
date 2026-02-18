from project import Function, FunctionType
from pathlib import Path

workspacePath = Path(__file__).parent.parent
mappingsFile = workspacePath / "config" / "me2" / "mapping.csv"
with open(str(mappingsFile), "r") as f:
    csvLines = f.read().splitlines()
    for csvline in csvLines:
        print(csvline)
        func : Function = Function.create(csvline)
        print(func)