<?xml version="1.0" encoding="UTF-8"?>
<!-- Basic FITS -->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xlink="http://www.w3.org/1999/xlink" xmlns:foxml="info:fedora/fedora-system:def/foxml#" xmlns:fits="http://hul.harvard.edu/ois/xml/ns/fits/fits_output" xmlns:mix="http://www.loc.gov/standards/mix/mix20/mix20.xsd" xmlns:aes="http://www.aes.org/audioObject" xmlns:ebucore="urn:ebu:metadata-schema:ebuCore_2014" version="1.0">
  <xsl:template match="foxml:datastream[@ID='TECHMD']/foxml:datastreamVersion[last()]" name="index_fits">
    <xsl:param name="content"/>
    <xsl:param name="prefix"/>
    <xsl:param name="suffix">ms</xsl:param>

    <!-- Add identificaiton info to index. -->
    <xsl:for-each select="$content//fits:identification/fits:identity">
      <field name="fits_identification_format_ms">
        <xsl:value-of select="@format"/>
      </field>
      <field name="fits_identification_mimetype_ms">
        <xsl:value-of select="@mimetype"/>
      </field>
    </xsl:for-each>
  </xsl:template>

</xsl:stylesheet>

