#ifndef __MYSYNTH_H__
#define __MYSYNTH_H__

#define RATE    44100
#define LIMIT   0.5

#define SINE    0
#define SAWT    1
#define TRIA    2
#define SQRE    3
#define MIRR    4
#define PEAK    5
#define NOIS    6

unsigned int  mysy_sample;
typedef float (*generatorDef)(float, float);

float mysy_note(unsigned char wave, unsigned char leng, float freq, float amp);
void  mysy_nextSample(void);

#endif // __MYSYNTH_H__
