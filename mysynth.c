#include <stdio.h>
#include <math.h>
#include "mysynth.h"

//TODO ADSR, filters, LFO?

float sine_generator(float freq, float amp) {
  float T = sample / RATE * 2 * M_PI * freq;
  return sin(T) * amp;
}

float sawt_generator(float freq, float amp) {
  // FIXME
  float T = sample / RATE * 2 * M_PI * freq;
  return sin(T) * amp;
}

float tria_generator(float freq, float amp) {
  // FIXME
  float T = sample / RATE * 2 * M_PI * freq;
  return sin(T) * amp;
}

float sqre_generator(float freq, float amp) {
  // FIXME
  float T = sample / RATE * 2 * M_PI * freq;
  return sin(T) * amp;
}

float mirr_generator(float freq, float amp) {
  // FIXME
  float T = sample / RATE * 2 * M_PI * freq;
  return sin(T) * amp;
}

float peak_generator(float freq, float amp) {
  float T = sample / RATE * 2 * M_PI * freq;
  float r = sin(T);
  if (r >  LIMIT) r =  2.0 * LIMIT - r;
  if (r < -LIMIT) r = -2.0 * LIMIT - r;
  return r * amp;
}

float nois_generator(float freq, float amp) {
  // FIXME do gen
  return 0.0 * amp;
}

float note(unsigned char wave, unsigned char leng, float freq, float amp) {
  generatorDef generatorPtr;
  switch (wave) {
    case (SINE): generatorPtr = &sine_generator; break;
    case (SAWT): generatorPtr = &sawt_generator; break;
    case (TRIA): generatorPtr = &tria_generator; break;
    case (SQRE): generatorPtr = &sqre_generator; break;
    case (PEAK): generatorPtr = &peak_generator; break;
    case (MIRR): generatorPtr = &mirr_generator; break;
    case (NOIS): generatorPtr = &nois_generator; break;
    default:  fprintf(stderr, "Error: Unsupported waveform: %d\n", wave);
  }
  return (*generatorPtr)(freq, amp);
}

