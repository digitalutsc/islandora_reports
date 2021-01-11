# islandora_reports
scripts to analyze islandora repository content

## How-To
* xslt needs to be setup to index necessary fields
* Islandora solr views are used to generate the necessary raw data needed for the reports.  It can be executed with the following command:
```
drush @dsu --user=1 views-data-export "islandora_report" "views_data_export_1" ~/repo_data.csv
```
* run the jupyter notebook to generate the reports


## Additional Notes
* If you want to include compound objects in the report, uncheck "Hide child objects in Solr results" in localhost:8000/admin/islandora/solution_pack_config/compound_object
* The solr fields will only show up in view if you have at least one object with that field.  Else, you may have to edit the view and reports to exclude those fields.  

## Report compilation:
* How to run: Run report_compilation file, all the cells one by one in order, change the data_file variable to the path you want
(if you want to make it take less time, comment out the orphan part). Report_compilation returns a docx file ReportSummary in
the same location as the file itself.
* report_functions contains all the helpers that mostly help process the data.
* document_helpers contains all the helpers related to displaying data as a word document and for getting AIP data
* tree_visualizer creates the tree structure and rotates it. As output it gives 2 pngs, treeTest and treeTestTranspose, which
are the tree for the collections and the rotated version of that same tree. These 2 pngs are in the same location as the file
itself
* bags_table works with the bags files and creates the table based on AIPs. If you want to change the path of the bags_validation_report.csv, change it in the
GetValidAIPForCollection function for the pd.read_csv section
