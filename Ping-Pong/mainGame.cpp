#include "mainGame.h"


void mainGame::Initiate(sf::RenderWindow* window)
{
	this->font = new sf::Font();
	this->font->loadFromFile("resources/arial.ttf");

	this->playerOne = new Player(1);
	this->playerOne->setPosition(130, window->getSize().y / 2);

	this->playerTwo = new Player(2);
	this->playerTwo->setPosition(window->getSize().x - 130, window->getSize().y / 2);

}

void mainGame::Render(sf::RenderWindow* window)
{
	window->draw(*this->playerOne);
	window->draw(*this->playerTwo);
}

void mainGame::Update(sf::RenderWindow* window)
{
	this->playerOne->Update();
	this->playerTwo->Update();
}

void mainGame::Destroy(sf::RenderWindow* window)
{
	delete this->font;
	delete this->playerOne;
	delete this->playerTwo;
}
