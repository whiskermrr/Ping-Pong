#include "Ball.h"


Ball::Ball(Paddle* playerOne, Paddle* playerTwo, Score* scorePlayerOne, Score* scorePlayerTwo)
{
	this->playerOne = playerOne;
	this->playerTwo = playerTwo;
	this->scorePlayerOne = scorePlayerOne;
	this->scorePlayerTwo = scorePlayerTwo;

	srand(time(NULL));
	int x;
	int y;

	x = (rand() % 2 == 0) ? -1 : 1;
	y = (rand() % 2 == 0) ? -1 : 1;

	this->velocity.y = x * ballSpeedY;
	this->velocity.x = y * ballSpeedX;

	this->LoadTexture("ball2.png");

	this->setScale(30 / this->getGlobalBounds().width, 30 / this->getGlobalBounds().height);
}

void Ball::Update()
{
	//ball goes down
	if (this->velocity.y > 0)
	{

		//collision with playerTwo
		if (this->velocity.x > 0 && this->CheckCollision(this->playerTwo))
		{
			if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerTwo->getPosition().y &&
				this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerTwo->getPosition().y + 40)
			{
				this->velocity.y = 1.7f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerTwo->getPosition().y + 40 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerTwo->getPosition().y + 80)
			{
				this->velocity.y = 1.0f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerTwo->getPosition().y + 80 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerTwo->getPosition().y + 120)
			{
				this->velocity.y =  0.7f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerTwo->getPosition().y + 120 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerTwo->getPosition().y + 160)
			{
				this->velocity.y = 1.0f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerTwo->getPosition().y + 160 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 <= this->playerTwo->getPosition().y + 200)
			{
				this->velocity.y = 1.7f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}
		}

		//collision with playerOne
		else if (this->velocity.x < 0 && this->CheckCollision(this->playerOne))
		{
			if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerOne->getPosition().y &&
				this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerOne->getPosition().y + 40)
			{
				this->velocity.y = 1.7f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerOne->getPosition().y + 40 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerOne->getPosition().y + 80)
			{
				this->velocity.y = 1.0f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerOne->getPosition().y + 80 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerOne->getPosition().y + 120)
			{
				this->velocity.y = 0.7f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerOne->getPosition().y + 120 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerOne->getPosition().y + 160)
			{
				this->velocity.y = 1.0f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerOne->getPosition().y + 160 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 <= this->playerOne->getPosition().y + 200)
			{
				this->velocity.y = 1.7f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}
		}

		else if (this->getPosition().y + this->getGlobalBounds().height >= 600)
			this->velocity.y = -this->velocity.y;
	}


	//ball goes up
	else if (this->velocity.y < 0)
	{
		//collision with player Two
		if (this->velocity.x > 0 && this->CheckCollision(this->playerTwo))
		{
			if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerTwo->getPosition().y &&
				this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerTwo->getPosition().y + 40)
			{
				this->velocity.y = -1.7f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerTwo->getPosition().y + 40 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerTwo->getPosition().y + 80)
			{
				this->velocity.y = -1.0f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerTwo->getPosition().y + 80 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerTwo->getPosition().y + 120)
			{
				this->velocity.y = -0.7f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerTwo->getPosition().y + 120 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerTwo->getPosition().y + 160)
			{
				this->velocity.y = -1.0f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerTwo->getPosition().y + 160 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 <= this->playerTwo->getPosition().y + 200)
			{
				this->velocity.y = -1.7f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}
		}

		//collision with playerOne
		else if (this->velocity.x < 0 && this->CheckCollision(this->playerOne))
		{
			if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerOne->getPosition().y &&
				this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerOne->getPosition().y + 40)
			{
				this->velocity.y = -1.7f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerOne->getPosition().y + 40 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerOne->getPosition().y + 80)
			{
				this->velocity.y = -1.0f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerOne->getPosition().y + 80 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerOne->getPosition().y + 120)
			{
				this->velocity.y = -0.7f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerOne->getPosition().y + 120 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 < this->playerOne->getPosition().y + 160)
			{
				this->velocity.y = -1.0f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}

			else if (this->getPosition().y + this->getGlobalBounds().height / 2 >= this->playerOne->getPosition().y + 160 &&
					this->getPosition().y + this->getGlobalBounds().height / 2 <= this->playerOne->getPosition().y + 200)
			{
				this->velocity.y = -1.7f * ballSpeedY;
				this->velocity.x = -this->velocity.x;
			}
		}

		else if (this->getPosition().y <= 0)
			this->velocity.y = -this->velocity.y;

	}

	if (this->getPosition().x < this->playerOne->getPosition().x - 130)
	{
		this->scorePlayerTwo->AddPoint();
		reset = true;
	}

	else if (this->getPosition().x > this->playerTwo->getPosition().x + 130)
	{
		this->scorePlayerOne->AddPoint();
		reset = true;
	}

	if (this->scorePlayerOne->getScore() > 2 || this->scorePlayerTwo->getScore() > 2)
	{
		gameOver = true;
	}

	Entity::Update();
}
