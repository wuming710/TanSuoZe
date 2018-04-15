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
	state = Test;
	line = LGaoTai2;
	Serial.begin(9600);

}
bool set = false;
void loop() {


	//czmayu

}
