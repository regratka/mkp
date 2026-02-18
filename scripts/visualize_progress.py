from pathlib import Path
import squarify
from matplotlib import pyplot as plt
from matplotlib import colormaps as cm
import json

def visualize(report_filepath: Path, output_file: Path):
    with report_filepath.open("r") as report_file:
        report = json.load(report_file)
        units = report["units"]
        sizes_arr = []
        matches = []
        labels_arr = []
        cmap = cm['brg']
        for unit in units:
            matched = unit["measures"]["matched_code_percent"]
            matches.append(matched/100)
            sizes_arr.append(int(unit["measures"]["total_code"]))
            labels_arr.append(f"{unit["name"]} {matched:.2f}%")
        squarify.plot(sizes=sizes_arr, label=labels_arr, color=cmap(matches))
        plt.axis("off")
        plt.savefig(str(output_file))

if __name__ == "__main__":
    workspacePath = Path(__file__).parent.parent
    
    visualize(workspacePath / "out.json", workspacePath / "progres.png")