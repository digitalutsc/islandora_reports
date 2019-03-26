<?xml version="1.0" encoding="UTF-8"?>
<!-- FOXML properties -->
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:foxml="info:fedora/fedora-system:def/foxml#"
  xmlns:audit="info:fedora/fedora-system:def/audit#"

     exclude-result-prefixes="foxml">

  <!-- Create "date" fields for the dates... -->
  <xsl:template match="foxml:property[substring-after(@NAME, '#')='createdDate' or substring-after(@NAME, '#')='lastModifiedDate']">
    <xsl:param name="prefix">fgs_</xsl:param>

    <field>
      <xsl:attribute name="name">
        <xsl:value-of select="concat($prefix, substring-after(@NAME,'#'), '_dt')"/>
      </xsl:attribute>
      <xsl:value-of select="@VALUE"/>
    </field>
  </xsl:template>

  <!-- Index the fedora properties -->
  <xsl:template match="foxml:property">
    <xsl:param name="prefix">fgs_</xsl:param>
    <xsl:param name="suffix">_s</xsl:param>
    <field>
      <xsl:attribute name="name">
        <xsl:value-of select="concat($prefix, substring-after(@NAME,'#'), $suffix)"/>
      </xsl:attribute>
      <xsl:value-of select="@VALUE"/>
    </field>
  </xsl:template>


   <xsl:template match="foxml:xmlContent">
    <xsl:for-each select="audit:auditTrail/audit:record">
      <field name="fgs_audit_record_ms">
        <xsl:value-of select="@ID"/>
      </field>
      <field name="fgs_audit_action_ms">
        <xsl:value-of select="audit:action"/>
      </field>
      <field name="fgs_audit_componentID_ms">
        <xsl:value-of select="audit:componentID"/>
      </field>
      <field name="fgs_audit_responsibility_ms">
        <xsl:value-of select="audit:responsibility"/>
      </field>
      <field name="fgs_audit_date_ms">
        <xsl:value-of select="audit:date"/>
      </field>
      <field name="fgs_audit_justification_ms">
        <xsl:value-of select="audit:justification"/>
      </field>
    </xsl:for-each>
  </xsl:template>


</xsl:stylesheet>
