#include "gameState.h"
#include "mainMenu.h"

gameState mainState;
bool gameOver = false;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 600), "mrr");

	window.setFramerateLimit(30);

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			mainState.~gameState();
		}

		if (gameOver)
		{
			mainState.~gameState();
		}

		window.clear(sf::Color::Black);
		mainState.Update();
		mainState.Render();

		window.display();
	}

	return 0;
}