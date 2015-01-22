.PHONY : clean
clean:
	-rm -f *.o

foo.o: foo.h foo.c
	echo "carat: $^"
	echo "lt: $<"
	echo "root: $*"

%.o: %.c
	echo "I'm about to make $@ from $<"
