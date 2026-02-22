from pathlib import Path
def sort(unit_listing: Path):

    unit_lines = []
    with unit_listing.open("r") as f:
        unit_lines = f.readlines()

    unit_lines.sort()
    with open(str(unit_listing)+"temp", "w") as out:
        out.writelines(unit_lines)

if __name__ == '__main__':
    paths = Path(__file__).parent.parent / "config" / "me2" / "units_listing.csv"
    sort(paths)