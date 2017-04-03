#ifndef __MYSYNTH_H__
#define __MYSYNTH_H__

#define RATE    44100
#define SECONDS 2.0
#define LIMIT   0.5

#define SINE    0
#define SAWT    1
#define TRIA    2
#define SQRE    3
#define MIRR    4
#define PEAK    5
#define NOIS    6

float sample;
typedef float (*generatorDef)(float, float);

float note(unsigned char wave, unsigned char leng, float freq, float amp);

#endif // __MYSYNTH_H__
