#include<iostream>
#include<graphics.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#include"map.h"
#include"player.h"
#include"enemy.h"

//debug 2024.8.25 map_wh类构造函数出错
//进度2024.8.24 实现类的互相包含 实现人物的碰撞检测和移动四种动作的图片加载和实现

//void map_draw()
//{
//	
//	SetWorkingImage(&a.MAP);
//	loadimage(&a.MAP, _T("C:\\Users\\84454\\Desktop\\c\\动作素材\\map1.png"),map_x,map_y);
//	putimage(0, 0, &a.MAP);
//};

map::map() :MAP(map_wh.map_x * 25, map_wh.map_y * 25) 
{
	
	pl = new player;
	em = new enemy;
};
map::map(int map_1x, int map_1y) :MAP(map_1x, map_1y), map_wh(map_1x / 25, map_1y / 25) 
{

	pl = new player;
	em = new enemy;
}

void map::joinplayer(player& p1)		//引用player可以直接加在map对象中 相当于获取到了玩家句柄
{
	delete pl;
	pl = &p1;			//加入玩家
	
}
void map::joinenemy(enemy& en,int n)
{
	delete em;
	em = &en;			//加入敌人
	max_em = n;
}
map::~map()
{
	delete pl;
}

void map::draw_rec()			//绘制方块
{

	/*map_init();*/
	/*BeginBatchDraw();*/
	SetWorkingImage(&MAP);

	//加载图片到各自的实例上


	//绘制地面
	IMAGE floor;
	loadimage(&floor, _T("F:\\sucai\\map4.png"), 250, 500);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 8; j++)
		{
			putimage(j * 250, i * 500, &floor);
		}

	IMAGE b;
	loadimage(&b, _T("C:\\Users\\84454\\Desktop\\c\\动作素材\\map2.png"), 25, 25);

	//加载不可破坏的墙图片 
	IMAGE wall;
	loadimage(&wall, _T("F:\\sucai\\wall5.jpg"), 25, 25);
	IMAGE wall1;
	loadimage(&wall1, _T("F:\\sucai\\wall6.jpg"), 25, 25);
	//加载不可破坏的墙图片
	IMAGE wall2;
	loadimage(&wall2, _T("F:\\sucai\\wall4.jpg"), 25, 25);
	IMAGE wall3;
	loadimage(&wall3, _T("F:\\sucai\\wall7.jpg"), 25, 25);

	IMAGE player1[4];
	loadimage(&player1[0], _T("F:\\sucai\\人物up-1.jpg"), 25, 25);
	loadimage(&player1[1], _T("F:\\sucai\\人物1-2.jpg"), 25, 25);		//人物向下图标
	loadimage(&player1[2], _T("F:\\sucai\\人物left-1.jpg"));
	loadimage(&player1[3], _T("F:\\sucai\\人物right-1.jpg"), 25, 25);
	IMAGE player1_mask[4];													//人物掩图
	loadimage(&player1_mask[0], _T("F:\\sucai\\人物up_mask.jpg"),25,25);
	loadimage(&player1_mask[1], _T("F:\\sucai\\人物1-1.jpg"), 25, 25);
	loadimage(&player1_mask[2], _T("F:\\sucai\\人物left_mask.jpg"));
	loadimage(&player1_mask[3], _T("F:\\sucai\\人物right_mask.jpg"), 25, 25);

	IMAGE bomb;
	loadimage(&bomb, _T("F:\\sucai\\bomb1.jpg"), 25, 25);
	IMAGE bomb_mask;
	loadimage(&bomb_mask, _T("F:\\sucai\\bomb1_mask.jpg"), 25, 25);

	IMAGE FIRE;
	loadimage(&FIRE, _T("F:\\sucai\\爆炸.jpg"), 25, 25);
	//加载敌人图片
	IMAGE enemy[4];
	loadimage(&enemy[0], _T("F:\\sucai\\enemy1_up.jpg"), 25, 25);
	loadimage(&enemy[1], _T("F:\\sucai\\enemy1_down.jpg"), 25, 25);
	loadimage(&enemy[2], _T("F:\\sucai\\enemy1_left.jpg"), 25, 25);
	loadimage(&enemy[3], _T("F:\\sucai\\enemy1_right.jpg"), 25, 25);
	IMAGE enemy_mask[4];
	loadimage(&enemy_mask[0], _T("F:\\sucai\\enemy1_up_mask.jpg"), 25, 25);
	loadimage(&enemy_mask[1], _T("F:\\sucai\\enemy1_down_mask.jpg"), 25, 25);
	loadimage(&enemy_mask[2], _T("F:\\sucai\\enemy1_left_mask.jpg"), 25, 25);
	loadimage(&enemy_mask[3], _T("F:\\sucai\\enemy1_right_mask.jpg"), 25, 25);

	//绘制图像到地图实例上
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (a[i][j] == 0)
			{

				/*putimage(j * 20, i * 20, &b);*/
				/*setbkcolor(WHITE);
				setbkmode(TRANSPARENT);*/
				/*if(i<39&&j<79)
				solidroundrect(j * 24, i * 24, (j + 1) * 24, (i + 1) * 24,15,15);
				setlinecolor(RGB(0, 0, 0));*/
				/*		setlinestyle(PS_SOLID,1);
						if (j == 1)
							line(j * 25, i * 25, 79 * 25, i * 25);
						if (i == 1)
							line(j * 25, i * 25, j * 25, 79 * 25);*/
			}
			if (a[i][j] == 1)
			{
				//优化地图显示 3d显示
				if (i > 0 && a[i - 1][j] == 1)
				{
					putimage(j * 25, (i - 1) * 25, &wall1);
				}
				if (i > 0 && a[i - 1][j] == 2)
				{
					putimage(j * 25, (i - 1) * 25, &wall3);
				}

				putimage(j * 25, i * 25, &wall);
			}
			if (a[i][j] == 2)
			{
				//优化地图显示 3d显示
				if (i > 0 && a[i - 1][j] == 2)
				{
					putimage(j * 25, (i - 1) * 25, &wall3);
				}
				if (i > 0 && a[i - 1][j] == 1)
				{
					putimage(j * 25, (i - 1) * 25, &wall1);
				}

				putimage(j * 25, i * 25, &wall2);
			}
			
			
			if (a[i][j] == -1)
			{
				if (pl != NULL)
				{
					putimage(j * 25, i * 25, 25,25,&player1_mask[(*pl).dtor],0,0, SRCAND);
					putimage(j * 25, i * 25, 25, 25, &player1[(*pl).dtor], 0, 0, SRCPAINT);
				}
				/*drawAlpha(&player1, j * 25, i * 25);*/
			}
			if (a[i][j] == 4)
			{
				
					putimage(j * 25, i * 25, 25, 25, &bomb_mask, 0, 0, SRCAND);
					putimage(j * 25, i * 25, 25, 25, &bomb, 0, 0, SRCPAINT);
				
			}
			if (a[i][j] == 3)
			{
				/*cout << j<<' '<<i << endl;*/
				putimage(j * 25, i * 25, 25, 25, &FIRE, 0, 0 );
				
				
			}
			for (int k = 1; k <= max_em; k++)
			{
				if (a[i][j] == 100 + k)
				{
					/*cout << j<<' '<<i << endl;*/
					putimage(j * 25, i * 25, 25, 25, &enemy_mask[em[k-1].dtor], 0, 0, SRCAND);
					putimage(j * 25, i * 25, 25, 25, &enemy[em [ k - 1].dtor], 0, 0, SRCPAINT);
				}
			}
		}

	}
	/*FlushBatchDraw();*/
}



