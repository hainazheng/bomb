#pragma once
#include<iostream>
#include<graphics.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
class wall1
{
public:
	bool de_flag = 0;			//判断物体的是否可以破坏 1可以 0不可以
	IMAGE MAP;
};


class wall2
{
	bool de_flag = 1;
	IMAGE MAP;
};
