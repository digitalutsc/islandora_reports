<?php


/**
 * Script to add <reformattingQuality> element with default value preservation to
 * MODS XML documents within a directory.
 * Assumes the <physicalDescription> parent element is present.
 *
 * Below is an example of how this will look:
 *
 *  <physicalDescription>
 *    <form authority="marcform">nonprojected graphic</form>
 *    <extent></extent>
 *    <reformattingQuality>preservation</reformattingQuality>
 *    <extent/>
 *  </physicalDescription>
 *
 * This script is inspired by
 * https://github.com/MarcusBarnes/mik/blob/master/extras/scripts/add_uuid_identifier_2_mods.php
 *
 *
 * Example usage:
 *    php add_reformattingquality_element_to_mods.php /some/path/folder_with_modsxml_files/
 */

// The first argument is assumed to be the path to the directory containing the MODS XML files.
$dir = trim($argv[1]);

//print_r($dir);

$directory_iterator = new RecursiveIteratorIterator(new RecursiveDirectoryIterator($dir));
foreach ($directory_iterator as $filepath => $info) {
    if (preg_match('/MODS\.xml$/', $filepath)) {
        add_reformattingQuality_element($filepath);
      //print $filepath . PHP_EOL;
    }

  // Run the MODS XML validator script against the saved MODS XML.
}


/**
 * Adds a <reformattingQuality> element containing default preservation value to
 * the file identified in the $mods_xml_path.
 */
function add_reformattingQuality_element($mods_xml_path, $reformatingQuality_value = 'preservation')
{
    print "Processing $mods_xml_path." . PHP_EOL;
    $dom = new DomDocument;
    $dom->preserveWhiteSpace = false;
    $dom->formatOutput = true;
    $dom->load($mods_xml_path);

  // Check to see if we already have an reformattingQuality element.
  // If so, exit.
    $xpath = new \DOMXPath($dom);
    $existing_reformattingQuality_elements = $xpath->query('//mods:reformatingQuality');

    if ($existing_reformattingQuality_elements->length > 0) {
        print "$mods_xml_path already has one or more reformatingQuality elements." . PHP_EOL;
        return;
    }

  // Build the <reformatingQuality> element we are adding.
    $reformatingQuality_element = $dom->createElement('reformatingQuality', $reformatingQuality_value);

  // Find parent element.  Assuming that there is only one parent element.
    $physicalDescription_elements = $dom->getElementsByTagName('physicalDescription');
    if ($physicalDescription_elements->length ==0) {
	$mods_element = $dom->getElementsByTagName('mods');
        $new_physicalDescription_element = $dom->createElement('physicalDescription');
	$mods_element->item(0)->appendChild($new_physicalDescription_element);
    }

    $physicalDescription_elements->item(0)->appendChild($reformatingQuality_element);

    $mods_xml = $dom->saveXML();
  // Write the changes to the file.
    file_put_contents($mods_xml_path, $mods_xml);
}