//不可破环的墙—1 可破坏的墙—2 玩家— -1 地面—0  
void map::map_init(int standard)
{
	srand(seed);


	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			//边缘墙壁
			if (i == 0 || j == 0 || i == 39 || j == 79)
				a[i][j] = 1;

		}

	}
	//随机生成不可破环墙壁
	for (int i = 0; i < (map_wh.map_x * map_wh.map_y) / standard; i++)
	{
		a[rand() % (map_wh.map_y - 2) + 1][rand() % (map_wh.map_x - 2) + 1] = 1;
	}
	//随机生成可破坏的墙壁
	for (int i = 0; i < (map_wh.map_x * map_wh.map_y) / standard; i++)
	{
		int x1 = rand() % (map_wh.map_y - 2) + 1;
		int y1 = rand() % (map_wh.map_x - 2) + 1;
		
		while( a[x1][y1] == 1)
		{
			x1 = rand() % (map_wh.map_y - 2) + 1;
			y1 = rand() % (map_wh.map_x - 2) + 1;
		}
		if(a[x1 ][y1]!=1)
			a[x1][y1] = 2;
	}
	for (int i = 1; i < 38; i++)
	{
		for (int j = 1; j < 78; j++)
		{
			//判断条件只要形成L型就删掉一个成I型 田字形就不删除
			if (a[i][j] == 1)
			{
				/*if (a[i][j + 1] == 1 && a[i][j + 2] == 1)
				{
					a[i][j + 1] = 0;

				}*/

				if (a[i][j + 1] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] != 1)
				{
					a[i][j + 1] = 0;

				}
				if (a[i][j + 1] == 1 && a[i + 1][j + 1] == 1 && a[i + 1][j] != 1)
				{
					a[i][j] = 0;
				}
				/*	if (a[i + 1][j] == 1 && a[i + 2][j] == 1)
						a[i + 1][j] = 0;*/
				if (a[i + 1][j] == 1 && a[i + 1][j + 1] == 1 && a[i][j + 1] != 1)
					a[i][j] = 0;
			}
		}

	}

}

void map::setseed(int n)
{
	seed = n;
}

//void drawAlpha(IMAGE* picture, int  picture_x, int picture_y) //x为载入图片的X坐标，y为Y坐标
//{
//	// 变量初始化
//	DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
//	DWORD* draw = GetImageBuffer();
//	DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
//	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
//	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
//	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
//	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
//	int dstX = 0;    //在显存里像素的角标
//
//	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
//	for (int iy = 0; iy < picture_height; iy++)
//	{
//		for (int ix = 0; ix < picture_width; ix++)
//		{
//			int srcX = ix + iy * picture_width; //在显存里像素的角标
//			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
//			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
//			int sg = ((src[srcX] & 0xff00) >> 8);   //G
//			int sb = src[srcX] & 0xff;              //B
//			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
//			{
//				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
//				int dr = ((dst[dstX] & 0xff0000) >> 16);
//				int dg = ((dst[dstX] & 0xff00) >> 8);
//				int db = dst[dstX] & 0xff;
//				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
//					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
//					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
//			}
//		}
//	}
//}
//