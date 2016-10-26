#pragma once
#include "state.h"
#include "playMenu.h"
#include "gameState.h"
#include "optionsMenu.h"


class mainMenu :
	public State
{
public:
	
	mainMenu();
	void Initiate(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:

	sf::Font* font;
	sf::Text* title;
	sf::Text* play;
	sf::Text* options;
	sf::Text* quit;

	int selected;
	int titleSize;
	int charSize;

	bool upKey;
	bool downKey;
};

extern float ballSpeedY;
extern float ballSpeedX;
extern bool gameExit;

