#include <stdio.h>
//#include <math.h>
#include "mysynth.h"

//TODO ADSR, filters, LFO?

s16 scale(u16 v, u16 src_Max, u16 trg_min, u16 trg_Max) {
  v *= trg_Max - trg_min;
  v /= src_Max;
  v += trg_min;
  return v;
}

s16 sine_generator(s16 freq) {
  s16 T = (s16)mysy_sample / RATE * 2 * PI * freq;
  return sin(T);
}

s16 sawt_generator(s16 freq) {
  s16 a = scale(mysy_sample, RATE, -1000, 1000);
  return a;
}

s16 tria_generator(s16 freq) {
  // FIXME
  s16 a = (s16)mysy_sample / RATE * 2 * PI * freq;
  return a;
}

s16 sqre_generator(s16 freq) {
  s16 a = (sawt_generator(freq) > 0.0) ? 1.0 : -1.0;
  return a;
}

s16 mirr_generator(s16 freq) {
  // FIXME
  s16 T = (s16)mysy_sample / RATE * 2 * PI * freq;
  return sin(T);
}

s16 peak_generator(s16 freq) {
  s16 T = (s16)mysy_sample / RATE * 2 * PI * freq;
  s16 r = sin(T);
  if (r >  LIMIT) r =  2.0 * LIMIT - r;
  if (r < -LIMIT) r = -2.0 * LIMIT - r;
  return r;
}

s16 nois_generator(s16 freq) {
  // FIXME do gen
  return 0.0;
}

s16 mysy_note(u8 wave, u8 leng, s16 freq, s16 amp) {
  generatorDef generatorPtr;
  switch (wave) {
    case (SINE): generatorPtr = &sine_generator; break;
    case (SAWT): generatorPtr = &sawt_generator; break;
    case (TRIA): generatorPtr = &tria_generator; break;
    case (SQRE): generatorPtr = &sqre_generator; break;
    case (PEAK): generatorPtr = &peak_generator; break;
    case (MIRR): generatorPtr = &mirr_generator; break;
    case (NOIS): generatorPtr = &nois_generator; break;
    default: {
      fprintf(stderr, "Error: Unsupported waveform: %d\n", wave);
      generatorPtr = &sine_generator;
    }
  }
  return (*generatorPtr)(freq) * amp;
}

void mysy_nextSample() {
  mysy_sample++;
}
