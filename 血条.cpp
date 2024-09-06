#include<graphics.h>
#include"Ѫ��.h"


_BloodbarDraw::_BloodbarDraw()
{


	weight = 20;
	height = 5;
	rate = 1;

}
void _BloodbarDraw::draw(int x, int y, int bloodtotal, int NowBlood, int ellipsewidth, int ellipseheight, bool _flag)
{
	SetWorkingImage();
	flag = _flag;
	if (flag)
	{
		rate = NowBlood / bloodtotal;
		//����Ѫ������
		int EndBloodBarLenth = rate * weight;
		//���ñ߿�ɫ
		setcolor(BLACK);
		//�������ɫ
		setfillcolor(WHITE);
		//��������Σ�������ʾ��Ѫ��
		fillroundrect(
			x, y, x + weight, y + height, ellipsewidth, ellipseheight
		);
		//�����ھ��Σ�������ʾ��ǰѪ��
		//Ѫ���ȴ��ڵ�����Ѫ����60%
		if (rate >= 0.6) {
			setfillcolor(GREEN);
			fillroundrect(
				x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
			);
			////����Ѫ��
			//NowBlood = NowBlood - Harm;
		}
		//Ѫ���ȴ��ڵ�����Ѫ����30%������С��60%
		else if (rate >= 0.3) {
			setfillcolor(RGB(255, 165, 0));
			fillroundrect(
				x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
			);
			/*NowBlood = NowBlood - Harm;*/
		}
		//Ѫ���ȴ��ڵ�����Ѫ��������С��30%
		else if (rate >= 0) {
			setfillcolor(RED);
			fillroundrect(
				x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
			);
			/*NowBlood = NowBlood - Harm;*/
		}
		/*else {
			return false;
		}
		return true;*/
		setbkmode(TRANSPARENT);
		settextcolor(BLACK);
		settextstyle(17, 0, _T("Consolas"));
		outtextxy(x - 20, y - 8, _T("Ѫ��"));
	}
}
void _BloodbarDraw::draw(int x, int y, double _rate, int ellipsewidth, int ellipseheight, bool _flag)
{
	SetWorkingImage();
	rate = _rate;
	flag = _flag;
	if (flag)
	{

		//����Ѫ������
		int EndBloodBarLenth = rate * weight;
		//���ñ߿�ɫ
		setcolor(BLACK);
		//�������ɫ
		setfillcolor(WHITE);
		//��������Σ�������ʾ��Ѫ��
		fillroundrect(
			x, y, x + weight, y + height, ellipsewidth, ellipseheight
		);
		//�����ھ��Σ�������ʾ��ǰѪ��
		//Ѫ���ȴ��ڵ�����Ѫ����60%
		if (rate >= 0.6) {
			setfillcolor(GREEN);
			fillroundrect(
				x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
			);
			////����Ѫ��
			//NowBlood = NowBlood - Harm;
		}
		//Ѫ���ȴ��ڵ�����Ѫ����30%������С��60%
		else if (rate >= 0.3) {
			setfillcolor(RGB(255, 165, 0));
			fillroundrect(
				x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
			);
			/*NowBlood = NowBlood - Harm;*/
		}
		//Ѫ���ȴ��ڵ�����Ѫ��������С��30%
		else if (rate >= 0) {
			setfillcolor(RED);
			fillroundrect(
				x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
			);
			/*NowBlood = NowBlood - Harm;*/
		}

	}
}