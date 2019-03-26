# islandora_reports
scripts to analyze islandora repository content

## How-To
* xslt needs to be setup to index necessary fields
* Islandora solr views are used to generate the necessary raw data needed for the reports.  It can be executed with the following command:
```
drush views-data-export "islandora_report" "views_data_export_1" repo_data.csv
```
* run the jupyter notebook to generate the reports


## Additional Notes
* If you want to include compound objects in the report, uncheck "Hide child objects in Solr results" in localhost:8000/admin/islandora/solution_pack_config/compound_object
* The solr fields will only show up in view if you have at least one object with that field.  Else, you may have to edit the view and reports to exclude those fields.  

