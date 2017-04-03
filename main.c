#include <stdio.h>
#include <stdlib.h>
#include "mysynth.h"

void output(float x) {
  putchar (((unsigned char *) &x) [0]);
  putchar (((unsigned char *) &x) [1]);
  putchar (((unsigned char *) &x) [2]);
  putchar (((unsigned char *) &x) [3]);
}

int main() {
  for (sample=0; sample<SECONDS*RATE; sample++) {
    output( note(PEAK, 1.0, 55.0, 1.0) );
    //printf("%f\n", generator(smp, 1.0, 1.0));
  }
}

