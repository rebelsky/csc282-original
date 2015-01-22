#include "log.h"

int 
main (int argc, char *argv[])
{
  char *x;
  int i;
  DO(i = 2);
  MSG("Starting");
  IVAR(i);
  IVAR(i*2);
  DO(i = i + 7);
  IVAR(i);
  IVAR(i*2);
  DO(x = "hello");
  MSG("Successfully said hello.");
  DO(*x = 'g');
  MSG("Ending");
  return 0;
} // main(int, char **)
