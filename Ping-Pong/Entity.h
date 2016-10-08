#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite
{
public:

	Entity();
	void LoadTexture(std::string file);
	void Update();
	bool CheckCollision(Entity* gameObject);
	void Destroy();

private:

	sf::Texture* texture;

public:

	sf::Vector2f velocity;

};