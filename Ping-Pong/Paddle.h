#pragma once
#include "Entity.h"


class Paddle :
	public Entity
{
public:

	int objectNumber;
	bool canMoveUp;
	bool canMoveDown;
};