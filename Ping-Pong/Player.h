#pragma once
#include "Paddle.h"


class Player :
	public Paddle
{
public:
	Player(unsigned int objectNumber);
	void Update();
};

