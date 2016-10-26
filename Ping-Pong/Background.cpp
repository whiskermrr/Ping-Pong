#include "Background.h"


Background::Background()
{
	this->LoadTexture("background3.png");
	this->setScale(1200 / this->getGlobalBounds().width, 600 / this->getGlobalBounds().height);
}


void Background::Update()
{

}
