/********************************************************
 * Simple Software Synthesizer
 * @param amp: amplitude, 0xffff equals 1.0f
 * 2017 (c) Zoltán Vér
 *******************************************************/

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

#define s8	char
#define s16	short
#define s32	int
#define s64	long long
#define u8	unsigned char
#define u16	unsigned short
#define u32	unsigned int
#define u64	unsigned long long

#define PI	3.14159

u16  		mysy_sample;
typedef float (*generatorDef)(float);

float mysy_note(u8 wave, u8 leng, float freq, float amp);
void  mysy_nextSample(void);

#endif // __MYSYNTH_H__

