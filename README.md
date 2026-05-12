# Komputerowa Gratka 3D - Magiczna kula Papatki

The WIP decompilation of _Komputerowa Gratka 3D - Magiczna kula Papatki_.

This repository does NOT contain any game assets or assembly. An existing copy of the game is required in order to contribute.

The project goal is the reconstruction of the source code of [Magiczna Kula Papatki](https://polish-abandonware.fandom.com/pl/wiki/Magiczna_Kula_Papatki) by IRMA and game engine __Magnum Engine v2.0__ . Work is currently focused on recreating engine source code.

| __File__         | __Size__       | __SHA1 hash__                                |
|--------------|------------|------------------------------------------|
| gratka3d.exe | 745,472B   | db170e2452a8c24860899b8bfc53ef07b1d2a7c9 |
| ME2.dll      | 1,650,688B | a5b52f7b504bfdbd32010e907344120490933425 |

Copy `gratka3d.exe` and `ME2.dll` to `orig/` 

__Configure project__

```shell
python scripts\configure.py
```

__Generate decompilation progress report__
```shell
tools\objdiff-cli.exe report generate -o report.json -f json-pretty
```

__Check changes in decompilation__
```shell
tools\objdiff-cli.exe report generate -o baseline.json -f json-pretty

tools\objdiff-cli.exe report changes baseline.json report.json -f json-pretty -o changes.json
```

Recognised toolkits:
* msvc 6.6
* directX 8.1
* directShow samples
* cg toolkit < 1.5