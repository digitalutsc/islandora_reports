
# coding: utf-8

# In[1]:


import pandas as pd
import datetime
import subprocess


# In[2]:


# Load the pid list
df = pd.read_csv("bags_report_csv.csv")


# In[3]:


# Loop through the pid list and create bag
creation_results = []
for index, row in df.iterrows():
    pid = row["PID"]

    # execute the command
    cmd = "drush --user=1 create-islandora-bag object " + pid
    cmd_output = subprocess.getoutput(cmd)
    print(cmd_output)
    
    # Check status of running the command
    creation_status = "Fail"
    if "Bag created and saved" in str(cmd_output): 
        creation_status = "Success"
        
    # Add to result set
    timestamp = datetime.datetime.utcnow()        
    creation_results.append((pid, creation_status, timestamp))
    print(pid + " " + creation_status)


# In[ ]:


df_creation_results = pd.DataFrame(creation_results, columns=('pid', 'creation_status', "created_on"))
df_creation_results.to_csv("bags_creation_report.csv")
df_creation_results

