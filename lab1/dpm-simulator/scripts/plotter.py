#!/usr/bin/env python
# coding: utf-8

# In[33]:


import sys
import pandas as pd
from matplotlib import pyplot as plt


# In[ ]:


IN_FILE = '../build/w1_timeout.log'
OUT_FILE = '../build/w1_timeout.png'


# In[34]:

if __name__ == '__main__':
    IN_FILE = sys.argv[1]
    OUT_FILE = sys.argv[2]


# In[35]:


df = pd.read_csv(IN_FILE)
df['energy_save_percent'] = (df['energy_without_dpm'] - df['energy_with_dpm'])/df['energy_without_dpm']
df.head()


# In[41]:


plt.grid()
plt.xlabel('Timeout (s)')
plt.ylabel('Energy Save (%)')
plt.plot(df['timeout'], df['energy_save_percent'])

plt.savefig(OUT_FILE)

