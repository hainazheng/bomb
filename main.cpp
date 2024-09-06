#include<iostream>
#include<graphics.h>
#include"map.h"
#include"player.h"
//#include"血条.h"
#include<Windows.h>
#include"bomb.h"
#include"enemy.h"
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
//const int map_w = scr_w*2;
//const int map_h = scr_h*2;
//IMAGE MAP(map_w, map_h);
#define max_enemy 10		//最大敌人数量
map a;
player haina1;
bomb bomb1(true);
bomb enemy_bomb[max_enemy];
enemy _enemy[max_enemy];
//进度2024.8.31 完成基本操作
void map_draw();
void map_init();
void update();
void draw_scr();
void menu();
/*void enemy_col();*/				//敌人被炸弹碰撞检测
int tot_time = 0;
int main()
{
	
	initgraph(scr_w, scr_h, SHOWCONSOLE);
	menu();
	PlaySound(TEXT("F:\\sucai\\secer.wav"), NULL, SND_FILENAME | SND_ASYNC);
	map_init();
	int _time = 0;
	while (true)
	{
		/*BeginBatchDraw();*/
		/*map_draw();*/
		
		a.draw_rec();
		SetWorkingImage();
			/*setbkcolor(WHITE);*/
			/*cleardevice();*/
			/*_BloodbarDraw b;
			b.draw(250, 100, 0.5);*/

		//绘制地图到当前窗口上
		/*putimage(0, 0,scr_w,scr_h, &a.MAP ,s);*/
		/*FlushBatchDraw();*/
		/*haina1.drawblood(1);*/
		//更新地图数据
		draw_scr();
		update();
		Sleep(80);
		
		if(haina1.exist_flag == 0)			//玩家一死暂停游戏
		{
			
			if (_time == 3)
			{
				cout << "game over" << endl;
				system("Pause");
			}
			_time++;
			/*cout << _time << endl;*/
		}
		tot_time++;
		if (tot_time == 90)
		{
			tot_time = 0;
		}
		if (GetAsyncKeyState(81))		//按下q暂停 bug1.无法继续
		{
			PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
			system("Pause");
			
		}
		/*cout << _enemy[1].exist_flag;*/
		
	}
	/*EndBatchDraw();*/
}

void menu()
{
	int menu_finish = 0;
	MOUSEMSG mouse;
	while (!menu_finish)			//设置开始页面
	{
		IMAGE menu;
		loadimage(&menu, _T("F:\\sucai\\menu.png"));
		putimage(0, 0, &menu);
		mouse = GetMouseMsg();
		switch (mouse.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (mouse.x >= 360 && mouse.y >= 250 && mouse.x < 600 && mouse.y < 335)
			{
				menu_finish = 1;		//结束开始页面
			}
		}
	}
}

void map_init()			//数组的数据进行初始化
{
	SetWorkingImage(&a.MAP);


	

	//根据数组绘制
	a.map_init();
	haina1.init(a);
	/*player* p = &haina1;*/
	for (int i = 0; i < max_enemy; i++)
	{
		_enemy[i].order=i+1;
		_enemy[i].init(a);
		_enemy[i].enemy_director(haina1.x, haina1.y);
	}
	/*cout << p->dtor;*/
	/*a.joinplayer(p);*/
	a.joinplayer(haina1);
	bomb1.joinplayer(&haina1);
	a.joinenemy(_enemy[0], max_enemy);
	for (int i = 0; i < max_enemy; i++)
	{
		bomb1.joinenemy(&_enemy[0], max_enemy);
		enemy_bomb[i].status = true;
		enemy_bomb[i].joinplayer(&haina1);
		enemy_bomb[i].joinenemy(&_enemy[0], max_enemy);
		
		/*enemy_bomb[i].joinplayer(&haina1);*/
	}
}


void map_draw()
{

	SetWorkingImage(&a.MAP);
	/*loadimage(&a.MAP, _T("C:\\Users\\84454\\Desktop\\c\\动作素材\\map1.png"), map_x, map_y);*/
	/*map_init();*/
	
	
	a.draw_rec();

	//绘制血条
	haina1.drawblood(1); 
}

void update()
{
	haina1.move(1, a);	
	haina1.map_bomb(bomb1,a);
	if (bomb1.bomb_start || bomb1.fire_start || bomb1.placed_start)
	{
		if(bomb1.time<bomb1.maxtime)
		bomb1.time++;
		/*cout << bomb1.time << endl*/;
		/*bomb1.time = bomb1.time % (bomb1.maxtime+1);*/
	}
	for (int i = 0; i < max_enemy; i++)				//控制敌人放置炸弹时间
	{
		if (enemy_bomb[i].bomb_start || enemy_bomb[i].fire_start || enemy_bomb[i].placed_start)
		{
			if (enemy_bomb[i].time < enemy_bomb[i].maxtime)
				enemy_bomb[i].time++;
		}
	}
	if (tot_time % 10 == 0)
	{
		for (int i = 0; i < max_enemy; i++)	//敌人移动
		{
			_enemy[i].enemy_director(haina1.x, haina1.y );
			
			/*if(_enemy[i].enemy_director(haina1.x, haina1.y==3))
				cout<<3<<endl;*/
		}
	}
	if (tot_time % 3 == 0)		//控制敌人速度
	{
		for (int i = 0; i < max_enemy; i++)	//敌人移动
		{
			
			_enemy[i].move(1, a);
			
		}
	}
	if (tot_time % 10 == 0)
	{
		for (int i = 0; i < max_enemy; i++)	
		{
			
			_enemy[i].map_bomb(enemy_bomb[i], a);
			/*if(_enemy[i].enemy_director(haina1.x, haina1.y==3))
				cout<<3<<endl;*/
		}
	}
	int enemy_count = 0;
	for (int i = 0; i < max_enemy; i++)
	{
		
		if (_enemy[i].exist_flag == 0)
		{
			enemy_count++;
		}
		
	}
	for (int i = 0; i < max_enemy; i++)
	{
		if (enemy_count == 10)
		{
			_enemy[i].enemy_rand();
			_enemy[i].exist_flag = 1;
		}
	}
}

//绘制屏幕 每一个格子是25*25
void draw_scr()
{
	SetWorkingImage(NULL);
	double src_x = 0;
	double src_y = 0;
	src_x = haina1.x*25 - 500.0;
	/*cout << ball_1._x << endl;*/
	//cout << src_x << endl;
	src_y = haina1.y*25 - scr_h / 2.0;
	/*cout << src_x << endl;*/
	if (src_x <= 0)							//小于零说明在左半边
	{
		src_x = 0;
	}
	if (src_x >= (map_x - scr_w))			//
	{
		src_x = map_x - scr_w;
	}
	//if (src_x > 0&& src_x < (map_w - scr_w))							//小于零说明在左半边
	//{
	//	src_x = ball_1._x;
	//}
	if (src_y <= 0)
	{
		src_y = 0;
	}
	if (src_y >= (map_y - scr_h))
	{
		src_y = map_y - scr_h;
	}
	putimage(0, 0, scr_w, scr_h, &a.MAP, src_x,src_y);
}