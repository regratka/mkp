from pathlib import Path
import squarify
from matplotlib import pyplot as plt
from matplotlib import colormaps as cm
import json

def visualize(report_path: Path):
    with report_path.open("r") as report_file:
        report = json.load(report_file)
        units = report["units"]
        sizes_arr = []
        matches = []
        labels_arr = []
        cmap = cm['brg']
        print(cmap(0.1))
        for unit in units:
            matched = unit["measures"]["matched_code_percent"]
            matches.append(matched/100)
            sizes_arr.append(int(unit["measures"]["total_code"]))
            labels_arr.append(f"{unit["name"]} {matched:.2f}%")
        print(cmap(2.0))
        print(cmap(matches))
        squarify.plot(sizes=sizes_arr, label=labels_arr, color=cmap(matches))
        plt.axis("off")
        plt.show()

if __name__ == "__main__":
    workspacePath = Path(__file__).parent.parent
    
    visualize(workspacePath / "out.json")