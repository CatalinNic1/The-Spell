#include "Player.hpp"

Player::Player(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName): 
    Entity(Position, Size, TextureFileName) {}

void Player::Update(float DeltaTime)
{
    ProcessInput(DeltaTime);
    UpdateView();
}

void Player::ProcessInput(float DeltaTime)
{
    auto [PlayerDirection, PlayerAction] = getAction();
    moveEntity(DeltaTime, PlayerDirection);
    EntityAnimate(PlayerAction);
}

std::pair< sf::Vector2f, Actions > Player::getAction()
{
    if(getInput::OnlyMovingUp())
        return {Directions::Up, Actions::MoveUp};
    else if(getInput::OnlyMovingDown())
        return {Directions::Down, Actions::MoveDown};
    else if(getInput::OnlyMovingLeft())
        return {Directions::Left, Actions::MoveLeft};
    else if(getInput::OnlyMovingRight())
        return {Directions::Right, Actions::MoveRight};
    else
        return {Directions::Stop, Actions::None};
}

void Player::setViewSize(sf::Vector2f NewSize)
{
    const sf::Vector2f defaultSize{960, 540};
    float scaleFactor = 1;
    while(NewSize.x / scaleFactor > defaultSize.x || NewSize.y / scaleFactor > defaultSize.y)
        scaleFactor++;
    PlayerView.setSize(NewSize.x / scaleFactor, NewSize.y / scaleFactor);
}

void Player::UpdateView()
{
    PlayerView.setCenter(getCenterPosition());
}

sf::Vector2f Player::getCenterPosition()
{
    return EntityRect.getPosition() + (EntityRect.getSize() / 2.f);
}

sf::View Player::getPlayerView()
{
    return PlayerView;
}