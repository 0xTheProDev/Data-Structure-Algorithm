#include <stdio.h>
#define get getchar_unlocked

/*
 * USAGE: scand(<ADDRESS OF INTEGER VARIABLE>)
 * RETURN TYPE: VOID
 * THIS METHOD READS CHARACTER FROM CONSOLE
 * CHECKS WHETHER IT BELONGS TO NUMBER OR NOT
 * IF IT IS A NUMBER KEEP ADDING UNTIL A NON-NUMERIC
 * CHARACTER IS FOUND. PUT THE INTEGER FORMED IN GIVEN
 * ADDRESS LOCATION.
*/
inline void scand(const void* a)
{
  register int q = 0, p = get();
  while((p < '0' || p > '9') && p ^ EOF) p = get();
  while(p >= '0' && p <= '9') q = (q << 3) + (q << 1) + p - '0', p = get();
  *(int*)a = q;
}

/* MAIN METHOD */
int main(void) 
{
  int N;
  scand(&N);
  printf("%d", N);
  return 0;
}
