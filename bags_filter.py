
# coding: utf-8

# In[16]:


import pandas as pd
import datetime as date
import configparser


# In[17]:


config = configparser.ConfigParser()
config.read('bags_config.ini')
data_folder = config['BAG_SCRIPTS']['data_folder']
reports_folder = config['BAG_SCRIPTS']['reports_folder']
last_baged_date = config['BAG_SCRIPTS']['last_baged_date']
bags_data_csv = config['BAG_SCRIPTS']['bags_data_csv']
pids_to_create_bags = config['BAG_SCRIPTS']['pids_to_create_bags']


# In[18]:


# Load bags data
df = pd.read_csv(data_folder + "/" + bags_data_csv) 
# Convert str to date format
df['last_nonpremis_audit_date'] = pd.to_datetime(df.LAST_NONPREMIS_AUDIT_DATE,  format = '%Y-%m-%dT%H:%M:%S.%fZ')
del df['LAST_NONPREMIS_AUDIT_DATE']
df.head(10)


# In[19]:


# Filter by last bagged date
last_baged_datetime = date.datetime.strptime(last_baged_date, '%Y-%m-%dT%H:%M:%S.%fZ')
filter_by_date =  df['last_nonpremis_audit_date'] < last_baged_datetime
df = df[filter_by_date]
df.head(10)


# In[20]:


df.to_csv(reports_folder + "/" + pids_to_create_bags, index=False)

