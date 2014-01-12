<?xml version='1.0'?>
<!DOCTYPE stylesheet [
  <!ENTITY % GroupEntities SYSTEM "group.ent">
  %GroupEntities;
  <!ENTITY % CourseEntities SYSTEM "../resources/course.ent">
  %CourseEntities;
  <!ENTITY % ProfEntities SYSTEM "../resources/prof.ent">
  %ProfEntities;
  <!ENTITY % CustomEntities SYSTEM "../resources/custom.ent">
  %CustomEntities;
  <!ENTITY % CommonEntities SYSTEM "../resources/common.ent">
  %CommonEntities;
  <!ENTITY % SubjectEntities SYSTEM "../resources/subjects.ent">
  %SubjectEntities;
  <!ENTITY % DueEntities SYSTEM "../resources/due.ent">
  %DueEntities;
  <!ENTITY % CalendarEntities SYSTEM "../resources/calendar.ent">
  %CalendarEntities;
  <!ENTITY % DateEntities SYSTEM "../resources/dates.ent">
  %DateEntities;
]>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                version='1.0'
                xmlns="http://www.w3.org/TR/xhtml1/transitional"
                exclude-result-prefixes="#default">

<xsl:import href="/home/rebelsky/share/docbook-xsl/html/docbook.xsl"/>
<xsl:import href="stylesheet.xsl"/>

<!-- Kludge to override text of <HEAD><TITLE> element. -->
<xsl:template match="*" mode="object.title.markup.textonly">
  <xsl:variable name="title">
    <xsl:apply-templates select="." mode="object.title.markup"/>
  </xsl:variable>
  &title-prefix;  
  <xsl:value-of select="normalize-space($title)"/>
  (&group;, &courseid; &semester;)
</xsl:template>

<!-- SECTIONS -->

<xsl:template name="section.title">
  <xsl:variable name="level" select="count(ancestor-or-self::section)"/>
  <xsl:variable name="hlevel">
    <xsl:choose>
      <xsl:when test="$level &gt; 5">6</xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="$level"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:variable>
  <xsl:element name="h{$hlevel}">
    <xsl:apply-templates/>
  </xsl:element>
</xsl:template>

<!--  SPECIAL TAGS -->

<!-- Scheme input -->
<xsl:template match="schemeinput">
  <code class="schemeinput"><xsl:apply-templates/></code>
</xsl:template>

<!-- Scheme output -->
<xsl:template match="schemeoutput">
  <code class="schemeoutput"><xsl:apply-templates/></code>
</xsl:template>

<!-- Scheme Comments -->
<xsl:template match="schemecomment">
  <code class="schemecomment"><xsl:apply-templates/></code>
</xsl:template>

<!-- Strikethrough text -->
<xsl:template match="strike">
  <strike><xsl:apply-templates/></strike>
</xsl:template>

<!-- Noprint text, for use with html2ps -->
<xsl:template match="noprint">
  <div class="noprint"><xsl:apply-templates/></div>
</xsl:template>

<!-- Hard breaks (a hack; requires appropriate CSS) -->
<xsl:template match="break">
  <span class="break"><xsl:apply-templates/></span>
</xsl:template>

<!-- Overviews in the schedule -->
<xsl:template match="overview">
  <span class="overview"><xsl:apply-templates/></span>
</xsl:template>

</xsl:stylesheet>
