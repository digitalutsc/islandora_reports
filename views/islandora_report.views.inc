$view = new view();
$view->name = 'repository_report';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'islandora_solr';
$view->human_name = 'repository_report';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'islandora_report';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'PID' => 'PID',
  'RELS_EXT_isMemberOfCollection_uri_ms' => 'RELS_EXT_isMemberOfCollection_uri_ms',
  'RELS_EXT_hasModel_uri_ms' => 'RELS_EXT_hasModel_uri_ms',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'PID' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'RELS_EXT_isMemberOfCollection_uri_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'RELS_EXT_hasModel_uri_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: Islandora Solr: PID */
$handler->display->display_options['fields']['PID']['id'] = 'PID';
$handler->display->display_options['fields']['PID']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['PID']['field'] = 'PID';
$handler->display->display_options['fields']['PID']['link_to_object'] = 0;
/* Field: Islandora Solr: RELS_EXT_isMemberOfCollection_uri_ms */
$handler->display->display_options['fields']['RELS_EXT_isMemberOfCollection_uri_ms']['id'] = 'RELS_EXT_isMemberOfCollection_uri_ms';
$handler->display->display_options['fields']['RELS_EXT_isMemberOfCollection_uri_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['RELS_EXT_isMemberOfCollection_uri_ms']['field'] = 'RELS_EXT_isMemberOfCollection_uri_ms';
$handler->display->display_options['fields']['RELS_EXT_isMemberOfCollection_uri_ms']['label'] = 'isMemberOfCollection';
$handler->display->display_options['fields']['RELS_EXT_isMemberOfCollection_uri_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: RELS_EXT_isPageOf_uri_ms */
$handler->display->display_options['fields']['RELS_EXT_isPageOf_uri_ms']['id'] = 'RELS_EXT_isPageOf_uri_ms';
$handler->display->display_options['fields']['RELS_EXT_isPageOf_uri_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['RELS_EXT_isPageOf_uri_ms']['field'] = 'RELS_EXT_isPageOf_uri_ms';
$handler->display->display_options['fields']['RELS_EXT_isPageOf_uri_ms']['label'] = 'isPageOf';
$handler->display->display_options['fields']['RELS_EXT_isPageOf_uri_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: RELS_EXT_hasModel_uri_ms */
$handler->display->display_options['fields']['RELS_EXT_hasModel_uri_ms']['id'] = 'RELS_EXT_hasModel_uri_ms';
$handler->display->display_options['fields']['RELS_EXT_hasModel_uri_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['RELS_EXT_hasModel_uri_ms']['field'] = 'RELS_EXT_hasModel_uri_ms';
$handler->display->display_options['fields']['RELS_EXT_hasModel_uri_ms']['label'] = 'cmodel';
$handler->display->display_options['fields']['RELS_EXT_hasModel_uri_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: fedora_datastreams_ms */
$handler->display->display_options['fields']['fedora_datastreams_ms']['id'] = 'fedora_datastreams_ms';
$handler->display->display_options['fields']['fedora_datastreams_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['fedora_datastreams_ms']['field'] = 'fedora_datastreams_ms';
$handler->display->display_options['fields']['fedora_datastreams_ms']['label'] = 'datastream_list';
$handler->display->display_options['fields']['fedora_datastreams_ms']['link_to_object'] = 0;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php_4']['id'] = 'php_4';
$handler->display->display_options['fields']['php_4']['table'] = 'views';
$handler->display->display_options['fields']['php_4']['field'] = 'php';
$handler->display->display_options['fields']['php_4']['label'] = 'datastreams_count';
$handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php_4']['php_output'] = '<?php
print(sizeof($row->fedora_datastreams_ms));
?>';
$handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
/* Field: Global: Regular Expression Re-Write */
$handler->display->display_options['fields']['regex_rewrite']['id'] = 'regex_rewrite';
$handler->display->display_options['fields']['regex_rewrite']['table'] = 'views';
$handler->display->display_options['fields']['regex_rewrite']['field'] = 'regex_rewrite';
$handler->display->display_options['fields']['regex_rewrite']['label'] = 'OBJ_Exists';
$handler->display->display_options['fields']['regex_rewrite']['alter']['text'] = '[fedora_datastreams_ms] ';
$handler->display->display_options['fields']['regex_rewrite']['alter']['text_patterns'] = '/^.*OBJ.*/
/^((?!OBJ).)*$/';
$handler->display->display_options['fields']['regex_rewrite']['alter']['text_replacements'] = 'OBJ
NO';
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'obj_checksum';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php

$datastreams = $row->fedora_datastreams_ms;
$obj_index = array_search("OBJ", $datastreams);

$checksums = $row->fedora_datastreams_last_checksum_ms;
$checksum_value = $checksums[$obj_index];

print($checksum_value);
?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Islandora Solr: fedora_datastreams_last_checksum_ms */
$handler->display->display_options['fields']['fedora_datastreams_last_checksum_ms']['id'] = 'fedora_datastreams_last_checksum_ms';
$handler->display->display_options['fields']['fedora_datastreams_last_checksum_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['fedora_datastreams_last_checksum_ms']['field'] = 'fedora_datastreams_last_checksum_ms';
$handler->display->display_options['fields']['fedora_datastreams_last_checksum_ms']['label'] = 'checksum_list';
$handler->display->display_options['fields']['fedora_datastreams_last_checksum_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: fgs_audit_justification_ms */
$handler->display->display_options['fields']['fgs_audit_justification_ms']['id'] = 'fgs_audit_justification_ms';
$handler->display->display_options['fields']['fgs_audit_justification_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['fgs_audit_justification_ms']['field'] = 'fgs_audit_justification_ms';
$handler->display->display_options['fields']['fgs_audit_justification_ms']['exclude'] = TRUE;
$handler->display->display_options['fields']['fgs_audit_justification_ms']['link_to_object'] = 0;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php_2']['id'] = 'php_2';
$handler->display->display_options['fields']['php_2']['table'] = 'views';
$handler->display->display_options['fields']['php_2']['field'] = 'php';
$handler->display->display_options['fields']['php_2']['label'] = 'Premis_Check';
$handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php_2']['php_output'] = '<?php

$justifications = $row->fgs_audit_justification_ms;
$justifications = array_reverse($justifications);

$last_check = "";
foreach ($justifications as $currentElement) {
  if (strpos($currentElement, \'fixity check\') !== false) {
    $last_check = $currentElement;
    break;
  }
}

$checksum_status = "Not Validated";
if (strpos($last_check, \'checksum validated\') !== false) {
  $checksum_status = "Validated";
}
print($checksum_status);
?>';
$handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
/* Field: Islandora Solr: fgs_audit_responsibility_ms */
$handler->display->display_options['fields']['fgs_audit_responsibility_ms']['id'] = 'fgs_audit_responsibility_ms';
$handler->display->display_options['fields']['fgs_audit_responsibility_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['fgs_audit_responsibility_ms']['field'] = 'fgs_audit_responsibility_ms';
$handler->display->display_options['fields']['fgs_audit_responsibility_ms']['exclude'] = TRUE;
$handler->display->display_options['fields']['fgs_audit_responsibility_ms']['link_to_object'] = 0;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php_3']['id'] = 'php_3';
$handler->display->display_options['fields']['php_3']['table'] = 'views';
$handler->display->display_options['fields']['php_3']['field'] = 'php';
$handler->display->display_options['fields']['php_3']['label'] = 'Last_Modified_By';
$handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php_3']['php_output'] = '<?php
print(end($row->fgs_audit_responsibility_ms));
?>';
$handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
/* Field: Islandora Solr: fits_identification_format_ms */
$handler->display->display_options['fields']['fits_identification_format_ms']['id'] = 'fits_identification_format_ms';
$handler->display->display_options['fields']['fits_identification_format_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['fits_identification_format_ms']['field'] = 'fits_identification_format_ms';
$handler->display->display_options['fields']['fits_identification_format_ms']['label'] = 'obj_format';
$handler->display->display_options['fields']['fits_identification_format_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: fedora_datastreams_mimetypes_ms */
$handler->display->display_options['fields']['fedora_datastreams_mimetypes_ms']['id'] = 'fedora_datastreams_mimetypes_ms';
$handler->display->display_options['fields']['fedora_datastreams_mimetypes_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['fedora_datastreams_mimetypes_ms']['field'] = 'fedora_datastreams_mimetypes_ms';
$handler->display->display_options['fields']['fedora_datastreams_mimetypes_ms']['label'] = 'mimetypes_list';
$handler->display->display_options['fields']['fedora_datastreams_mimetypes_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: dc.title */
$handler->display->display_options['fields']['dc.title']['id'] = 'dc.title';
$handler->display->display_options['fields']['dc.title']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['dc.title']['field'] = 'dc.title';
$handler->display->display_options['fields']['dc.title']['label'] = 'title';
$handler->display->display_options['fields']['dc.title']['link_to_object'] = 0;
/* Field: Islandora Solr: fedora_datastreams_size_ms */
$handler->display->display_options['fields']['fedora_datastreams_size_ms']['id'] = 'fedora_datastreams_size_ms';
$handler->display->display_options['fields']['fedora_datastreams_size_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['fedora_datastreams_size_ms']['field'] = 'fedora_datastreams_size_ms';
$handler->display->display_options['fields']['fedora_datastreams_size_ms']['label'] = 'size_list';
$handler->display->display_options['fields']['fedora_datastreams_size_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: fgs_lastModifiedDate_dt */
$handler->display->display_options['fields']['fgs_lastModifiedDate_dt']['id'] = 'fgs_lastModifiedDate_dt';
$handler->display->display_options['fields']['fgs_lastModifiedDate_dt']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['fgs_lastModifiedDate_dt']['field'] = 'fgs_lastModifiedDate_dt';
$handler->display->display_options['fields']['fgs_lastModifiedDate_dt']['link_to_object'] = 0;
$handler->display->display_options['fields']['fgs_lastModifiedDate_dt']['date_format'] = 'long';
/* Sort criterion: Islandora Solr: fgs_lastModifiedDate_dt */
$handler->display->display_options['sorts']['fgs_lastModifiedDate_dt']['id'] = 'fgs_lastModifiedDate_dt';
$handler->display->display_options['sorts']['fgs_lastModifiedDate_dt']['table'] = 'islandora_solr';
$handler->display->display_options['sorts']['fgs_lastModifiedDate_dt']['field'] = 'fgs_lastModifiedDate_dt';
$handler->display->display_options['sorts']['fgs_lastModifiedDate_dt']['order'] = 'DESC';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'islandora_report_page';

/* Display: Data export */
$handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_csv';
$handler->display->display_options['path'] = 'islandora_report_data';
$handler->display->display_options['sitename_title'] = 0;

