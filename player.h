#pragma once
#include<iostream>
#include<graphics.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
//#include"map.h"
#include"血条.h"
#include<Windows.h>


enum director
{
	UP,DOWN,LEFT,RIGHT
};
class map;
class bomb;
//玩家出现在地图的位置
class player
{
public:
	int x;
	int y;
	bool exist_flag = 1;
	bool blood_flag = 1;
	
	void move(int step,map& map1);
	player() :x(2), y(2) {};		//默认开始在(2,2) (50,50)
	player(int _x, int _y) :x(_x), y(_y) {};
	void init(map& map1);			//在地图上人物出生位置3*3位置不能出现方块
	void drawblood(bool _flag);
	director dtor= DOWN;				//默认开始是向上的
	void map_update(map& map1);				//map类成员数组数据更新
	void map_bomb(bomb &bomb1,map& map1);
private:
	void move(int step);
};

