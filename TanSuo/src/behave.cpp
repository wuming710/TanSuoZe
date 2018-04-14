#include "behave.h"
#include "core.h"
#include "LedControl.h"
extern LedControl lc;
extern unsigned char Echo[5][7];

void LedSetM(int Mode)//×´Ì¬£¬·½Ïò0Go 1Left 2Right 3Back 4 Stop
{
	lc.shutdown(0, false);
	lc.setIntensity(0, 8);
	lc.clearDisplay(0);

	for (int j = 1; j < 8; j++)
	{
		lc.setRow(0, j, Echo[Mode][j - 1]);
		_delay_us(2);
	}

	lc.shutdown(0, true);
}

void LedSetT(unsigned char i)//×´Ì¬£¬·½Ïò0Go 1Left 2Right 3Back 4 Stop
{
	lc.shutdown(0, false);
	lc.setIntensity(0, 8);
	lc.clearDisplay(0);
	lc.setRow(0, 0, i);
	lc.shutdown(0, true);
}
unsigned char LineControl()
{
	/*if		(!BlackLeft() && !BlackBeh() && !BlackRight())	return 1;//000
	else if (!BlackLeft() && !BlackBeh() &&  BlackRight())	return 2;//001
	else if (!BlackLeft() &&  BlackBeh() && !BlackRight())	return 3;//010
	else if ( !BlackLeft()&& BlackBeh()  &&  BlackRight())	return 4;//011
	else if ( BlackLeft() && !BlackBeh() && !BlackRight())	return 5;//100
	else if ( BlackLeft() && !BlackBeh() &&  BlackRight())	return 6;//101
	else if ( BlackLeft() &&  BlackBeh() && !BlackRight())	return 7;//110
	else if ( BlackLeft() &&  BlackBeh() &&  BlackRight())	return 8;//111
	else return 0;
*/
	unsigned char  flag = BlackLeft() + BlackBeh() + BlackRight();
	return flag + 1;
/*
	switch (flag)
	{
	case 0: return 1;
	case 1: return 2;
	case 2: return 3;
	case 3: return 4;
	case 4: return 5;
	case 5: return 6;
	case 6: return 7;
	case 7: return 8;
	default:	return 0;
	}

*/
}

void MotoInit()
{
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
}

void RedInInit()
{
	pinMode(A0, INPUT);
	pinMode(A4, INPUT);
	pinMode(A2, INPUT);
}

void Go(int speed)
{
	LedSetM(2);
	
	switch (speed)
	{
	case 255:GoCon(255, 243); break;
	case 200:GoCon(200, 195); break;
	case 150:GoCon(150, 160); break;
	case 100:GoCon(100, 117); break;
	default:GoCon(speed,speed); break;
	}
//	GoCon(speed, speed);

}
void GoCon(int SpeedLeft,int SpeedRight)
{
	LedSetM(2);
	MotoLeftUp(SpeedLeft);
	MotoRightUp(SpeedRight);
}

void Back(int speed)
{
	LedSetM(1);
	MotoLeftDown(speed);
	MotoRightDown(speed);
}

void TurnLeft(int speed)
{
	LedSetM(0);
	MotoLeftUp(speed-80);
//	MotoLeftStop();
	MotoRightUp(speed);
}
void TurnLeftB(int speed)
{
	LedSetM(0);
	MotoLeftDown(speed);
	MotoRightUp(speed);
}

void TurnRight(int speed)
{
	LedSetM(3);
//	MotoLeftUp(speed);
	MotoRightUp(speed-80);
	MotoRightStop();
}
void TurnRightB(int speed)
{
	LedSetM(3);
	MotoLeftUp(speed);
	MotoRightDown(speed);
}

void Stop()
{
	LedSetM(4);
	MotoLeftStop();
	MotoRightStop();
}

bool XunJi()
{
	switch (BlackLeft() + BlackBeh() + BlackRight() + 1)
	{
	case 8: Go(100); return true;		//111+¿Ú£¬×ª×´Ì¬   
	case 1:Back(90); break;			//000 
	case 2:TurnRight(200); break;	//001 
	case 3:Go(100); break;			//010
	case 4:TurnRight(200); break;	//011  B
	case 5:TurnLeft(200); break;	//100
	case 6:Back(90); break;	//101 ºÚ°×ºÚ
	case 7:TurnLeft(200); break;	//110 B
									//	default:Stop(); break;
	}
	return false;
}


void XunJiCon(int GoSpeed, int TurnleftSpeed, int TurnRightSpeed, int BackSpeed)
{
	switch (LineControl())
	{
	case 1:Back(BackSpeed); break;			//000 
	case 2:TurnRight(TurnRightSpeed); break;	//001 
	case 3:Go(GoSpeed); break;			//010
	case 4:TurnRightB(TurnRightSpeed); break;	//011  B
	case 5:TurnLeft(TurnleftSpeed); break;	//100
	case 6:Back(BackSpeed); break;	//101 ºÚ°×ºÚ
	case 7:TurnLeftB(TurnleftSpeed); break;	//110
	case 8:Go(GoSpeed); break;		//111T¿Ú£¬×ª×´Ì¬   */
	default:Stop(); break;
	}
}
void XunJiDelay(int time)
{
	for(int i=0;i<time;i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				XunJi();
}
void XunJiDelayLed(int time,int mode)
{
	for (int i = 0; i<time; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
			{
				XunJi();
				LedSetT(mode);
			}
}