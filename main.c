#include <stdio.h>
#include <stdlib.h>
#include "mysynth.h"

#define SECONDS 2.0

void output(float x) {
  putchar (((unsigned char *) &x) [0]);
  putchar (((unsigned char *) &x) [1]);
  putchar (((unsigned char *) &x) [2]);
  putchar (((unsigned char *) &x) [3]);
}

int main() {
  unsigned int i;
  for (i=0; i<SECONDS*RATE; i++) {
    output( mysy_note(SQRE, 1.0, 55.0, 1.0) );
    mysy_nextSample();
    //printf("%f\n", generator(smp, 1.0, 1.0));
  }
}

