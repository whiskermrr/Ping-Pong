#include "Score.h"


Score::Score(sf::Font &font)
{
	this->value = 0;
	this->setCharacterSize(80);
	this->setFont(font);
	this->setFillColor(sf::Color(128, 128, 128));
	this->setString(std::to_string(this->value));
}

void Score::AddPoint()
{
	this->value += 1;
}

int Score::getScore()
{
	return this->value;
}

void Score::Update()
{
	this->setString(std::to_string(this->value));
}

