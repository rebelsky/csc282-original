include ../resources/section.mk

MKSCHEDULE=../tools/mkschedule

schedule.html: overviews/*.xml
overviews/%.xml: ../outlines/overviews/%.md
	../tools/overview2xml $^ > $@

schedule.sect: $(MKSCHEDULE)
	$(MKSCHEDULE) mtwf-spring > $@

# Hacks for generating a decent PDF of the schedule
sched.sect: $(MKSCHEDULE)
	$(MKSCHEDULE) mtwf-spring-alt > $@
sched-munge.html: sched.html
	../tools/munge-schedule $< > $@
schedule.ps: sched-munge.html schedule.h2p
	html2ps -D -f schedule.h2p -o $@ $<

