#include "playMenu.h"
#include "mainMenu.h"


playMenu::playMenu()
{
}

void playMenu::Initiate(sf::RenderWindow* window)
{
	this->selected = 1;
	this->upKey = false;
	this->downKey = true;
	this->titleSize = 120;
	this->charSize = 60;

	this->font = new sf::Font();
	this->font->loadFromFile("resources/font.ttf");

	this->title = new sf::Text();
	this->title->setFont(*this->font);
	this->title->setCharacterSize(titleSize);
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->title->setPosition(window->getSize().x / 4, window->getSize().y / 2 - 250);
	this->title->setString("Ping-Pong");

	this->singlePlayer = new sf::Text();
	this->singlePlayer->setFont(*this->font);
	this->singlePlayer->setCharacterSize(charSize);
	this->singlePlayer->setOrigin(this->singlePlayer->getGlobalBounds().width / 2, this->singlePlayer->getGlobalBounds().height / 2);
	this->singlePlayer->setPosition(window->getSize().x / 4, window->getSize().y / 2);
	this->singlePlayer->setString("Single Player");

	this->multiPlayer = new sf::Text();
	this->multiPlayer->setFont(*this->font);
	this->multiPlayer->setCharacterSize(charSize);
	this->multiPlayer->setOrigin(this->multiPlayer->getGlobalBounds().width / 2, this->multiPlayer->getGlobalBounds().height / 2);
	this->multiPlayer->setPosition(window->getSize().x / 4, window->getSize().y / 2 + 70);
	this->multiPlayer->setString("Multi Player");

	this->back = new sf::Text();
	this->back->setFont(*this->font);
	this->back->setCharacterSize(charSize);
	this->back->setOrigin(this->back->getGlobalBounds().width / 2, this->back->getGlobalBounds().height / 2);
	this->back->setPosition(window->getSize().x / 4, window->getSize().y / 2 + 140);
	this->back->setString("Back");
}


void playMenu::Render(sf::RenderWindow* window)
{
	this->title->setFillColor(sf::Color::White);
	this->singlePlayer->setFillColor(sf::Color::White);
	this->multiPlayer->setFillColor(sf::Color::White);
	this->back->setFillColor(sf::Color::White);

	switch (this->selected)
	{
	case 1:
		this->singlePlayer->setFillColor(sf::Color::Red);
		this->upKey = false;
		break;

	case 2:
		this->multiPlayer->setFillColor(sf::Color::Red);
		this->upKey = true;
		this->downKey = true;
		break;

	case 3:
		this->back->setFillColor(sf::Color::Red);
		this->downKey = false;
		break;

	default:
		break;
	}

	window->draw(*this->title);
	window->draw(*this->singlePlayer);
	window->draw(*this->multiPlayer);
	window->draw(*this->back);
}

void playMenu::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->upKey)
	{
		selected -= 1;
		Sleep(100);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->downKey)
	{
		selected += 1;
		Sleep(100);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		switch (this->selected)
		{
		case 1:
			Sleep(200);
			mainState.setState(new mainGame());
			break;

		case 2:
			break;

		case 3:
			Sleep(200);
			mainState.setState(new mainMenu());
			break;

		default:
			break;
		}
	}
}

void playMenu::Destroy(sf::RenderWindow* window)
{
	delete this->font;
	delete this->title;
	delete this->singlePlayer;
	delete this->multiPlayer;
	delete this->back;
}
