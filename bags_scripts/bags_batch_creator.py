
# coding: utf-8

# In[1]:


##################################################
## Script to creat bags in a batch using islandora_bagit.
##################################################
## GNU General Public License, version 2
## Author: UTSC DSU
##################################################


# In[13]:


import pandas as pd
import datetime
import subprocess
import configparser


# In[14]:


config = configparser.ConfigParser()
config.read('bags_config.ini')
reports_folder = config['BAG_SCRIPTS']['reports_folder']
pids_to_create_bags = config['BAG_SCRIPTS']['pids_to_create_bags']
bags_creation_report = config['BAG_SCRIPTS']['bags_creation_report']


# In[15]:


# Load the pid list
df = pd.read_csv(reports_folder + "/" + pids_to_create_bags)


# In[16]:


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


# In[17]:


df_creation_results = pd.DataFrame(creation_results, columns=('pid', 'creation_status', "created_on"))
df_creation_results.to_csv(reports_folder + "/" + bags_creation_report)
df_creation_results

