#include "mainMenu.h"


mainMenu::mainMenu()
{
}

void mainMenu::Initiate(sf::RenderWindow* window)
{
	this->charSize = 60;
	this->titleSize = 120;
	this->selected = 1;
	this->upKey = false;
	this->downKey = true;

	this->font = new sf::Font();
	this->font->loadFromFile("resources/font.ttf");
	
	this->title = new sf::Text();
	this->title->setFont(*this->font);
	this->title->setCharacterSize(titleSize);
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->title->setPosition(window->getSize().x / 4, window->getSize().y / 2 - 250);
	this->title->setString("Ping-Pong");

	this->play = new sf::Text();
	this->play->setFont(*this->font);
	this->play->setCharacterSize(charSize);
	this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
	this->play->setPosition(window->getSize().x / 4, window->getSize().y / 2);
	this->play->setString("Play");

	this->options = new sf::Text();
	this->options->setFont(*this->font);
	this->options->setCharacterSize(charSize);
	this->options->setOrigin(this->options->getGlobalBounds().width / 2, this->options->getGlobalBounds().height / 2);
	this->options->setPosition(window->getSize().x / 4, window->getSize().y / 2 + 70);
	this->options->setString("Options");

	this->quit = new sf::Text();
	this->quit->setFont(*this->font);
	this->quit->setCharacterSize(charSize);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 4, window->getSize().y / 2 + 140);
	this->quit->setString("Quit");
}

void mainMenu::Render(sf::RenderWindow* window)
{
	this->title->setColor(sf::Color::White);
	this->play->setColor(sf::Color::White);
	this->options->setColor(sf::Color::White);
	this->quit->setColor(sf::Color::White);

	switch (this->selected)
	{
	case 1:
		this->play->setColor(sf::Color::Red);
		this->upKey = false;
		break;

	case 2:
		this->options->setColor(sf::Color::Red);
		this->upKey = true;
		this->downKey = true;
		break;

	case 3:
		this->quit->setColor(sf::Color::Red);
		this->downKey = false;
		break;

	default:
		break;
	}

	window->draw(*this->title);
	window->draw(*this->play);
	window->draw(*this->options);
	window->draw(*this->quit);
}

void mainMenu::Update(sf::RenderWindow* window)
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
			mainState.setState(new playMenu());
			break;

		case 2:
			Sleep(200);
			mainState.setState(new optionsMenu());
			break;

		case 3:
			Sleep(200);
			gameOver = true;
			break;

		default:
			break;
		}
	}

}

void mainMenu::Destroy(sf::RenderWindow* window)
{
	delete this->font;
	delete this->title;
	delete this->play;
	delete this->options;
	delete this->quit;
}