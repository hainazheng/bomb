#pragma once
#include<iostream>
#include<graphics.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>




//debug 2024.8.24 ����������ض��� ���Ӻ󴴽�������������壩
//ͷ�ļ��Ͷ������ ��ֹ��������
class player;		//�ļ��໥������ǰ���������ļ�֪�����������
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
//������ͼ
class map
{
public:
	map_wh map_wh;
	IMAGE MAP;
	map();
	map(int map_1x, int map_1y);
	/*vector<vector<int>> a=NULL;*/			//ָ��һ����ά����
	void draw_rec();
	int a[40][80] = { 0 };							//[y][x] ռ������ڴ� �Ż����ȿ���
	void map_init(int standard=8);
	/*player* pl=NULL;*/
	player* pl;			//�Ӻ󴴽�
	void joinplayer(player& p1);			//����Ҽ���������������Ӷ�����
	~map();
	int seed=0;				//�������������
	void setseed(int n);
	enemy* em;
	int max_em=10;
	void joinenemy(enemy& en,int n);
};


