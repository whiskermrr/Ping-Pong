#pragma once
#include "state.h"
#include "Player.h"
#include "Ball.h"
#include "Background.h"
#include "Score.h"
#include "CountingDown.h"
#include "PlayerAI.h"


class mainGame :
	public State
{
public:
	
	void Initiate(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
	void Reset(sf::RenderWindow* window);

private:

	sf::Font* font;

	Player* playerOne;
	PlayerAI* playerTwo;
	Ball* ball;
	Background* background;
	Score* scorePlayerOne;
	Score* scorePlayerTwo;
	CountingDown* counter;
	Ball* ball2;
};

extern bool reset;
extern int typeOfGame;
