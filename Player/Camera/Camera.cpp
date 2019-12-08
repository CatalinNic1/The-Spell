#include "Camera.hpp"
#include <iostream>

void Camera::setCameraSize(sf::Vector2f NewSize)
{
    const sf::Vector2f defaultSize{960.f, 540.f};
    float scaleFactor = 1;
    while(NewSize.x / scaleFactor > defaultSize.x || NewSize.y / scaleFactor > defaultSize.y)
        scaleFactor++;
    setSize(NewSize.x / scaleFactor, NewSize.y / scaleFactor);
    CameraSize = {NewSize.x / scaleFactor, NewSize.y / scaleFactor};
}

void Camera::UpdateCamera(sf::FloatRect EntityCenter)
{
    PlayerCentralPosition = getPlayerCenterPosition(EntityCenter);
    auto[Direction, CollisionType] = getCameraDirection();
    sf::Vector2f PositionDiff = PlayerCentralPosition - getCenter();
    move({Direction.x * PositionDiff.x, Direction.y * PositionDiff.y});
    if(CollisionType != Collisions::Nope)
        correctCamera(CollisionType);
}

void Camera::correctCamera(Camera::Collisions CollisionType)
{
    sf::Vector2f CameraPosition = getCenter();
    if(CollisionType == Collisions::Up)
        setCenter(CameraPosition.x, CameraSize.y / 2.f);
    else if(CollisionType == Collisions::Down)
        setCenter(CameraPosition.x, LevelLimits.y - CameraSize.y / 2.f);
    else if(CollisionType == Collisions::Left)
        setCenter(CameraSize.x / 2.f, CameraPosition.y);
    else if(CollisionType == Collisions::Right)
        setCenter(LevelLimits.x - CameraSize.x / 2.f, CameraPosition.y);
}

std::pair< sf::Vector2f, Camera::Collisions > Camera::getCameraDirection()
{
    sf::Vector2f CameraPosition = getCenter();
    if(PlayerCentralPosition.y < CameraPosition.y && PlayerCentralPosition.y - CameraSize.y / 2.f > 0.f)
        return {Axis::Vertical, Collisions::Nope};
    else if(PlayerCentralPosition.y > CameraPosition.y && PlayerCentralPosition.y + CameraSize.y / 2.f < LevelLimits.y)
        return {Axis::Vertical, Collisions::Nope};
    else if(PlayerCentralPosition.x < CameraPosition.x && PlayerCentralPosition.x - CameraSize.x / 2.f > 0.f)
        return {Axis::Horizontal, Collisions::Nope};
    else if(PlayerCentralPosition.x > CameraPosition.x && PlayerCentralPosition.x + CameraSize.x / 2.f < LevelLimits.x)
        return {Axis::Horizontal, Collisions::Nope};
    else
        return getCollisionType();
}

std::pair< sf::Vector2f, Camera::Collisions > Camera::getCollisionType()
{
    if(PlayerCentralPosition.y - CameraSize.y / 2.f < 0.f)
        return {Axis::None, Collisions::Up};
    else if(PlayerCentralPosition.y + CameraSize.y / 2.f > LevelLimits.y)
        return {Axis::None, Collisions::Down};
    else if(PlayerCentralPosition.x - CameraSize.x / 2.f < 0.f)
        return {Axis::None, Collisions::Left};
    else if(PlayerCentralPosition.x + CameraSize.x / 2.f > LevelLimits.x)
        return {Axis::None, Collisions::Right};
    else
        return {Axis::None, Collisions::Nope};
}

void Camera::setLevelLimits(sf::Vector2f Limits)
{
    LevelLimits = Limits;
}

sf::Vector2f Camera::getPlayerCenterPosition(sf::FloatRect EntityRect)
{
    return sf::Vector2f(EntityRect.left, EntityRect.top);
}