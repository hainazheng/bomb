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
//˼�� �ж�ը����״̬ ʵ���Է��ı�ը����map��һ��������
//����Һ͵���λ�ð󶨣�һ�����¿ո񣬾�ʵ�ַ���ը��
//ͬ��λ�ò����ٷ�ը��
//һ��ը��ʵ����ըstatus�ͱ�Ϊ0ը��ʵ��
//Ѱ·�㷨ը���Զ�Ѱ�Ҳ�Ϊ1�ĵ���vector�洢����vector
class bomb
{
public:
	bomb(bool flag) :status(flag) {};
	bool status = false;				//ը��״̬
	void enable();				//����
	bomb() :status(false) {};
	void bomb_rg(map& map1,int x,int y, int sound,int max_fireend_time=5, int max_bombstart_time=3, int max_bombend_time=5);
	int rg = 2;					//ը����Χ���ֵ
	/*void search(int x,int y);	*/	//Ѱ·�㷨���Զ�Ѱ��ը�����Էŵ�λ��
	void bomb_hide(map& map1, int x, int y, int max_bomb_time = 3);
	void bomb_placed(map& map1, int x, int y, int max_bombend_time);	///����ը��
	void settime(int n=3);			//ʵ��ʱ�����  ����ʱ��
	int time=0;					//��ʱ��
	int maxtime = 3;			//ʱ��=3*sleep()
	bool fire_start = 0;		//���Ƿ���� ����
	bool bomb_start = false;
	bool placed_start = 0;
	int _x;
	int _y;
	int num = 0;
	player* a1;
	enemy* en;
	void joinplayer(player* a);		//�ж����
	void joinenemy(enemy* a,int n);
	/*void exist_pupil*/
};

