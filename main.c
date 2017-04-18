#include <stdio.h>
#include <stdlib.h>
#include "mysynth.h"

#define SECONDS 2.0

void writeFloat(float v, FILE *f) {
  fwrite((void*)(&v), sizeof(v), 1, f);
}

int main() {
  FILE *binary_file = fopen("raw.bin","wb");

  u32 i;
  for (i=0; i<SECONDS*RATE; i++) {
    writeFloat( mysy_note(SAWT, 1.0, 55.0, 1.0), binary_file );
    mysy_nextSample();
  }

  fclose(binary_file);

  return 0;
}

