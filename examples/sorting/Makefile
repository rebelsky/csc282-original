CFLAGS = -g -Wall

expt0: expt0.o sort0.o
	$(LINK.o) -o $@ $^

expt1a: expt1a.o sort1.o
	$(LINK.o) -o $@ $^

expt1b: expt1b.o sort1.o
	$(LINK.o) -o $@ $^

hexpt1a: expt1a.o heapsort1.o
	$(LINK.o) -o $@ $^

expt0.o: sort0.h
sort0.o: sort0.h

expt1a.o: sort1.h
expt1b.o: sort1.h
sort1.o: sort1.h
heapsort1.o: sort1.h
