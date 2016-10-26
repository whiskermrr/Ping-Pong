#include "gameState.h"
#include "mainMenu.h"
#include "mainGame.h"
#include "testState.h"

gameState mainState;
bool gameExit = false;
bool gameOver = false;
bool reset = false;
float ballSpeedX = 7.6f;
float ballSpeedY = 7.6f;
sf::Vector2f screenDimensions(1200, 600);

int main()
{
	sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "mrr");

	window.setFramerateLimit(60);

	mainState.setWindow(&window);
	mainState.setState(new mainMenu());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (gameOver)
		{
			mainState.setState(new mainMenu());
			gameOver = false;
		}

		window.clear(sf::Color::Black);
		mainState.Update();
		mainState.Render();

		window.display();

		if (gameExit)
		{
			window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}