import sys
import pandas as pd
from matplotlib import pyplot as plt


df = pd.read_csv(sys.argv[1])
df.head()


dfs = [df[df['file'] == file] for file in df['file'].unique()]
dfs[0]


plt.grid()
for file_df in dfs:
    plt.plot(file_df['timeout'], file_df['energy_with_dpm'])

plt.savefig('build/plot.png')