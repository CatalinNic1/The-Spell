#include "SmartRect.hpp"

void SmartRect::moveRect(float DeltaTime, sf::Vector2f Direction, float SpeedFactor)
{
    move(DeltaTime * MovingSpeed * Direction * SpeedFactor);
    MovingDirection = Direction;
    PseudoLineThickness = DeltaTime * MovingSpeed * SpeedFactor * 2.f;
}

sf::Vector2f SmartRect::getCollisionDirection(SmartRect OtherObject)
{
    sf::FloatRect OtherObjectFloatRect = OtherObject.getGlobalBounds();
    sf::FloatRect ObjectFloatRect = getGlobalBounds();
    sf::FloatRect PseudoLine;

    if(OtherObject.MovingDirection == Directions::Up)
    {
        // Up
        PseudoLine = sf::FloatRect(OtherObjectFloatRect.left, OtherObjectFloatRect.top + PseudoLineThickness, OtherObjectFloatRect.width, PseudoLineThickness);
        if(ObjectFloatRect.intersects(PseudoLine))
            return Directions::Down;
    }
    else if(OtherObject.MovingDirection == Directions::Down)
    {
        // Down
        PseudoLine = sf::FloatRect(OtherObjectFloatRect.left, OtherObjectFloatRect.top + OtherObjectFloatRect.width, OtherObjectFloatRect.width, PseudoLineThickness);
        if(ObjectFloatRect.intersects(PseudoLine))
            return Directions::Up;
    }
    else if(OtherObject.MovingDirection == Directions::Left)
    {
        // Left
        PseudoLine = sf::FloatRect(OtherObjectFloatRect.left - PseudoLineThickness, OtherObjectFloatRect.top, PseudoLineThickness, OtherObjectFloatRect.height);
        if(ObjectFloatRect.intersects(PseudoLine))
            return Directions::Right;
    }
    else if(OtherObject.MovingDirection == Directions::Right)
    {
        // Right
        PseudoLine = sf::FloatRect(OtherObjectFloatRect.left + OtherObjectFloatRect.width, OtherObjectFloatRect.top, PseudoLineThickness, OtherObjectFloatRect.height);
        if(ObjectFloatRect.intersects(PseudoLine))
            return Directions::Left;
    }
    std::printf("%s", "Collision\n");
    return MovingDirection;
}

bool SmartRect::CheckCollision(sf::FloatRect OtherObjectFloatRect)
{
    sf::Vector2f Difference = getInwardsCollision(OtherObjectFloatRect);
    move(Difference);
    if(Difference != sf::Vector2f(0.f, 0.f))
        return true;
    else
        return false;
}

bool SmartRect::CheckCollision(SmartRect& OtherObject, CollisionTypes CollisionType)
{
    if(CollisionType == CollisionTypes::Inwards)
    {
        sf::Vector2f Difference = getInwardsCollision(OtherObject) + getCollisionDirection(OtherObject);
        move(Difference);
        if(Difference != Axis::None)
            return true;
        else
            return false;
    }
    else if(CollisionType == CollisionTypes::Outwards)
    {
        sf::Vector2f Difference = getOutwardsCollision(OtherObject) * 1.1f;
        move(Difference);
        if(Difference != Axis::None)
            return true;
        else
            return false;
    }
    return false;
}

sf::Vector2f SmartRect::getInwardsCollision(sf::FloatRect OtherObjectFloatRect)
{
    sf::FloatRect ObjectFloatRect = getGlobalBounds();
    if(ObjectFloatRect.top < OtherObjectFloatRect.top)
        return Axis::Vertical * (OtherObjectFloatRect.top - ObjectFloatRect.top);
    else if(ObjectFloatRect.top + ObjectFloatRect.height > OtherObjectFloatRect.top + OtherObjectFloatRect.height)
        return Axis::Vertical * ((OtherObjectFloatRect.top + OtherObjectFloatRect.height) - (ObjectFloatRect.top + ObjectFloatRect.height));
    else if(ObjectFloatRect.left < OtherObjectFloatRect.left)
        return Axis::Horizontal * (OtherObjectFloatRect.left - ObjectFloatRect.left);
    else if(ObjectFloatRect.left + ObjectFloatRect.width > OtherObjectFloatRect.left + OtherObjectFloatRect.width)
        return Axis::Horizontal * ((OtherObjectFloatRect.left + OtherObjectFloatRect.width) - (ObjectFloatRect.left + ObjectFloatRect.width));
    return Axis::None;
}

sf::Vector2f SmartRect::getOutwardsCollision(SmartRect OtherObject)
{
    sf::FloatRect ObjectFloatRect = getGlobalBounds();
    sf::FloatRect OtherObjectFloatRect = OtherObject.getGlobalBounds();
    sf::Vector2f CollisionDirection = getCollisionDirection(OtherObject);

    if(ObjectFloatRect.intersects(OtherObjectFloatRect))
    {
        if(CollisionDirection == Directions::Up)
            return Axis::Vertical * (OtherObjectFloatRect.height + OtherObjectFloatRect.top - ObjectFloatRect.top);
        else if(CollisionDirection == Directions::Down)
            return Axis::Vertical * (OtherObjectFloatRect.top - (ObjectFloatRect.top + ObjectFloatRect.height));
        else if(CollisionDirection == Directions::Left)
            return Axis::Horizontal * (OtherObjectFloatRect.width + OtherObjectFloatRect.left - ObjectFloatRect.left);
        else if(CollisionDirection == Directions::Right)
            return Axis::Horizontal * (OtherObjectFloatRect.left - (ObjectFloatRect.left + ObjectFloatRect.width));   
    }
    return Axis::None;
}

sf::Vector2f SmartRect::getInwardsCollision(SmartRect OtherObject)
{
    sf::FloatRect ObjectFloatRect = getGlobalBounds();
    sf::FloatRect OtherObjectFloatRect = OtherObject.getGlobalBounds();
    sf::Vector2f PositionDifference = Axis::None;

    if(ObjectFloatRect.top < OtherObjectFloatRect.top)
        PositionDifference += (Axis::Vertical * (OtherObjectFloatRect.top - ObjectFloatRect.top));
    if(ObjectFloatRect.top + ObjectFloatRect.height > OtherObjectFloatRect.top + OtherObjectFloatRect.height)
        PositionDifference += (Axis::Vertical * ((OtherObjectFloatRect.top + OtherObjectFloatRect.height) - (ObjectFloatRect.top + ObjectFloatRect.height)));
    if(ObjectFloatRect.left < OtherObjectFloatRect.left)
        PositionDifference += (Axis::Horizontal * (OtherObjectFloatRect.left - ObjectFloatRect.left));
    if(ObjectFloatRect.left + ObjectFloatRect.width > OtherObjectFloatRect.left + OtherObjectFloatRect.width)
        PositionDifference += (Axis::Horizontal * ((OtherObjectFloatRect.left + OtherObjectFloatRect.width) - (ObjectFloatRect.left + ObjectFloatRect.width)));
    return PositionDifference;
}