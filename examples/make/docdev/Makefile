default: file.htm

%.htm: %.md
	Markdown.pl $< > $@

%.html: %.htm template.html
	wrap-md-html $< template.html > $@

%.ps : %.html
        html2ps $
