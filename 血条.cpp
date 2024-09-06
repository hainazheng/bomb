#include<graphics.h>
#include"血条.h"


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
		//最终血条长度
		int EndBloodBarLenth = rate * weight;
		//设置边框色
		setcolor(BLACK);
		//设置填充色
		setfillcolor(WHITE);
		//绘制外矩形，用于显示总血量
		fillroundrect(
			x, y, x + weight, y + height, ellipsewidth, ellipseheight
		);
		//绘制内矩形，用于显示当前血量
		//血量比大于等于总血量的60%
		if (rate >= 0.6) {
			setfillcolor(GREEN);
			fillroundrect(
				x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
			);
			////更新血量
			//NowBlood = NowBlood - Harm;
		}
		//血量比大于等于总血量的30%，并且小于60%
		else if (rate >= 0.3) {
			setfillcolor(RGB(255, 165, 0));
			fillroundrect(
				x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
			);
			/*NowBlood = NowBlood - Harm;*/
		}
		//血量比大于等于总血量，并且小于30%
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
		outtextxy(x - 20, y - 8, _T("血量"));
	}
}
void _BloodbarDraw::draw(int x, int y, double _rate, int ellipsewidth, int ellipseheight, bool _flag)
{
	SetWorkingImage();
	rate = _rate;
	flag = _flag;
	if (flag)
	{

		//最终血条长度
		int EndBloodBarLenth = rate * weight;
		//设置边框色
		setcolor(BLACK);
		//设置填充色
		setfillcolor(WHITE);
		//绘制外矩形，用于显示总血量
		fillroundrect(
			x, y, x + weight, y + height, ellipsewidth, ellipseheight
		);
		//绘制内矩形，用于显示当前血量
		//血量比大于等于总血量的60%
		if (rate >= 0.6) {
			setfillcolor(GREEN);
			fillroundrect(
				x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
			);
			////更新血量
			//NowBlood = NowBlood - Harm;
		}
		//血量比大于等于总血量的30%，并且小于60%
		else if (rate >= 0.3) {
			setfillcolor(RGB(255, 165, 0));
			fillroundrect(
				x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
			);
			/*NowBlood = NowBlood - Harm;*/
		}
		//血量比大于等于总血量，并且小于30%
		else if (rate >= 0) {
			setfillcolor(RED);
			fillroundrect(
				x, y, x + EndBloodBarLenth, y + height, ellipsewidth, ellipseheight
			);
			/*NowBlood = NowBlood - Harm;*/
		}

	}
}