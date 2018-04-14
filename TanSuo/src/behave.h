#ifndef _BEHAVE_H_
#define _BEHAVE_H_


#include "globle.h"


extern unsigned char LineControl();

extern void MotoInit();
extern void RedInInit();

void LedSetM(int Mode);
void LedSetT(unsigned char i);
extern void Go(int speed); //speed should between 0-255
extern void GoCon(int SpeedLeft, int SpeedRight);
extern void Back(int speed); //speed should between 0-255

extern void TurnLeft(int speed); //speed should between 0-255
extern void TurnLeftB(int speed);
extern void TurnRight(int speed); //speed should between 0-255
extern void TurnRightB(int speed);
extern void Stop();
extern bool XunJi();
extern void XunJiCon(int GoSpeed, int TurnleftSpeed, int TurnRightSpeed, int BackSpeed);
extern void XunJiDelay(int time);
extern void XunJiDelayLed(int time, int mode);


#endif // !_BEHAVE_H_