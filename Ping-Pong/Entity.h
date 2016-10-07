#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite
{
public:

	Entity();
	void LoadTexture();
	void Update();
	bool CheckCollision(Entity* gameObject);
	void Destroy();

private:

	sf::Texture* texture;

public:

	sf::Vector2f velocity;

};