#pragma once
#include<iostream>
#include<graphics.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
//#include"map.h"
#include"Ѫ��.h"
#include<Windows.h>
#include"player.h"


class map;
class bomb;
//��ҳ����ڵ�ͼ��λ��
class enemy
{
public:
	int x;
	int y;
	bool exist_flag = 1;
	bool blood_flag = 1;
	int order = 1;		//���

	void move(int step, map& map1);
	enemy();		//�������λ��
	enemy(int _x, int _y) :x(_x), y(_y) {};
	void init(map& map1);			//�ڵ�ͼ���������λ��3*3λ�ò��ܳ��ַ���
	/*void drawblood(bool _flag);*/
	director dtor = RIGHT;				//Ĭ�Ͽ�ʼ�����ϵ�
	/*void map_update(map& map1);		*/		//map���Ա�������ݸ���
	void map_bomb(bomb& bomb1, map& map1);
	director enemy_director(int _x,int _y);		//ȷ�ϵ��˷��� �㷨1 ���ж�
	void enemy_rand();
};