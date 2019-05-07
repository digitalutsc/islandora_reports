$view = new view();
$view->name = 'bags_data';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'islandora_solr';
$view->human_name = 'bags_data';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'bags_data';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
/* Field: Islandora Solr: PID */
$handler->display->display_options['fields']['PID']['id'] = 'PID';
$handler->display->display_options['fields']['PID']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['PID']['field'] = 'PID';
/* Field: Islandora Solr: RELS_EXT_isMemberOfCollection_uri_ms */
$handler->display->display_options['fields']['RELS_EXT_isMemberOfCollection_uri_ms']['id'] = 'RELS_EXT_isMemberOfCollection_uri_ms';
$handler->display->display_options['fields']['RELS_EXT_isMemberOfCollection_uri_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['RELS_EXT_isMemberOfCollection_uri_ms']['field'] = 'RELS_EXT_isMemberOfCollection_uri_ms';
$handler->display->display_options['fields']['RELS_EXT_isMemberOfCollection_uri_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: RELS_EXT_hasModel_uri_ms */
$handler->display->display_options['fields']['RELS_EXT_hasModel_uri_ms']['id'] = 'RELS_EXT_hasModel_uri_ms';
$handler->display->display_options['fields']['RELS_EXT_hasModel_uri_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['RELS_EXT_hasModel_uri_ms']['field'] = 'RELS_EXT_hasModel_uri_ms';
$handler->display->display_options['fields']['RELS_EXT_hasModel_uri_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: RELS_EXT_isPageOf_uri_ms */
$handler->display->display_options['fields']['RELS_EXT_isPageOf_uri_ms']['id'] = 'RELS_EXT_isPageOf_uri_ms';
$handler->display->display_options['fields']['RELS_EXT_isPageOf_uri_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['RELS_EXT_isPageOf_uri_ms']['field'] = 'RELS_EXT_isPageOf_uri_ms';
$handler->display->display_options['fields']['RELS_EXT_isPageOf_uri_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: fgs_audit_justification_ms */
$handler->display->display_options['fields']['fgs_audit_justification_ms']['id'] = 'fgs_audit_justification_ms';
$handler->display->display_options['fields']['fgs_audit_justification_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['fgs_audit_justification_ms']['field'] = 'fgs_audit_justification_ms';
$handler->display->display_options['fields']['fgs_audit_justification_ms']['exclude'] = TRUE;
$handler->display->display_options['fields']['fgs_audit_justification_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: dc.title */
$handler->display->display_options['fields']['dc.title']['id'] = 'dc.title';
$handler->display->display_options['fields']['dc.title']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['dc.title']['field'] = 'dc.title';
/* Field: Islandora Solr: fgs_audit_date_ms */
$handler->display->display_options['fields']['fgs_audit_date_ms']['id'] = 'fgs_audit_date_ms';
$handler->display->display_options['fields']['fgs_audit_date_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['fgs_audit_date_ms']['field'] = 'fgs_audit_date_ms';
$handler->display->display_options['fields']['fgs_audit_date_ms']['exclude'] = TRUE;
$handler->display->display_options['fields']['fgs_audit_date_ms']['link_to_object'] = 0;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'LAST_NONPREMIS_AUDIT_DATE';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php
$justifications = $row->fgs_audit_justification_ms;
$dates = $row->fgs_audit_date_ms;
$last_non_premis_date = "not_set";

if (isset($dates)) {
    if (empty($justifications)) {
        $last_non_premis_date = end($dates);
    } else {
        $justifications = array_reverse($justifications);

        $last_non_premis_key = "";
        foreach ($justifications as $key => $currentElement) {
            if (strpos($currentElement, \'PREMIS\') === false) {
                $last_non_premis_key = $key;
                break;
            }
        }

        $dates = array_reverse($dates);
        $last_non_premis_date = $dates[$last_non_premis_key];
    }
}
print($last_non_premis_date);

?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Filter criterion: Islandora Solr: mods_physicalDescription_reformattingQuality_s */
$handler->display->display_options['filters']['mods_physicalDescription_reformattingQuality_s']['id'] = 'mods_physicalDescription_reformattingQuality_s';
$handler->display->display_options['filters']['mods_physicalDescription_reformattingQuality_s']['table'] = 'islandora_solr';
$handler->display->display_options['filters']['mods_physicalDescription_reformattingQuality_s']['field'] = 'mods_physicalDescription_reformattingQuality_s';
$handler->display->display_options['filters']['mods_physicalDescription_reformattingQuality_s']['value'] = 'preservation';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'bags_data';

/* Display: Data export */
$handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['style_plugin'] = 'views_data_export_csv';
$handler->display->display_options['path'] = 'bags_data_csv';
$translatables['bags_data'] = array(
  t('Master'),
  t('bags_data'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('PID'),
  t('RELS_EXT_isMemberOfCollection_uri_ms'),
  t('RELS_EXT_hasModel_uri_ms'),
  t('RELS_EXT_isPageOf_uri_ms'),
  t('fgs_audit_justification_ms'),
  t('dc.title'),
  t('fgs_audit_date_ms'),
  t('LAST_NONPREMIS_AUDIT_DATE'),
  t('Page'),
  t('Data export'),
);

