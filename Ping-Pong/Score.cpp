#include "Score.h"


Score::Score(sf::Font &font)
{
	this->value = 0;
	this->setCharacterSize(80);
	this->setFont(font);
	this->setColor(sf::Color(128, 128, 128));
	this->setString(std::to_string(this->value));
}

void Score::AddPoint()
{
	this->value += 1;
}

void Score::Update()
{
	this->setString(std::to_string(this->value));
}

