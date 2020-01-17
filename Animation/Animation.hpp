#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>

//
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
    //
    int FrameLimit = 0;
    //
    int CurrentFrame = 0;
    //
    Actions CurrentAction = Actions::MoveDown;
    //
    bool NeedsToLoad = false;
    //
    std::string FileName;
public:
    //
    std::shared_ptr< sf::Texture > AnimTexture;
    ///
    ///
    ///
    void setFrameLimit(const std::string& TextureFileName, int HorizontalFrameNumber);
    ///
    ///
    ///
    void Animate(sf::RectangleShape& EntityRect, Actions Action);
};
