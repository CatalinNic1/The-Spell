#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

enum class Actions
{
    None = -1,
    MoveUp,
    MoveDown,
    MoveLeft,
    MoveRight,
    JumpLeft,
    JumpRight,
    Attack,
    Pair,
};

class Animation
{
private:
    int FrameLimit;
    int CurrentFrame = 0;
    Actions CurrentAction = Actions::MoveDown;
public:
    void setFrameLimit(float TextureWidth, int HorizontalFrameNumber);
    void Animate(sf::RectangleShape& EntityRect, Actions Action);
};
