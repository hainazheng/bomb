#include"bomb.h"
#include"map.h"
#include"player.h"
#include"enemy.h"
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
void bomb::enable()
{
	if(status==true)
		status=false;
	else
	{
		status = true;
	}
}

void bomb::joinplayer(player* a)
{
	a1 = a;
}

void bomb::joinenemy(enemy* a,int n)
{
	en = a;
}
//debug 2024.8.30 �����ڱ߽����ը��������		����1.countû����whileѭ������ർ�����ֵ��1������˳�����ѭ��
void bomb::bomb_rg(map& map1,int x1,int y1,int sound,int max_fireend_time,int max_bomb_time, int max_bombend_time)
{
	/*time++;*/
	bomb_placed(map1, _x, _y, max_bombend_time);			//ͬʱֻ�ܷ���һ��
	if (status&&time==maxtime&&placed_start)
	{
		if(sound==1)
		PlaySound(TEXT("F:\\sucai\\��ը��.wav"), NULL, SND_FILENAME | SND_ASYNC);
		if (_y>=1&&_x>=1 &&_y<=map1.map_wh.map_y-2&&_x<= map1.map_wh.map_x - 2)			//������������ڲ�
		{
			if (map1.a[_y][_x] == 4||map1.a[_y][_x]==-1)														//��ǰλ���Ѿ��ź�ը��
			{
				if (a1 != NULL)
				{
					if (a1->x == _x && a1->y == _y)		//ֻҪ���������ը������ʧ
					{
						a1->exist_flag = 0; cout << a1->x << ' ' << a1->exist_flag << endl;
					}
				}
				if(en!=NULL)
				{
					for (int i = 0; i < 10; i++)
					{
						if (en[i].x == _x && en[i].y == _y)		//ֻҪ�е�������ը������ʧ
						{
							en[i].exist_flag = 0; 
							cout << en[i].x << ' ' << en[i].exist_flag << endl;
						}
					}
				}
				map1.a[_y][_x] = 3;			//����ը��			1.ʮ����
				int count = 1;		//����
				int y = _y;
				int x = _x;
				while (count < rg)			//�ж�����
				{
					if (map1.a[y - 1][x] != 1)
					{
						if (map1.a[y - 1][x] == 2)
						{
							map1.a[y - 1][x] = 3;
							break;
						}
						if (map1.a[y - 1][x] == -1)		//ֻҪ���������ը������ʧ
						{
							if(a1!=NULL)
							a1->exist_flag = 0;
						}
						for (int i = 1; i <= 10; i++)
						{
							if (en[i - 1].x == x && (en[i - 1].y-1) == y)
							{
								
								if (en[i - 1].exist_flag)
								{
									cout << i << endl;
									en[i - 1].exist_flag = 0;
									map1.a[y - 1][x] = 0;
								}
							}
						}
						map1.a[y - 1][x] = 3;
						y--;
						
					}
					count++;
					/*cout << "y:" << y <<' '<<count << endl;*/
				}
				count = 1;
				y = _y;
				x = _x;
				while (count < rg)			//�ж�����
				{
					if (map1.a[y + 1][_x] != 1)
					{
						if (map1.a[y + 1][x] == 2)
						{
							map1.a[y + 1][x] = 3;
							break;
						}
						if (map1.a[y + 1][x] == -1)		//ֻҪ���������ը������ʧ
						{
							if (a1 != NULL)
							a1->exist_flag = 0;/*cout <<a1->x<<' ' << a1->exist_flag << endl;*/
						}
						for (int i = 1; i <= 10; i++)
						{
							if (en[i-1].x==x&&(en[i-1].y+1)==y)
								if (en[i - 1].exist_flag)
								{
									en[i - 1].exist_flag = 0;
									map1.a[y + 1][x] = 0;
								}
						}
						map1.a[y + 1][x] = 3;
						y++;
						
					}
					count++;
				/*	cout << y << endl;*/
				}
				count = 1;
				y = _y;
				x = _x;
				while (count < rg)			//�ж�����
				{
					if (map1.a[y ][x-1] != 1)
					{
						if (map1.a[y ][x-1] == 2)
						{
							map1.a[y ][x-1] = 3;
							break;
						}
						if (map1.a[y ][x-1] == -1)		//ֻҪ���������ը������ʧ
						{
							if (a1 != NULL)
							a1->exist_flag = 0;
						}
						map1.a[y][x - 1] = 3;
						
						for (int i = 1; i <= 10; i++)
						{
							if ((en[i - 1].x-1) == x && en[i - 1].y == y)
								if (en[i - 1].exist_flag)
								{
									en[i - 1].exist_flag = 0;
									map1.a[y ][x-1] = 0;
								}
						}
						x--;
					}
					count++;
				}
				count = 1;
				 y = _y;
				x = _x;
				while (count < rg)			//�ж�����
				{
					if (map1.a[y ][x+1] != 1)
					{
						if (map1.a[y ][x+1] == 2)
						{
							map1.a[y ][x+1] = 3;
							break;
						}
						if (map1.a[y ][x+1] == -1)		//ֻҪ���������ը������ʧ
						{
							if (a1 != NULL)
							a1->exist_flag = 0;
						}
						map1.a[y][x + 1] = 3;
						
						for (int i = 1; i <= 10; i++)
						{
							if ((en[i - 1].x+1) == x && en[i - 1].y == y)
								if (en[i - 1].exist_flag)
								{
									en[i - 1].exist_flag = 0;
									map1.a[y][x +1] = 0;
								}
						}
						x++;
					}
					count++;
				}

			}
		}
		placed_start = false;
		fire_start = true;
		time=0;
		settime(max_fireend_time);			//���û𻨳���ʱ��
	}
	bomb_hide(map1, _x, _y, max_bomb_time);	
}

void bomb::bomb_hide(map& map1, int x, int y, int max_bomb_time)
{
	if (time == maxtime && fire_start&&status)
	{
		//��ʡ��������
		for (int i = y - rg + 1; i <= y + rg - 1; i++)
		{
			for (int j = x - rg + 1; j <= x + rg - 1; j++)
			{
				/*cout <<'\n' << map1.a[i][j] << ' ';*/
				if (map1.a[i][j] == 3)
				{
					map1.a[i][j] = 0;
				}
				
			}
		}
		fire_start = 0;			//����ʧ
		time = 0;
		settime(max_bomb_time);			//���ó���ը����ʱ��
		/*bomb_start = true;*/
		num=0;
	}
}

void bomb::bomb_placed(map& map1, int x, int y,int max_bombend_time)
{
	if (status&&time==maxtime&&bomb_start)
	{
		map1.a[y][x] = 4;
		settime(max_bombend_time);
		placed_start = true;
		bomb_start = false;
		time = 0;
		/*_x = x;
		_y = y;*/
		
	}
}

void bomb::settime(int n)
{

	maxtime = n;
}
