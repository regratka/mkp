from pathlib import Path
import squarify
from matplotlib import pyplot as plt
from matplotlib import colormaps as cm
import json

cmap = cm['RdYlGn']

def print_progress(file: Path, sizes, labels, matches):
    fig, axs = plt.subplots(1,1, figsize=(40,40))
    plt.rcParams.update({'font.size': 10})
    squarify.plot(sizes=sizes, norm_x=1000, norm_y=1000, label=labels, color=cmap(matches), pad=True, ax=axs)
    plt.axis("off")
    plt.savefig(str(file))
    plt.close()

def visualize_overall(report, output_file: Path):
    units = report["units"]
    sizes_arr = []
    matches = []
    labels_arr = []
    for unit in units:
        meas = unit["measures"]
        matched = meas["fuzzy_match_percent"] if "fuzzy_match_percent" in meas else 0
        matches.append(matched/100)
        sizes_arr.append(int(unit["measures"]["total_code"]))
        labels_arr.append(f"{unit["name"]}\n{matched:.1f}%")
    
    print_progress(output_file, sizes_arr, labels_arr, matches)

def visualize_unit(unit, output_file: Path):
    functions = unit["functions"]
    sizes_arr = []
    matches = []
    labels_arr = []
    for function in functions:
        matched = function["fuzzy_match_percent"] if "fuzzy_match_percent" in function else 0
        matches.append(matched/100)
        sizes_arr.append(int(function["size"]))
        labels_arr.append(f"{function["name"]}\n{matched:.1f}%")
    
    print_progress(output_file, sizes_arr, labels_arr, matches)


def visualize(report_filepath: Path, output_folder: Path):
    with report_filepath.open("r") as report_file:
        report = json.load(report_file)
        visualize_overall(report, output_folder/"progress.png")

        for unit in report["units"]:
            visualize_unit(unit, output_folder/unit["name"])

if __name__ == "__main__":
    workspacePath = Path(__file__).parent.parent
    
    visualize(workspacePath / "report.json", workspacePath / "progress")