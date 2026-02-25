from pathlib import Path
def merge(old: Path, new: Path, result: Path):

    mappings_old = []
    with old.open("r") as f:
        mappings_old = f.readlines()
    mappings_new = []
    with new.open("r") as f:
        mappings_new = f.readlines()


    with result.open("w") as f:
        for index in range(0,len(mappings_old)):
            old_map = mappings_old[index]
            demangled_name = mappings_new[index].split(";")[0]
            f.write(demangled_name+";"+ old_map)

if __name__ == '__main__':
    old = Path(__file__).parent.parent.parent / "config" / "me2" / "mapping copy.csv"
    new = Path(__file__).parent.parent.parent / "config" / "me2" / "mapping.csv"
    result = Path(__file__).parent.parent.parent / "config" / "me2" / "res.csv"
    merge(old, new, result)