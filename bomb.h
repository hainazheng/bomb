#pragma once
#include<iostream>
#include<graphics.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

class player;
class map;
class enemy;
//思想 判断炸弹的状态 实现自发的爆炸放在map的一个格子中
//跟玩家和敌人位置绑定，一旦按下空格，就实现放下炸弹
//同个位置不能再放炸弹
//一旦炸弹实例爆炸status就变为0炸弹实例
//寻路算法炸弹自动寻找不为1的点用vector存储返回vector
class bomb
{
public:
	bomb(bool flag) :status(flag) {};
	bool status = false;				//炸弹状态
	void enable();				//开关
	bomb() :status(false) {};
	void bomb_rg(map& map1,int x,int y, int sound,int max_fireend_time=5, int max_bombstart_time=3, int max_bombend_time=5);
	int rg = 2;					//炸弹范围最大值
	/*void search(int x,int y);	*/	//寻路算法，自动寻找炸弹可以放的位置
	void bomb_hide(map& map1, int x, int y, int max_bomb_time = 3);
	void bomb_placed(map& map1, int x, int y, int max_bombend_time);	///放置炸弹
	void settime(int n=3);			//实现时间控制  设置时间
	int time=0;					//计时间
	int maxtime = 3;			//时间=3*sleep()
	bool fire_start = 0;		//火花是否出现 触发
	bool bomb_start = false;
	bool placed_start = 0;
	int _x;
	int _y;
	int num = 0;
	player* a1;
	enemy* en;
	void joinplayer(player* a);		//判断玩家
	void joinenemy(enemy* a,int n);
	/*void exist_pupil*/
};

