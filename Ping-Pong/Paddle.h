#pragma once
#include "Entity.h"


class Paddle :
	public Entity
{

public:

	Paddle();
	void Update();

public:

	bool canMoveUp;
	bool canMoveDown;
};