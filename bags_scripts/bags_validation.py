
# coding: utf-8

# In[116]:


##################################################
## Script to validate bags in a folder.
## Uses https://github.com/LibraryOfCongress/bagit-python for validation.
##################################################
## GNU General Public License, version 2
## Author: UTSC DSU
##################################################


# In[1]:


# -*- coding: utf-8 -*-
import os, glob, sys
import bagit
import zipfile
import tempfile
import datetime
import pandas as pd
import configparser


# In[4]:


## Specify the folder to the bags here
config = configparser.ConfigParser()
config.read('bags_config.ini')
reports_folder = config['BAG_SCRIPTS']['reports_folder']
path_to_bags_dir = config['BAG_SCRIPTS']['path_to_bags_dir']
bags_validation_report = config['BAG_SCRIPTS']['bags_validation_report']


# In[119]:


## This method extracts the zip bagit file and uses the python bagit module to validate it
## Returns True if valid, False otherwise
def validate_bag(path_to_bag):
    with tempfile.TemporaryDirectory() as tmp_dir_path:
        zip_ref = zipfile.ZipFile(path_to_bag, 'r')
        zip_ref.extractall(tmp_dir_path)

        bag_basename = os.path.basename(path_to_bag)
        bag_foldername = os.path.splitext(bag_basename)[0]
        bag_extracted_path = tmp_dir_path + "/" + bag_foldername 
        bag = bagit.Bag(bag_extracted_path)
    
        if bag.is_valid():
            return True
        else:
            return False


# In[120]:


# Loops through all bags in the path_to_bags_dir dir and validates it.
# It assumes all zip files are bags.

list_of_bags = glob.glob(path_to_bags_dir + "/*.zip", recursive=True) 
validate_results = []
    
for path_to_bag in list_of_bags:
    bag_basename = os.path.basename(path_to_bag)
    print("Processing " + bag_basename)
    validation_status = False
    try:
      validation_status = validate_bag(path_to_bag)
    except:
      print("Unexpected error:", sys.exc_info()[0])
    
    print("Validation Status for " + bag_basename + " : " + str(validation_status))
    timestamp = datetime.datetime.utcnow()
    validate_results.append((bag_basename, validation_status, timestamp))


# In[121]:


# Converts the results into a dataframe and saves to a csv
df_validation_results = pd.DataFrame(validate_results, columns=('bag_name', 'validation_status', "validated_on"))
df_validation_results.to_csv(reports_folder + bags_validation_report)
df_validation_results


# In[123]:


is_valid =  df_validation_results['validation_status'] == False
valid_bags = df_validation_results[is_valid]
valid_bags

