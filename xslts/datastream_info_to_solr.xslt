<?xml version="1.0" encoding="UTF-8"?>
<!-- Datastream information. -->
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:foxml="info:fedora/fedora-system:def/foxml#"
     exclude-result-prefixes="foxml">

  <xsl:template match="foxml:datastream" mode="index_object_datastreams">
    <field name="fedora_datastreams_ms">
      <xsl:value-of select="@ID"/>
    </field>
    <field name="fedora_datastreams_mimetypes_ms">
      <xsl:value-of select="foxml:datastreamVersion[last()]/@MIMETYPE"/>
    </field>
    <field name="fedora_datastreams_size_ms">
       <xsl:choose>
         <xsl:when test="foxml:datastreamVersion[last()]/@SIZE">
		<xsl:value-of select="foxml:datastreamVersion[last()]/@SIZE"/>
         </xsl:when>
         <xsl:otherwise>not_set</xsl:otherwise>
       </xsl:choose>
    </field>
    <field name="fedora_datastreams_last_checksum_ms">
       <xsl:choose>
         <xsl:when test="foxml:datastreamVersion[last()]/foxml:contentDigest">
        	<xsl:value-of select="foxml:datastreamVersion[last()]/foxml:contentDigest/@DIGEST"/>
         </xsl:when>
         <xsl:otherwise>not_set</xsl:otherwise>
       </xsl:choose>
    </field>
    <field name="fedora_datastreams_num_of_versions_ms">
	<xsl:value-of select="count(foxml:datastreamVersion)"/>
    </field>

    <xsl:call-template name="fedora_datastream_attribute_fields">
      <xsl:with-param name="id" select='@ID'/>
      <xsl:with-param name="prefix">fedora_datastream_info</xsl:with-param>
    </xsl:call-template>
    <xsl:apply-templates mode="index_object_datastreams"/>
    <xsl:call-template name="fedora_datastream_attribute_fields">
      <xsl:with-param name="element" select="foxml:datastreamVersion[last()]"/>
      <xsl:with-param name="prefix">fedora_datastream_latest</xsl:with-param>
    </xsl:call-template>
  </xsl:template>

  <xsl:template match="foxml:datastreamVersion" mode="index_object_datastreams">
    <xsl:call-template name="fedora_datastream_attribute_fields"/>
  </xsl:template>

  <xsl:template name="fedora_datastream_attribute_fields">
    <xsl:param name="element" select="."/>
    <xsl:param name="id" select="$element/../@ID"/>
    <xsl:param name="prefix">fedora_datastream_version</xsl:param>

    <xsl:for-each select="$element/@*">
      <field>
        <xsl:attribute name="name">
          <xsl:value-of select="$prefix"/>
          <xsl:text>_</xsl:text>
          <xsl:value-of select="$id"/>
          <xsl:text>_</xsl:text>
          <xsl:value-of select="local-name()"/>
          <xsl:text>_ms</xsl:text>
        </xsl:attribute>
        <xsl:value-of select="normalize-space(.)"/>
      </field>
    </xsl:for-each>

  </xsl:template>

</xsl:stylesheet>
