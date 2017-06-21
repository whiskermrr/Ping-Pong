#include "mainGame.h"


void mainGame::Initiate(sf::RenderWindow* window)
{
	this->background = new Background();
	this->background->setPosition(sf::Vector2f(0, 0));

	this->font = new sf::Font();
	this->font->loadFromFile("resources/arial.ttf");

	this->counter = new CountingDown(*this->font);

	this->scorePlayerOne = new Score(*this->font);
	this->scorePlayerOne->setPosition((window->getSize().x / 2) - 80, window->getSize().y / 16);

	this->scorePlayerTwo = new Score(*this->font);
	this->scorePlayerTwo->setPosition((window->getSize().x / 2) + 20, window->getSize().y / 16);

	this->playerOne = new Player(1);
	this->playerOne->setPosition(130, window->getSize().y / 2);

	this->playerTwo = new Player(2);
	this->playerTwo->setPosition(window->getSize().x - 130, window->getSize().y / 2);

	this->ball = new Ball(playerOne, playerTwo, scorePlayerOne, scorePlayerTwo);
	this->ball->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void mainGame::Render(sf::RenderWindow* window)
{
	window->draw(*this->background);
	window->draw(*this->playerOne);
	window->draw(*this->playerTwo);
	window->draw(*this->ball);
	window->draw(*this->scorePlayerOne);
	window->draw(*this->scorePlayerTwo);

	if (reset && !gameOver)
		this->Reset(window);
}

void mainGame::Update(sf::RenderWindow* window)
{
	this->background->Update();
	this->playerOne->Update();
	this->playerTwo->Update();
	this->ball->Update();
	this->scorePlayerOne->Update();
	this->scorePlayerTwo->Update();
}

void mainGame::Destroy(sf::RenderWindow* window)
{
	delete this->font;
	delete this->playerOne;
	delete this->playerTwo;
	delete this->ball;
	delete this->background;
	delete this->scorePlayerOne;
	delete this->scorePlayerTwo;
	delete this->counter;
}

void mainGame::Reset(sf::RenderWindow* window)
{
	this->playerOne->setPosition(130, window->getSize().y / 2);
	this->playerTwo->setPosition(window->getSize().x - 130, window->getSize().y / 2);
	this->ball->setPosition(window->getSize().x / 2, window->getSize().y / 2);
	this->ball->velocity = sf::Vector2f(ballSpeedX, ballSpeedY);

	while (this->counter->getCounter() >= -1)
	{

		window->clear(sf::Color::Black);

		this->counter->Update();

		window->draw(*this->background);
		window->draw(*this->playerOne);
		window->draw(*this->playerTwo);
		window->draw(*this->ball);
		window->draw(*this->scorePlayerOne);
		window->draw(*this->scorePlayerTwo);
		window->draw(*this->counter);

		window->display();

		this->counter->setCounter(this->counter->getCounter() - 1);
		Sleep(999);
	}

	this->counter->setCounter(3);
	reset = false;
}
