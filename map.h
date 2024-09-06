#pragma once
#include<iostream>
#include<graphics.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>




//debug 2024.8.24 类包含出现重定义 用延后创建解决（声明定义）
//头文件和定义分离 防止多重声明
class player;		//文件相互包含提前声明，让文件知道有这个类型
class enemy;
//#include"player.h"
const int map_x = 2000;
const int map_y = 1000;
const int scr_w = 1000;
const int scr_h = 500;
using namespace std;
//void drawAlpha(IMAGE* picture, int  picture_x, int picture_y);
class map_wh
{
public:
	int map_x = 80;
	int map_y = 40;
	map_wh() :map_x(80), map_y(40) {};
	map_wh(int map_w1, int map_h1) :map_x(map_w1), map_y(map_h1) {};
};
//创建地图
class map
{
public:
	map_wh map_wh;
	IMAGE MAP;
	map();
	map(int map_1x, int map_1y);
	/*vector<vector<int>> a=NULL;*/			//指向一个二维数组
	void draw_rec();
	int a[40][80] = { 0 };							//[y][x] 占据最大内存 优化优先考虑
	void map_init(int standard=8);
	/*player* pl=NULL;*/
	player* pl;			//延后创建
	void joinplayer(player& p1);			//把玩家加入容器，可以添加多个玩家
	~map();
	int seed=0;				//设置随机数种子
	void setseed(int n);
	enemy* em;
	int max_em=10;
	void joinenemy(enemy& en,int n);
};


