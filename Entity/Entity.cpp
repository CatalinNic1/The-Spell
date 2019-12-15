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
    EntityRect.move(Direction * DeltaTime * EntitySpeed);
    EntityDirection = Direction;
}

void Entity::EntityAnimate(Actions Action)
{
    EntityAnimation.Animate(EntityRect, Action);
}

void Entity::setMovable(bool IsMovable)
{
    Movable = IsMovable;
}

bool Entity::CheckCollision(sf::FloatRect ObjectFloatRect, bool IsMovable, CollisionTypes CollisionType)
{
    if(IsMovable == true)
    {
        /// TODO: Implement collisions for moving objects
        throw std::runtime_error("Only static objects can use for now collisions");
        return false;
    }
    sf::FloatRect EntityFloatRect = EntityRect.getGlobalBounds();
    if(CollisionType == CollisionTypes::Inwards)
    {
        sf::Vector2f Difference = getInwardsCollision(EntityFloatRect, ObjectFloatRect);
        EntityRect.move(Difference);
        if(Difference != sf::Vector2f(0.f, 0.f))
            return true;
        else
            return false;
    }
    else if(CollisionType == CollisionTypes::Outwards)
    {
        sf::Vector2f Difference = getOutwardsCollision(EntityFloatRect, ObjectFloatRect);
        EntityRect.move(Difference);
        if(Difference != sf::Vector2f(0.f, 0.f))
            return true;
        else
            return false;
    }
    return false;
}

sf::Vector2f Entity::getOutwardsCollision(sf::FloatRect EntityFloatRect, sf::FloatRect ObjectFloatRect)
{
    if(ObjectFloatRect.intersects(EntityFloatRect))
    {
        if(EntityDirection == Directions::Up)
            return Axis::Vertical * (ObjectFloatRect.height + ObjectFloatRect.top - EntityFloatRect.top);
        else if(EntityDirection == Directions::Down)
            return Axis::Vertical * (ObjectFloatRect.top - (EntityFloatRect.top + EntityFloatRect.height));
        else if(EntityDirection == Directions::Left)
            return Axis::Horizontal * (ObjectFloatRect.width + ObjectFloatRect.left - EntityFloatRect.left);
        else if(EntityDirection == Directions::Right)
            return Axis::Horizontal * (ObjectFloatRect.left - (EntityFloatRect.left + EntityFloatRect.width));   
    }
    return Axis::None;
}

sf::Vector2f Entity::getInwardsCollision(sf::FloatRect EntityFloatRect, sf::FloatRect ObjectFloatRect)
{
    if(EntityFloatRect.top < ObjectFloatRect.top)
        return Axis::Vertical * (ObjectFloatRect.top - EntityFloatRect.top);
    else if(EntityFloatRect.top + EntityFloatRect.height > ObjectFloatRect.top + ObjectFloatRect.height)
        return Axis::Vertical * ((ObjectFloatRect.top + ObjectFloatRect.height) - (EntityFloatRect.top + EntityFloatRect.height));
    else if(EntityFloatRect.left < ObjectFloatRect.left)
        return Axis::Horizontal * (ObjectFloatRect.left - EntityFloatRect.left);
    else if(EntityFloatRect.left + EntityFloatRect.width > ObjectFloatRect.left + ObjectFloatRect.width)
        return Axis::Horizontal * ((ObjectFloatRect.left + ObjectFloatRect.width) - (EntityFloatRect.left + EntityFloatRect.width));
    return Axis::None;
}