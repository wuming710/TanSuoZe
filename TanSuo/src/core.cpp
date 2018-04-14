#include "core.h"
#define MOTOLEFT1 9
#define MOTOLEFT2 10
#define MOTORIGHT1 5
#define MOTORIGHT2 6



void MotoLeftStop()
{
	digitalWrite(MOTOLEFT2, LOW);
	digitalWrite(MOTOLEFT1, LOW);
}
void MotoRightStop()
{
	digitalWrite(MOTORIGHT2, LOW);
	digitalWrite(MOTORIGHT1, LOW);
}


void MotoLeftUp(int speed)
{
	analogWrite(MOTOLEFT2, speed);
	analogWrite(MOTOLEFT1, LOW);
}
void MotoLeftDown(int speed)
{
	analogWrite(MOTOLEFT1, speed);
	analogWrite(MOTOLEFT2, LOW);
}

void MotoRightUp(int speed)
{
	analogWrite(MOTORIGHT2, speed);
	analogWrite(MOTORIGHT1, LOW);
}

void MotoRightDown(int speed)
{
	analogWrite(MOTORIGHT1, speed);
	analogWrite(MOTORIGHT2, LOW);
}

unsigned char BlackLeft()
{
	if (digitalRead(A0))
		return 4;
	return 0;
}

unsigned char BlackRight()
{
	if (digitalRead(A4))
		return 1;
	return 0;
}

unsigned char BlackBeh()
{
	if (digitalRead(A2))
		return 2;
	return 0;
}

bool Accelate()
{
	return !digitalRead(3);
}
