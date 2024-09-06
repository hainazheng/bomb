#include"enemy.h"
#include"map.h"
#include"bomb.h"
int k=10;
enemy::enemy() 
{
	srand(k++);

	x = rand() % 78+1;
	y = rand() % 38+1;
	cout << "x:" << x << ' ' << "y:" << y << endl;
}

void enemy::enemy_rand()
{
	srand(k++);
	if (k % 50 == 0)
		k = 0;
	x = rand() % 78 + 1;
	y = rand() % 38 + 1;
}

void enemy::init(map& map1)
{

	for (int i = y - 1; i <= y + 1; i++)
	{
		for (int j = x - 1; j <= x + 1; j++)
		{

			if (map1.a[i][j] == 1|| map1.a[i][j] == 2)
			{
				map1.a[i][j] = 0;

			}
		}

	}
	map1.a[y][x] = 100+order;			//当前位置设置玩家
	/*cout << map1.a[y][x];*/
}

void enemy::move(int step, map& map1)
{

	if (exist_flag)
	{
		switch (dtor) {
		case UP:

			if (y > 1 && map1.a[y - 1][x] == 0)
			{
				y -= step;
				if (map1.a[y + 1][x] == 100+order)
					map1.a[y + 1][x] = 0;map1.a[y][x] = 100 + order;
			}

			
			break;

		case LEFT:

			if (x > 1 && map1.a[y][x - 1] == 0)
			{
				x -= step;
				if (map1.a[y][x + 1] == 100 + order)
					map1.a[y][x + 1] = 0;map1.a[y][x] = 100 + order;
			}

			
			break;

		case DOWN:

			if (y < map_y / 25 - 1 && map1.a[y + 1][x] == 0)
			{
				y += step;
				if (map1.a[y - 1][x] == 100 + order)
					map1.a[y - 1][x] = 0;map1.a[y][x] = 100 + order;
			}

			
			break;

		case RIGHT:

			if (x < map_x / 25 - 1 && map1.a[y][x + 1] == 0)
			{
				x += step;
				if (map1.a[y][x - 1] == 100 + order)
					map1.a[y][x - 1] = 0;map1.a[y][x] = 100 + order;
			}

			
			break;

		}
		/*map1.a[y][x] = -1;*/
	}
	/*map_update(map1);*/

}

director enemy::enemy_director(int _x, int _y)
{
	srand(time(0));
	int r = rand()%2;
	if (x > _x)
	{
		if (y >= _y)		//目标在左上
		{
			if (r ==1)
			{
				dtor = UP;
				return UP;
			}
			else
			{
				dtor = LEFT;
				return LEFT;
			}
		}
		else              //目标在左下
		{
			if (r ==1)
			{
				dtor = DOWN;
				return DOWN;
			}
			
			else
			{
				dtor = LEFT;
				return LEFT;
			}
		}
	}
	//else if (x==_x)
	//{
	//	if (y > _y)		//目标在左上
	//	{
	//		
	//			dtor = UP;
	//			return UP;
	//	
	//	}
	//	else              //目标在左下
	//	{
	//	
	//			dtor = DOWN;
	//			return DOWN;
	//	}
	//}
	else
	{
		if (y > _y)		//目标在右上
		{
			if (r ==1)
			{
				dtor = UP;
				return UP;
			}
			else
			{
				dtor = RIGHT;
				return RIGHT;
			}
		}
		/*else if (y == _y)
		{
			
				dtor = RIGHT;
				return RIGHT;
			
		}*/
		else              //目标在右下
		{
			if (r ==1)
			{
				dtor = DOWN;
				return DOWN;
			}
				
			else
			{
				dtor = RIGHT;
				return RIGHT;
			}
		}
	}
}

void enemy::map_bomb(bomb& bomb1, map& map1)
{
	
		if (exist_flag==1)
		{
			/*bomb1.status=true;*/
			if (!bomb1.bomb_start && !bomb1.fire_start && !bomb1.placed_start)
				bomb1.bomb_start = true;
			if (bomb1.num <= 2)
				bomb1.num++;
			/*cout << "num:" << bomb1.num << endl;*/
			if (bomb1.num == 1)
			{
				bomb1._x = x;
				bomb1._y = y;
			}
		}

	bomb1.bomb_rg(map1, x, y,0);
}