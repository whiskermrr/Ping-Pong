#include "CountingDown.h"


CountingDown::CountingDown(sf::Font &font) : sf::Text("3", font, 120)
{
	this->counter = 3;
	this->setFillColor(sf::Color(128, 128, 128));
	this->setPosition(sf::Vector2f(600, 300));
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
}

void CountingDown::setCounter(int counter)
{
	this->counter = counter;
}

int CountingDown::getCounter()
{
	return this->counter;
}

void CountingDown::Update()
{
	if (this->counter == -1)
	{
		this->setString("START!");
	}

	else
		this->setString(std::to_string(counter));

	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
}

