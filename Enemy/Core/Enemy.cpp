#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName)
    : Entity(Position, Size)
{
    initEntityAnim(TextureFileName);
}
