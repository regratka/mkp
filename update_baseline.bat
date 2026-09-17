@ECHO OFF

ECHO Updating baseline.json...
tools\objdiff-cli.exe report generate -o baseline.json -f json-pretty