#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# Builds a directed graph datastructure of islandora collections


# In[ ]:


import pandas as pd
import collections
import json


# In[ ]:


data_file = "data/report_data_may_2019.csv"
reports_dir = "report_prod_may_2019/"


# In[ ]:


# Build child parent tuple tree, recursively
def get_collection_members(df, collection_tree, collection):   
    children = []

    is_collection_member =  df['isMemberOfCollection'] == collection
    member_list = df[is_collection_member]
        
    ## Loop through each member, if it is a collection model, then call this again!
    for index, row in member_list.iterrows():
        pid = row["PID"]
        cmodel = row["cmodel"]
        child = {}
        if cmodel == "info:fedora/islandora:collectionCModel":
            child["name"] = pid
            child["parent"] = collection
            collection_tree = get_collection_members(df, collection_tree, "info:fedora/"+pid)
            collection_name = collection.replace("info:fedora/", "")
            tup2 = (collection_name, pid);
            collection_tree.append(tup2)
        
    return collection_tree


# In[ ]:


df = pd.read_csv(data_file) 


# In[ ]:


tree = lambda: collections.defaultdict(tree)
collection_tree = tree()
collection = "info:fedora/dsu:root"

path_list = ["root"]
collection_tree =[]
## Build child parent tuple tree, recursively
collection_tree = get_collection_members(df, collection_tree, collection)

print(collection_tree)


# In[ ]:


# Build a Directed Graph
# https://stackoverflow.com/questions/45460653/given-a-flat-list-of-parent-child-create-a-hierarchical-dictionary-tree

lst = collection_tree

# Build a directed graph and a list of all names that have no parent
graph = {name: set() for tup in lst for name in tup}
has_parent = {name: False for tup in lst for name in tup}
for parent, child in lst:
    graph[parent].add(child)
    has_parent[child] = True

# All names that have absolutely no parent:
roots = [name for name, parents in has_parent.items() if not parents]

# traversal of the graph (doesn't care about duplicates and cycles)
treeData = []
def traverse(hierarchy, graph, names):
    for name in names:
        hierarchy[name] = traverse({}, graph, graph[name])
    return hierarchy

aa = traverse({}, graph, roots)
json.dumps(aa)


# In[ ]:




