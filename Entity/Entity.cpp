#include "Entity.hpp"

Entity::Entity(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName)
{
    EntityRect.setPosition(Position);
    EntityRect.setSize(Size);
    EntityTexture = ResourceManager::Acquire(TextureFileName);
    EntityRect.setTexture(EntityTexture.get());
    EntityAnimation.setFrameLimit(static_cast<float>(EntityTexture->getSize().x), static_cast<int>(Size.x));
}

void Entity::moveEntity(float DeltaTime, sf::Vector2f Direction)
{
    EntityRect.move(Direction * (DeltaTime * static_cast<float>(EntitySpeed)));
}

void Entity::EntityAnimate(Actions Action)
{
    EntityAnimation.Animate(EntityRect, Action);
}