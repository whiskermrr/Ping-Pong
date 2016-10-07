#pragma once
#include "state.h"
#include <Windows.h>


class playMenu :
	public State
{
public:

	playMenu();
	void Initiate(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:

	sf::Font* font;
	sf::Text* title;
	sf::Text* singlePlayer;
	sf::Text* multiPlayer;
	sf::Text* back;

	int selected;
	int titleSize;
	int charSize;

	bool upKey;
	bool downKey;
};

