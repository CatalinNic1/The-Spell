#include "Camera.hpp"
#include "../../CentralStuff/TypeDefs.hpp"

void Camera::setCameraSize(sf::Vector2f NewSize)
{
    float ScaleFactor = 1;
    while(NewSize.x / ScaleFactor > DefaultSize.x || NewSize.y / ScaleFactor > DefaultSize.y)
        ScaleFactor++;
    setSize(NewSize.x / ScaleFactor, NewSize.y / ScaleFactor);
    CameraSize = {NewSize.x / ScaleFactor, NewSize.y / ScaleFactor};
}

void Camera::UpdateCamera(sf::FloatRect EntityCenter)
{
    PlayerCentralPosition = getPlayerCenterPosition(EntityCenter);
    sf::Vector2f Direction = getCameraDirection();
    sf::Vector2f PositionDiff = PlayerCentralPosition - getCenter();
    
    move({Direction.x * PositionDiff.x, Direction.y * PositionDiff.y});
    Collisions CollisionType = getCollisionType();
    correctCamera(CollisionType);
}

void Camera::correctCamera(Camera::Collisions CollisionType)
{
    sf::Vector2f CameraPosition = getCenter();
    sf::Vector2f SuperiorLimitsDiff = LevelLimits - (CameraPosition + CameraSize / 2.f);
    sf::Vector2f InferiorLimitsDiff = CameraPosition - CameraSize / 2.f;

    if(CollisionType == Collisions::Up)
        move(Axis::Vertical * -InferiorLimitsDiff.y);
    else if(CollisionType == Collisions::Down)
        move(Axis::Vertical * SuperiorLimitsDiff.y);
    else if(CollisionType == Collisions::Left)
        move(Axis::Horizontal * -InferiorLimitsDiff.x);
    else if(CollisionType == Collisions::Right)
        move(Axis::Horizontal * SuperiorLimitsDiff.x);
}

sf::Vector2f Camera::getCameraDirection()
{
    sf::Vector2f CameraPosition = getCenter();
    if(PlayerCentralPosition.y < CameraPosition.y && CameraPosition.y - CameraSize.y / 2.f > 0.f)
        return Axis::Vertical;
    else if(PlayerCentralPosition.y > CameraPosition.y && CameraPosition.y + CameraSize.y / 2.f < LevelLimits.y)
        return Axis::Vertical;
    else if(PlayerCentralPosition.x < CameraPosition.x && CameraPosition.x - CameraSize.x / 2.f > 0.f)
        return Axis::Horizontal;
    else if(PlayerCentralPosition.x > CameraPosition.x && CameraPosition.x + CameraSize.x / 2.f < LevelLimits.x)
        return Axis::Horizontal;
    else
        return Axis::None;
}

Camera::Collisions Camera::getCollisionType()
{
    sf::Vector2f CameraPosition = getCenter();
    if(CameraPosition.y - CameraSize.y / 2.f < 0.f)
        return Collisions::Up;
    else if(CameraPosition.y + CameraSize.y / 2.f > LevelLimits.y)
        return Collisions::Down;
    else if(CameraPosition.x - CameraSize.x / 2.f < 0.f)
        return Collisions::Left;
    else if(CameraPosition.x + CameraSize.x / 2.f > LevelLimits.x)
        return Collisions::Right;
    else
        return Collisions::Nope;
}

void Camera::setLevelLimits(sf::Vector2f Limits)
{
    LevelLimits = Limits;
}

sf::Vector2f Camera::getPlayerCenterPosition(sf::FloatRect EntityRect)
{
    return sf::Vector2f(EntityRect.left, EntityRect.top) + sf::Vector2f(EntityRect.width, EntityRect.height) / 2.f;
}