# regratka
Recompilation project of "Magiczna kula Papatki"


 ![Progress](progress.png)

Configure project

```shell
python scripts\configure.py
```

Generate decompilation progress report
```shell
tools\objdiff-cli.exe report generate -o report.json -f json-pretty
```

Update progress visualization

```shell
python scripts\visualize_progress.py
```