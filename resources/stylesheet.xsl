<?xml version='1.0'?>
<!DOCTYPE stylesheet [
  <!ENTITY % CourseEntities SYSTEM "../resources/course.ent">
    %CourseEntities;
  <!ENTITY % GroupEntities SYSTEM "group.ent">
    %GroupEntities;
]>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                version='1.0'
                xmlns="http://www.w3.org/TR/xhtml1/transitional"
                exclude-result-prefixes="#default">

<xsl:import href="../resources/links.xsl"/>

<xsl:template name="body.attributes">
  <xsl:attribute name="style">background-image:url(../Images/logo.png);</xsl:attribute>
</xsl:template>

<xsl:template name="user.header.content">
<p class="course">
  &coursename; (&courseid; &semester;) : &group;
<br/>
</p>
<div class="head">
<xsl:call-template name="navlinks"/>
<p><a name="body"></a></p>
</div>
</xsl:template>

<xsl:template name="user.footer.content">

<div class="foot">

<div class="NOPRINT">

<xsl:call-template name="navlinks"/>

</div><!--noprint-->

<div class="pagenotes">

<p>
Copyright (c) 2013-14 Samuel A. Rebelsky.  
</p>

<p>
<!--Creative Commons License-->
<a rel="license" href="http://creativecommons.org/licenses/by/3.0/"><img alt="Creative Commons License" style="border-width:0" src="../resources/cc-by-3.0.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by/3.0/">Creative Commons Attribution 3.0 Unported License</a>.  To view a copy of this
license, visit <a href="http://creativecommons.org/licenses/by/3.0/"><code>http://creativecommons.org/licenses/by/3.0/</code></a> 
or send a letter to Creative Commons, 543 Howard Street, 5th Floor, 
San Francisco, California, 94105, USA.
<!--/Creative Commons License-->
</p>

<!-- <rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">
    <Work rdf:about="">
        <license rdf:resource="http://creativecommons.org/licenses/by/3.0/" />
    <dc:type rdf:resource="http://purl.org/dc/dcmitype/Text" />
    </Work>
    <License rdf:about="http://creativecommons.org/licenses/by/3.0/"><permits rdf:resource="http://web.resource.org/cc/Reproduction"/><permits rdf:resource="http://web.resource.org/cc/Distribution"/><requires rdf:resource="http://web.resource.org/cc/Notice"/><requires rdf:resource="http://web.resource.org/cc/Attribution"/><prohibits rdf:resource="http://web.resource.org/cc/CommercialUse"/><permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/></License></rdf:RDF> -->

</div><!--/pagenotes-->

</div><!--/foot-->

</xsl:template>

</xsl:stylesheet>
