#include <iostream>

#include "Entity.hpp"

Entity::Entity(sf::Vector2f Position, sf::Vector2f Size)
{
    EntityRect.setPosition(Position);
    EntityRect.setSize(Size);
    EntityAnimation.AnimTexture = nullptr;
}

void Entity::initEntityAnim(const std::string& TextureFileName)
{
    EntityAnimation.AnimTexture = ResourceManager::Acquire(TextureFileName); 
    EntityRect.setTexture(EntityAnimation.AnimTexture.get());
    
    EntityAnimation.setFrameLimit(TextureFileName, static_cast<int>(EntityRect.getSize().x));
}

void Entity::moveEntity(float DeltaTime, sf::Vector2f Direction)
{
    EntityRect.moveRect(DeltaTime, Direction);
}

void Entity::EntityAnimate(Actions Action)
{
    EntityAnimation.Animate(EntityRect, Action);
}