#include <iostream>

#include "Entity.hpp"

Entity::Entity(const sf::Vector2f& Position, const sf::Vector2f& Size)
{
    EntityRect.setPosition(Position);
    EntityRect.setSize(Size);
    EntityAnimation.AnimTexture = nullptr;
}

void Entity::initEntityAnim(const std::string& TextureFileName)
{
    EntityAnimation.AnimTexture = ResourceManager::Acquire(TextureFileName); 
    EntityRect.setTexture(EntityAnimation.AnimTexture.get());
    
    EntityAnimation.setFrameLimit(TextureFileName, static_cast< int >(EntityRect.getSize().x));
}

void Entity::moveEntity(const float& DeltaTime, const sf::Vector2f& Direction, const float& SpeedFactor)
{
    EntityRect.moveRect(DeltaTime, Direction, SpeedFactor);
}

void Entity::EntityAnimate(const Actions& Action)
{
    EntityAnimation.Animate(EntityRect, Action);
}