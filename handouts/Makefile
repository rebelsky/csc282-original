include ../resources/section.mk

schedule.html: overviews/*.xml
overviews/%.xml: ../outlines/overviews/%.md
	../tools/overview2xml $^ > $@

