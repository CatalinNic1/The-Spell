#include "SmartRect.hpp"
#include "../CentralStuff/TypeDefs.hpp"

void SmartRect::moveRect(float DeltaTime, sf::Vector2f Direction, float SpeedFactor)
{
    move(DeltaTime * MovingSpeed * Direction * SpeedFactor);
    MovingDirection = Direction;
    //if(Direction != Directions::Stop)
    //    MovingDirection = Direction;
    PseudoLineThickness = DeltaTime * MovingSpeed;
}

sf::Vector2f SmartRect::getCollisionDirection(SmartRect OtherObject)
{
    if(MovingDirection != Directions::Stop)
    {
        sf::FloatRect OtherObjectFloatRect = OtherObject.getGlobalBounds();
        sf::FloatRect ObjectFloatRect = getGlobalBounds();
        sf::FloatRect OtherObjectPseudoLine = sf::FloatRect();
        sf::FloatRect ObjectPseudoLine = sf::FloatRect();
        // Up
        if(MovingDirection == Directions::Up)
        {
            ObjectPseudoLine = sf::FloatRect(ObjectFloatRect.left, ObjectFloatRect.top - PseudoLineThickness, ObjectFloatRect.width, PseudoLineThickness * PseudoLineMultiplier);
            OtherObjectPseudoLine = sf::FloatRect(OtherObjectFloatRect.left, OtherObjectFloatRect.top + OtherObjectFloatRect.height - PseudoLineThickness, OtherObjectFloatRect.width, PseudoLineThickness * PseudoLineMultiplier);
        }
        // Down
        else if(MovingDirection == Directions::Down)
        {
            ObjectPseudoLine = sf::FloatRect(ObjectFloatRect.left, ObjectFloatRect.top + ObjectFloatRect.height - PseudoLineThickness, ObjectFloatRect.width, PseudoLineThickness * PseudoLineMultiplier);
            OtherObjectPseudoLine = sf::FloatRect(OtherObjectFloatRect.left, OtherObjectFloatRect.top - PseudoLineThickness, OtherObjectFloatRect.width, PseudoLineThickness * PseudoLineMultiplier);
        }
        // Left
        else if(MovingDirection == Directions::Left)
        {
            ObjectPseudoLine = sf::FloatRect(ObjectFloatRect.left - PseudoLineThickness, ObjectFloatRect.top, PseudoLineThickness * PseudoLineMultiplier, ObjectFloatRect.height);
            OtherObjectPseudoLine = sf::FloatRect(OtherObjectFloatRect.left + OtherObjectFloatRect.width - PseudoLineThickness, OtherObjectFloatRect.top, PseudoLineThickness * PseudoLineMultiplier, OtherObjectFloatRect.height);
        }
        // Right
        else if(MovingDirection == Directions::Right)
        {
            ObjectPseudoLine = sf::FloatRect(ObjectFloatRect.left + ObjectFloatRect.width - PseudoLineThickness, ObjectFloatRect.top, PseudoLineThickness * PseudoLineMultiplier, ObjectFloatRect.height);
            OtherObjectPseudoLine = sf::FloatRect(OtherObjectFloatRect.left - PseudoLineThickness, OtherObjectFloatRect.top, PseudoLineThickness * PseudoLineMultiplier, OtherObjectFloatRect.height);
        }
        // Verification
        if(ObjectPseudoLine.intersects(OtherObjectPseudoLine))
            return MovingDirection;
        else
            return -OtherObject.MovingDirection;
    }
    else
        return -OtherObject.MovingDirection;
}

bool SmartRect::CheckCollision(sf::FloatRect OtherObjectFloatRect)
{
    sf::Vector2f Difference = getInwardsCollision(OtherObjectFloatRect);
    move(Difference);
    if(Difference != Axis::None)
        return true;
    else
        return false;
}

bool SmartRect::CheckCollision(SmartRect& OtherObject, CollisionTypes CollisionType)
{
    if(CollisionType == CollisionTypes::Inwards)
    {
        sf::Vector2f Difference = getInwardsCollision(OtherObject);
        move(Difference * DifferenceOffset);
        if(Difference != Axis::None)
            return true;
        else
            return false;
    }
    else if(CollisionType == CollisionTypes::Outwards)
    {
        sf::Vector2f Difference = getOutwardsCollision(OtherObject);
        move(Difference * DifferenceOffset);
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
    if(ObjectFloatRect.top + ObjectFloatRect.height > OtherObjectFloatRect.top + OtherObjectFloatRect.height)
        return Axis::Vertical * ((OtherObjectFloatRect.top + OtherObjectFloatRect.height) - (ObjectFloatRect.top + ObjectFloatRect.height));
    if(ObjectFloatRect.left < OtherObjectFloatRect.left)
        return Axis::Horizontal * (OtherObjectFloatRect.left - ObjectFloatRect.left);
    if(ObjectFloatRect.left + ObjectFloatRect.width > OtherObjectFloatRect.left + OtherObjectFloatRect.width)
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
        if(CollisionDirection == Directions::Down)
            return Axis::Vertical * (OtherObjectFloatRect.top - (ObjectFloatRect.top + ObjectFloatRect.height));
        if(CollisionDirection == Directions::Left)
            return Axis::Horizontal * (OtherObjectFloatRect.width + OtherObjectFloatRect.left - ObjectFloatRect.left);
        if(CollisionDirection == Directions::Right)
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