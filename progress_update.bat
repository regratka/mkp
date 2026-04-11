@ECHO OFF
ECHO Started Update

ECHO Updating report.json...
tools\objdiff-cli.exe report generate -o report.json -f json-pretty

ECHO Updating changes based on baseline.json...
tools\objdiff-cli.exe report changes baseline.json report.json -f json-pretty -o changes.json

ECHO Updating progress visualization...
python scripts\visualize_progress.py