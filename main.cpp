#include<iostream>
#include<graphics.h>
#include"map.h"
#include"player.h"
//#include"Ѫ��.h"
#include<Windows.h>
#include"bomb.h"
#include"enemy.h"
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
//const int map_w = scr_w*2;
//const int map_h = scr_h*2;
//IMAGE MAP(map_w, map_h);
#define max_enemy 10		//����������
map a;
player haina1;
bomb bomb1(true);
bomb enemy_bomb[max_enemy];
enemy _enemy[max_enemy];
//����2024.8.31 ��ɻ�������
void map_draw();
void map_init();
void update();
void draw_scr();
void menu();
/*void enemy_col();*/				//���˱�ը����ײ���
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

		//���Ƶ�ͼ����ǰ������
		/*putimage(0, 0,scr_w,scr_h, &a.MAP ,s);*/
		/*FlushBatchDraw();*/
		/*haina1.drawblood(1);*/
		//���µ�ͼ����
		draw_scr();
		update();
		Sleep(80);
		
		if(haina1.exist_flag == 0)			//���һ����ͣ��Ϸ
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
		if (GetAsyncKeyState(81))		//����q��ͣ bug1.�޷�����
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
	while (!menu_finish)			//���ÿ�ʼҳ��
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
				menu_finish = 1;		//������ʼҳ��
			}
		}
	}
}

void map_init()			//��������ݽ��г�ʼ��
{
	SetWorkingImage(&a.MAP);


	

	//�����������
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
	/*loadimage(&a.MAP, _T("C:\\Users\\84454\\Desktop\\c\\�����ز�\\map1.png"), map_x, map_y);*/
	/*map_init();*/
	
	
	a.draw_rec();

	//����Ѫ��
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
	for (int i = 0; i < max_enemy; i++)				//���Ƶ��˷���ը��ʱ��
	{
		if (enemy_bomb[i].bomb_start || enemy_bomb[i].fire_start || enemy_bomb[i].placed_start)
		{
			if (enemy_bomb[i].time < enemy_bomb[i].maxtime)
				enemy_bomb[i].time++;
		}
	}
	if (tot_time % 10 == 0)
	{
		for (int i = 0; i < max_enemy; i++)	//�����ƶ�
		{
			_enemy[i].enemy_director(haina1.x, haina1.y );
			
			/*if(_enemy[i].enemy_director(haina1.x, haina1.y==3))
				cout<<3<<endl;*/
		}
	}
	if (tot_time % 3 == 0)		//���Ƶ����ٶ�
	{
		for (int i = 0; i < max_enemy; i++)	//�����ƶ�
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

//������Ļ ÿһ��������25*25
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
	if (src_x <= 0)							//С����˵��������
	{
		src_x = 0;
	}
	if (src_x >= (map_x - scr_w))			//
	{
		src_x = map_x - scr_w;
	}
	//if (src_x > 0&& src_x < (map_w - scr_w))							//С����˵��������
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