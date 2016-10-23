#pragma once

#include "state.h"
#include "gameState.h"
#include "mainMenu.h"

enum Option{

	EASY, MEDIUM, ADVANCED
};

class optionsMenu : public State
{
public:

	optionsMenu();
	void Initiate(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:

	sf::Font* font;
	sf::Text* title;
	sf::Text* botDifficult;
	sf::Text* ballDifficult;
	sf::Text* back;

	int selected;
	int selectedBotDifficult;
	int selectedBallDifficult;
	int titleSize;
	int charSize;

	bool upKey;
	bool downKey;
	bool rightBotKey;
	bool leftBotKey;
	bool rightBallKey;
	bool leftBallKey;

};

