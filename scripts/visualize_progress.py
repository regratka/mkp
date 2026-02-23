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
        cmap = cm['RdYlGn']
        for unit in units:
            meas = unit["measures"]
            matched = meas["fuzzy_match_percent"] if "fuzzy_match_percent" in meas else 0
            matches.append(matched/100)
            sizes_arr.append(int(unit["measures"]["total_code"]))
            labels_arr.append(f"{unit["name"]}\n{matched:.1f}%")
        
        fig, axs = plt.subplots(1,1, figsize=(40,40))
        plt.rcParams.update({'font.size': 10})
        squarify.plot(sizes=sizes_arr, norm_x=1000, norm_y=1000, label=labels_arr, color=cmap(matches), pad=True, ax=axs)
        plt.axis("off")
        plt.savefig(str(output_file))

if __name__ == "__main__":
    workspacePath = Path(__file__).parent.parent
    
    visualize(workspacePath / "report.json", workspacePath / "progress.png")