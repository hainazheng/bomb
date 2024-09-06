#include<iostream>
#include<graphics.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include"map.h"
//#include"Ѫ��.h"
#include<Windows.h>
#include"player.h"
#include"bomb.h"


//�ڵ�ͼ������Ϊ���ĳ���λ��3*3λ�ò��ܳ��ַ���
void player::init(map& map1)
{

	for (int i = y - 1; i <= y + 1; i++)
	{
		for (int j = x - 1; j <= x + 1; j++)
		{

			if (map1.a[i][j] != 0)
			{
				map1.a[i][j] = 0;

			}
		}

	}
	map1.a[y][x] = -1;			//��ǰλ���������
}

void player::drawblood(bool _flag)
{
	_BloodbarDraw a;
	a.draw(x*25+2,y*25-13,1.0, 5, 5, _flag);
}

void player::map_update(map& map1)
{
	if (map1.a[y][x] != -1)
	{
		//��ǰ����������
		if (dtor == UP)
		{
			if (map1.a[y + 1][x] == -1)
				map1.a[y + 1][x] = 0;			//����ǰһ������Ԫ����0
		}
		//��ǰ����������
		if (dtor == DOWN)
		{
			if (map1.a[y - 1][x] == -1)
				map1.a[y - 1][x] = 0;			//����ǰһ������Ԫ����0
		}
		//��ǰ����������
		if (dtor == RIGHT)
		{
			if (map1.a[y][x - 1] == -1)
				map1.a[y][x - 1] = 0;			//����ǰһ������Ԫ����0
		}
		//��ǰ����������
		if (dtor == LEFT)
		{
			if (map1.a[y][x + 1] == -1)
				map1.a[y][x + 1] = 0;			//����ǰһ������Ԫ����0
		}
		map1.a[y][x] = -1;
	}
}

void player::move(int step)
{
	if (exist_flag)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			if (y > 1)
			{
				y -= step;
				dtor = UP;
			}
			dtor = UP;

		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (x > 1)
			{
				x -= step;
				dtor = LEFT;
			}
			dtor = LEFT;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (y < map_y / 25 - 1)
			{
				y += step;
				dtor = DOWN;
			}
			dtor = DOWN;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (x < map_x / 25 - 1)
			{
				x += step;
				dtor = RIGHT;
			}
			dtor = RIGHT;
		}

	}
}


//debug 2024.8.24 �첽�����������ϵȲ���ԭ����ûɾ�� ����һֱ�Ӱ����ݸ���д��move ������ֱ����һ��ֵ�洢�첽����ķ���ֵ��һ��ֻ�ж�һ��
void player::move(int step, map& map1)
{
	
	if (exist_flag)
	{
		if (GetAsyncKeyState(VK_UP)&0x8000)
		{
			if (y > 1 && map1.a[y - 1][x] == 0)
			{
				y -= step;
				if (map1.a[y + 1][x] == -1)
					map1.a[y + 1][x] = 0;
			}
			dtor = UP;
			map1.a[y][x] = -1;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			if (x > 1 && map1.a[y][x - 1] == 0)
			{
				x -= step;
				if (map1.a[y][x + 1] == -1)
					map1.a[y][x + 1] = 0;
			}
			dtor = LEFT;
			map1.a[y][x] = -1;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (y < map_y / 25 - 1 && map1.a[y + 1][x] == 0)
			{
				y += step;
				if (map1.a[y - 1][x] == -1)
					map1.a[y - 1][x] = 0;
			}
			dtor = DOWN;
			map1.a[y][x] = -1;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			if (x < map_x / 25 - 1 && map1.a[y][x + 1] == 0)
			{
				x += step;
				if (map1.a[y][x - 1] == -1)
					map1.a[y][x - 1] = 0;
			}
			dtor = RIGHT;
			map1.a[y][x] = -1;
		}
		/*map1.a[y][x] = -1;*/
	}
	/*map_update(map1);*/
	
}

void player::map_bomb(bomb& bomb1, map& map1)
{
	if (exist_flag)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			/*bomb1.status=true;*/
			if (!bomb1.bomb_start && !bomb1.fire_start && !bomb1.placed_start)
			bomb1.bomb_start = true;
			if(bomb1.num<=2)
			bomb1.num++;
			/*cout << "num:" << bomb1.num << endl;*/
			if (bomb1.num == 1)
			{
				 bomb1._x = x;
				bomb1._y = y;
			}
		}
		
	}bomb1.bomb_rg(map1, x, y,1);
}
