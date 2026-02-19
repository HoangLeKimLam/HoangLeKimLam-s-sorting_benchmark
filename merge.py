import pandas as pd

py = pd.read_csv("sorting_benchmark_results.csv")
cpp = pd.read_csv("cpp_sort_results.csv")

final = py.merge(cpp, on="Dataset")

final.to_csv("final_benchmark_results.csv", index=False)
