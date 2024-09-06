#pragma once
#include<graphics.h>

class _BloodbarDraw			//利用easyx绘制血条fillroundrect
{
private:
	int weight;			//血条宽度
	int height;				//血条高度
	double rate;			//血条百分比
	bool flag = false;
public:
	_BloodbarDraw();		//绘制血条初始化 全是默认数值
	_BloodbarDraw(int w, int h = 5, double _rate = 1, bool _flag = 0) :weight(w), height(h), rate(_rate), flag(_flag) {};
	void draw(int x, int y, int bloodtotal, int NowBlood, int ellipsewidth = 5, int ellipseheight = 5, bool _flag = 1);				//当flag=1的时候开始绘制 为0隐藏 有血数值显示
	void draw(int x, int y, double rate, int ellipsewidth = 5, int ellipseheight = 5, bool _flag = 1);

};

