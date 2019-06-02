#pragma once
#define NORMAL 10
#define BIG 5
#define SMALL 15
#include <vector>
#include <iostream>

class Brick
{
public:
	Brick(int n, int h, int w);
	Brick(const Brick &b) 
	{
		for (int i = 0; i < 10; i++)
		{
			Bh.push_back(b.Bh[i]);
			Bw.push_back(b.Bw[i]);
		} 
	}
	Brick() {};
	~Brick();
	std::vector <int> Bh, Bw, Bx, By;
	//bool alive[15];
	std::vector<bool> alive;

	//std::vector <bool*>::iterator it;
};