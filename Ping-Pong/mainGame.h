#pragma once
#include "state.h"
#include "Player.h"
#include "Ball.h"


class mainGame :
	public State
{
public:
	
	void Initiate(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:

	sf::Font* font;

	Player* playerOne;
	Player* playerTwo;
	Ball* ball;
};

