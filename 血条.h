#pragma once
#include<graphics.h>

class _BloodbarDraw			//����easyx����Ѫ��fillroundrect
{
private:
	int weight;			//Ѫ�����
	int height;				//Ѫ���߶�
	double rate;			//Ѫ���ٷֱ�
	bool flag = false;
public:
	_BloodbarDraw();		//����Ѫ����ʼ�� ȫ��Ĭ����ֵ
	_BloodbarDraw(int w, int h = 5, double _rate = 1, bool _flag = 0) :weight(w), height(h), rate(_rate), flag(_flag) {};
	void draw(int x, int y, int bloodtotal, int NowBlood, int ellipsewidth = 5, int ellipseheight = 5, bool _flag = 1);				//��flag=1��ʱ��ʼ���� Ϊ0���� ��Ѫ��ֵ��ʾ
	void draw(int x, int y, double rate, int ellipsewidth = 5, int ellipseheight = 5, bool _flag = 1);

};

