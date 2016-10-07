#include "Entity.h"

Entity::Entity()
{
	this->texture = new sf::Texture();
}

void Entity::LoadTexture()
{
}

void Entity::Update()
{
	this->move(this->velocity);
}

bool Entity::CheckCollision(Entity* gameObject)
{
	return this->getGlobalBounds().intersects(gameObject->getGlobalBounds());
}

void Entity::Destroy()
{
	delete this->texture;
}