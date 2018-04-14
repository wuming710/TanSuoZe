#ifndef _CORE_H_
#define _CORE_H_

#include <Arduino.h>

extern void MotoLeftStop();
extern void MotoRightStop();

extern void MotoLeftUp(int speed); //speed should between 0-255
extern void MotoLeftDown(int speed);

extern void MotoRightUp(int speed);
extern void MotoRightDown(int speed);

extern unsigned char BlackLeft();
extern unsigned char BlackRight();
extern unsigned char BlackBeh();

extern bool Accelate();

#endif // !_CORE_H_
