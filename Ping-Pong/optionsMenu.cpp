#include "optionsMenu.h"


optionsMenu::optionsMenu()
{
}


void optionsMenu::Initiate(sf::RenderWindow* window)
{
	this->selected = 1;
	this->selectedBotDifficult = 1;
	this->selectedBotDifficult = 1;
	this->upKey = false;
	this->downKey = true;
	this->leftBotKey = false;
	this->rightBotKey = true;
	this->leftBallKey = false;
	this->rightBallKey = true;
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

	this->botDifficult = new sf::Text();
	this->botDifficult->setFont(*this->font);
	this->botDifficult->setCharacterSize(charSize);
	this->botDifficult->setOrigin(this->botDifficult->getGlobalBounds().width / 2, this->botDifficult->getGlobalBounds().height / 2);
	this->botDifficult->setPosition(window->getSize().x / 4, window->getSize().y / 2);
	this->botDifficult->setString("Bot Defficult: EASY");

	this->ballDifficult = new sf::Text();
	this->ballDifficult->setFont(*this->font);
	this->ballDifficult->setCharacterSize(charSize);
	this->ballDifficult->setOrigin(this->ballDifficult->getGlobalBounds().width / 2, this->ballDifficult->getGlobalBounds().height / 2);
	this->ballDifficult->setPosition(window->getSize().x / 4, window->getSize().y / 2 + 70);
	this->ballDifficult->setString("Ball Defficult: EASY");

	this->back = new sf::Text();
	this->back->setFont(*this->font);
	this->back->setCharacterSize(charSize);
	this->back->setOrigin(this->back->getGlobalBounds().width / 2, this->back->getGlobalBounds().height / 2);
	this->back->setPosition(window->getSize().x / 4, window->getSize().y / 2 + 140);
	this->back->setString("Back");
}


void optionsMenu::Render(sf::RenderWindow* window)
{
	this->title->setColor(sf::Color::White);
	this->botDifficult->setColor(sf::Color::White);
	this->ballDifficult->setColor(sf::Color::White);
	this->back->setColor(sf::Color::White);


	switch (this->selectedBallDifficult)
	{
	case 1:
		this->ballDifficult->setString("Ball Defficult: EASY");
		ballSpeedX = 7.6f;
		ballSpeedY = 7.6f;
		this->leftBallKey = false;
		break;

	case 2:
		this->ballDifficult->setString("Ball Defficult: MEDIUM");
		ballSpeedX = 8.1f;
		ballSpeedY = 8.1f;
		this->leftBallKey = true;
		this->rightBallKey = true;
		break;

	case 3:
		this->ballDifficult->setString("Ball Defficult: HARD");
		ballSpeedX = 11.6f;
		ballSpeedY = 11.6f;
		this->rightBallKey = false;
		break;

	default:
		break;
	}

	switch (this->selectedBotDifficult)
	{
	case 1:
		this->botDifficult->setString("Bot Defficult: EASY");
		this->leftBotKey = false;
		break;

	case 2:
		this->botDifficult->setString("Bot Defficult: MEDIUM");
		this->leftBotKey = true;
		this->rightBotKey = true;
		break;

	case 3:
		this->botDifficult->setString("Bot Defficult: HARD");
		this->rightBotKey = false;
		break;

	default:
		break;
	}

	switch (this->selected)
	{
	case 1:
		this->botDifficult->setColor(sf::Color::Red);
		this->upKey = false;
		break;

	case 2:
		this->ballDifficult->setColor(sf::Color::Red);
		this->upKey = true;
		this->downKey = true;
		break;

	case 3:
		this->back->setColor(sf::Color::Red);
		this->downKey = false;
		break;

	default:
		break;
	}

	window->draw(*this->title);
	window->draw(*this->botDifficult);
	window->draw(*this->ballDifficult);
	window->draw(*this->back);

}

void optionsMenu::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && upKey)
	{
		selected -= 1;
		Sleep(200);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && downKey)
	{
		selected += 1;
		Sleep(200);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && selected == 1 && rightBotKey)
	{
		selectedBotDifficult += 1;
		Sleep(200);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && selected == 1 && leftBotKey)
	{
		selectedBotDifficult -= 1;
		Sleep(200);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && selected == 2 && rightBallKey)
	{
		selectedBallDifficult += 1;
		Sleep(200);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && selected == 2 && leftBallKey)
	{
		selectedBallDifficult -= 1;
		Sleep(200);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		switch (this->selected)
		{
		case 1:
			break;

		case 2:
			break;

		case 3:
			Sleep(200);
			mainState.setState(new mainMenu());
		}
	}

}

void optionsMenu::Destroy(sf::RenderWindow* window)
{
	delete this->font;
	delete this->title;
	delete this->back;
	delete this->botDifficult;
	delete this->ballDifficult;
}