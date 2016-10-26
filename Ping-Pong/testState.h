#pragma once
#include "state.h"


class testState :
	public State
{
public:

	void Initiate(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:

};

