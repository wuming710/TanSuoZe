/*
 Name:		TanSuo.ino
 Created:	2018/3/27 19:51:09
 Author:	Lavinci
*/

#include "src/behave.h"

#include "src/core.h" //测试用，最终不应该出现这个头文件
#include "src/LedControl.h"

enum State
{
	Set,GaoTai2, YuanTai,	//ZX
	Shange, JianSuDai,GaoTai,Cao_Fang,	//wuMing
	StateStop,Begin,Test,
};
enum Line
{
	LGaoTai2=1,LYuanTai,LShanGe,LJianSuDai,LGaoDi,LCaoFang,LTest,
};
unsigned char Echo[5][7] = {
	0x10,0x38,0x54,0x92,0x10,0x10,0x10,//Go
	0x10,0x20,0x40,0xfe,0x40,0x20,0x10,//left
	0x10,0x08,0x04,0xfe,0x04,0x08,0x10,//right
	0x10,0x10,0x10,0x92,0x54,0x38,0x10,//back
	0x00,0x00,0x00,0xfe,0x00,0x00,0x00,//stop
};

State state;
Line line;
LedControl lc = LedControl(12, 11, 13, 1);

void setup() {
	MotoInit();
	RedInInit();
	state = Set;//Test;//
	line = LGaoTai2;
	Serial.begin(9600);

}
bool set = false;
void loop() {


	switch (state)
	{
//-------------------------------Set--------------------------------
	case Set:
		while (!set && digitalRead(3))
		{
			LedSetT(static_cast<int>(line));
			if (!digitalRead(A3))
			{
				delay(120);
				if (!digitalRead(A3))
				{
					if (line == LTest)
						line = LGaoTai2;
					else
						line = (enum Line)(line + 1);
				}
			}

		}
		
		set = true;
		state = Begin;
		break;
//-------------------------------Begin--------------------------------
	case Begin:

	/*	LedSetT(1);
		Go(100);
		delay(700);
		while (!XunJi());*/

		switch (line)
		{
		case LGaoTai2:state = GaoTai2; break;
		case LYuanTai:state = YuanTai; break;
		case LShanGe:state = Shange; break;
		case LJianSuDai:state = JianSuDai; break;
		case LGaoDi:state = GaoTai; break;
		case LCaoFang:state = Cao_Fang; break;
		case LTest:state = Test; break;
		}


		break;
//-------------------------------GaoTai2--------------------------------
	case GaoTai2:
		
		

			//台阶2
			Go(120);     
			delay(1300);
			XunJiDelayLed(1,1);
			Go(255);	//上台阶
			delay(1300);
			Go(0);
			delay(2000);
			Go(60);	//下台阶
			delay(1500);

			XunJiDelay(2);

			Go(80);
			delay(1800);

			//三角
			XunJiDelay(2);  
			Go(220);
			delay(3000);
			XunJiDelay(4);

			//---------两个直角转弯---------
			//------ 到十字停下-----
			//*****//
			/*Go(100);
			delay(1200);*/
			TurnRightB(160);
			delay(600);
			Go(100);
			delay(1100);
			TurnLeftB(160);
			delay(600);
			Go(100);
			delay(800);

			
			//U型隧道
			Go(150);       
			delay(800);
			TurnRight(150);
			delay(6300);

			Go(150);
			delay(800);

			//----两个直角------
			TurnLeftB(150);
			delay(800);
			Go(100);
			delay(2000);
			Go(100);
			delay(1200);

			//台阶3
			XunJiDelay(2);    

			Go(255);
			GoCon(255, 230);
			delay(3000);
			Go(80);
			delay(1200);

			XunJiDelay(2);

            //半圆
			XunJiDelay(2);
			Go(1300);
			GoCon(130, 110);
			delay(6500);
			XunJiDelay(2);

			state = StateStop;
		
		break;
//-------------------------------YuanTai--------------------------------
	case YuanTai:

		//出发
		Go(120);
		delay(1000);
		//半圆减速带
		Go(100);
		delay(5000);
		XunJiDelay(3);
		//--------到十字停下
		
		//三级台阶
		Go(255);
		delay(3000);
		Go(80);
		delay(3000);
		

		break;
//-------------------------------SanGe--------------------------------
	case Shange:
		LedSetT(3);

			//出发
			Go(120);         
			delay(1000);

			//格子
			Go(150);             
			/*GoCon(120, 120);*/
			delay(6000);

			//高坡
			Go(255);
			/*GoCon(230, 200);*/
			delay(900);
			Go(0);
			delay(2000);
			Go(80);
			delay(3000);
			//Go(230);             
			//GoCon(230, 200);
			//delay(2000);
			////高坡减速
			//Go(80);               
			//delay(3500);

			//两个直角
			TurnRightB(145);      
			delay(800);
			Go(100);
			delay(1500);
			TurnLeftB(140);
			delay(500);
			Go(100);
			delay(600);

			//直角隧道
			Go(120);            
			delay(1300);

			TurnRightB(180);
			delay(1500);
			Back(100);
			delay(500);
			Go(220);
			delay(500);

			Go(255);
			GoCon(255, 200);
			delay(400);
			Back(100);
			delay(1000);
			Go(255);
			GoCon(255, 0);
			delay(300);
			Back(100);
			delay(1000);
			GoCon(255, 0);
			delay(300);
			Back(100);
			delay(1000);
			GoCon(255, 0);
			delay(300);
			Back(100);
			delay(1000);
			TurnRightB(150);
			delay(1000);
			Back(100);
			delay(1000);
			TurnRightB(150);
			delay(1000);
			Back(100);
			delay(1000);
			TurnRightB(150);
			delay(1000);
			Back(100);
			delay(1000);
			TurnRightB(150);
			delay(1300);
			Go(220);
			delay(500);

			/*TurnRight(200);
			delay(1500);
			Go(120);
			delay(500);

			TurnRight(200);
			delay(1500);
			Go(120);
			delay(500);*/

			Go(180);
			delay(1200);

			state = StateStop;
		break;
//------------------------------JianSuDai--------------------------------
	case JianSuDai:
		LedSetT(4);
	
		//出发
		Go(120);
		delay(1000);
		//减速带和草地
		Go(100);
		delay(1500);
		TurnRight(100);
		delay(500);
		Go(150);
		delay(4500);
		Go(100);
		delay(1000);
		Go(150);
		delay(4500);

		state = StateStop;

		break;
//-------------------------------GaoTai--------------------------------
	case GaoTai:
		LedSetT(5);





		//出发
		Go(120);
		delay(1000);

		//格子
		Go(150);
		/*GoCon(120, 120);*/
		delay(5000);

		//高坡
		Go(255);
		/*GoCon(230, 200);*/
		delay(900);

			Go(0);
			delay(3000);


			//Go(130);
			//GoCon(130, 120);
			//delay(7000);

			///*XunJiDelay(5);
			//XunJiDelay(3);*/

			//Go(230);
			//GoCon(230, 200);
			//delay(1400);
			TurnRightB(150);
			delay(2000);
			Go(255);
			delay(1000);

			TurnRightB(250);
			delay(8000);


			state = StateStop;

		break;
//-------------------------------Cao_fang--------------------------------
	case Cao_Fang:

		Go(120);
		delay(1000);
		//半圆减速带
		Go(255);
		delay(3000);
		XunJiDelay(3);
		//--------到十字停下

		//三级台阶
		Go(255);
		delay(3000);
		Go(80);
		delay(3000);


		/*Go(100);
		delay(1000);
		Go(150);
		delay(2000);
		Go(100);
		delay(1000);
		Go(150);
		delay(2500);
		Go(100);
		delay(2000);
		XunJiDelay(2);


		TurnRightB(150);
		delay(800);
		Go(100);
		delay(2100);
		TurnLeftB(150);
		delay(800);
		Go(100);
		delay(600);

		//直角隧道
		Go(120);
		delay(1300);

		TurnLeftB(180);
		delay(1500);
		Back(100);
		delay(500);
		Go(220);
		delay(500);

		Go(255);
		//GoCon(255, 200);
		delay(400);
		Back(100);
		delay(500);
		Go(255);
		GoCon(0, 255);
		delay(300);
		Back(100);
		delay(500);
		GoCon(0, 255);
		delay(300);
		Back(100);
		delay(500);
		GoCon(0, 255);
		delay(300);
		Back(100);
		delay(500);
		TurnLeftB(150);
		delay(1300);
		Go(220);
		delay(500)*/;

		break;
//-------------------------------Test--------------------------------
	case Test:
		LedSetT(0xfe);
		Serial.println(digitalRead(2));
		//delay(1000);
		break;
//-------------------stop--------------------------------------------
	case StateStop:
		Stop();
		break;
//---------------------------------------------------------------
	default:
		Stop();
		LedSetT(0xf0);
		break;
	}
}
