#pragma once
#include<iostream>
#include<graphics.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
//#include"map.h"
#include"Ѫ��.h"
#include<Windows.h>


enum director
{
	UP,DOWN,LEFT,RIGHT
};
class map;
class bomb;
//��ҳ����ڵ�ͼ��λ��
class player
{
public:
	int x;
	int y;
	bool exist_flag = 1;
	bool blood_flag = 1;
	
	void move(int step,map& map1);
	player() :x(2), y(2) {};		//Ĭ�Ͽ�ʼ��(2,2) (50,50)
	player(int _x, int _y) :x(_x), y(_y) {};
	void init(map& map1);			//�ڵ�ͼ���������λ��3*3λ�ò��ܳ��ַ���
	void drawblood(bool _flag);
	director dtor= DOWN;				//Ĭ�Ͽ�ʼ�����ϵ�
	void map_update(map& map1);				//map���Ա�������ݸ���
	void map_bomb(bomb &bomb1,map& map1);
private:
	void move(int step);
};

