#include "gameState.h"
#include "mainMenu.h"
#include "mainGame.h"

gameState mainState;
bool gameOver = false;
float ballSpeedX = 7.6f;
float ballSpeedY = 7.6f;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 600), "mrr");

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

		window.clear(sf::Color::Black);
		mainState.Update();
		mainState.Render();

		window.display();

		if (gameOver)
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