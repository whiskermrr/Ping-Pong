#pragma once

#include "State.h"

class gameState
{
public:

	gameState()
	{
		this->state = NULL;
	}

	void Update()
	{
		if (this->state != NULL)
		{
			this->state->Update();
		}
	}

	void Render()
	{
		if (this->state != NULL)
		{
			this->state->Render();
		}
	}

	void setWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}

	void setState(State* state)
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}

		this->state = state;

		if (this->state != NULL)
		{
			this->state->Initiate(this->window);
		}
	}

	~gameState()
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
	}

private:

	sf::RenderWindow* window;
	State* state;
};