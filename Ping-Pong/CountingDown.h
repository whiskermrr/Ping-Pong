#pragma once

#include <SFML/Graphics.hpp>

class CountingDown : public sf::Text
{
public:

	CountingDown(sf::Font &font);
	void setCounter(int counter);
	int getCounter();
	void Update();

private:

	int counter;
};

