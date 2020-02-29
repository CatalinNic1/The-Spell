#include "Enemy.hpp"

Enemy::Enemy(const sf::Vector2f& Position, const sf::Vector2f& Size, const std::string& TextureFileName)
    : Entity(Position, Size)
{
    initEntityAnim(TextureFileName);
}
