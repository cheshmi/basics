import csv
import os
import re
import sys

import matplotlib
import matplotlib.pyplot as plt

name = re.compile(r"^BM_Sort(\w+)/(\d+)$")

def parse_csv(path):
    data = {}
    with open(path) as f:
        lines = f.readlines()

    for i, line in enumerate(lines):
        if line.startswith("name,"):
            start = i
            break

    for row in csv.DictReader(lines[start:]):
        m = name.match(row["name"])
        if not m:
            continue
        algo, n = m.group(1), int(m.group(2))
        data.setdefault(algo, {})[n] = float(row["real_time"])
    return data


def plot_insertion(data, out_path):
    plt.figure()
    runs = data["Insertion"]
    xs, ys = zip(*sorted(runs.items()))
    plt.plot(xs, ys, marker="o", label="Insertion")
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Input size N")
    plt.ylabel("Runtime (ms)")
    plt.title("Insertion sort runtime")
    plt.grid(True, which="both", linestyle="--", alpha=0.4)
    plt.savefig(out_path, dpi=150)
    plt.close()


def plot_runtime(data, out_path):
    plt.figure()
    for algo, runs in data.items():
        xs = sorted(runs.keys())
        ys = [runs[n] for n in xs]
        plt.plot(xs, ys, marker="o", label=algo)
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Input size N")
    plt.ylabel("Runtime (ms)")
    plt.title("LinkedList runtime")
    plt.legend()
    plt.grid(True, which="both", linestyle="--", alpha=0.4)
    plt.savefig(out_path, dpi=150)
    plt.close()


def main():
    csv_path, out_dir = sys.argv[1], sys.argv[2]
    os.makedirs(out_dir, exist_ok=True)
    data = parse_csv(csv_path)
    plot_runtime(data, os.path.join(out_dir, "runtime.png"))
    plot_insertion(data, os.path.join(out_dir, "insertion.png"))

main()