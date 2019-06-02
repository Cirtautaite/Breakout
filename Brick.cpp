#include "Brick.h"

Brick::Brick(int n, int h, int w)
{
	for (int i = 0; i < n; i++)
	{
		Bh.push_back(h);
		Bw.push_back (w);
	}
	//std::cout << "FFFFF  " << std::endl;
}

Brick::~Brick()
{
}