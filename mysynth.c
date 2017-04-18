#include <stdio.h>
//#include <math.h>
#include "mysynth.h"

//TODO ADSR, filters, LFO?

float scale(float v, float min, float Max) {
  v *= Max - min;
  v += min;
  return v;
}

float sine_generator(float freq) {
  float T = mysy_sample / RATE * 2 * PI * freq;
  return sin(T);
}

float sawt_generator(float freq) {
  float ramp = mysy_sample * freq;
  while (ramp > RATE) ramp -= RATE;
  float a = scale(ramp / RATE, -1.0, 1.0);
  return a;
}

float tria_generator(float freq) {
  // FIXME
  float a = mysy_sample / RATE * 2 * PI * freq;
  return a;
}

float sqre_generator(float freq) {
  float a = (sawt_generator(freq) > 0.0) ? 1.0 : -1.0;
  return a;
}

float mirr_generator(float freq) {
  // FIXME
  float T = mysy_sample / RATE * 2 * PI * freq;
  return sin(T);
}

float peak_generator(float freq) {
  float T = mysy_sample / RATE * 2 * PI * freq;
  float r = sin(T);
  if (r >  LIMIT) r =  2.0 * LIMIT - r;
  if (r < -LIMIT) r = -2.0 * LIMIT - r;
  return r;
}

float nois_generator(float freq) {
  // FIXME do gen
  return 0.0;
}

float mysy_note(u8 wave, u8 leng, float freq, float amp) {
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
