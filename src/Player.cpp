#include "Player.h"
Player::Player()
{

}

void Player::keyReleased(sf::RenderWindow& window, sf::Event event)
// When the key is released. The event will stop happening
{
  if(event.key.code == sf::Keyboard::Space)
  {
    player_direction.y = 1;
  }
  // Key events that stop player moving
  if ((event.key.code == sf::Keyboard::A)||
      (event.key.code == sf::Keyboard::D))
  {
    player_direction.x = 0;
    player_direction.y = 0;
  }
}

void Player::keyPressed(sf::RenderWindow& window, sf::Event event)
{
}

void Player::move(sf::RenderWindow& window, float dt,sf::Event event)
{
  // Updates player movement
  getSprite()->move(player_direction.x * getSpeed() * dt, player_direction.y * getSpeed() * dt);
  keyReleased(window,event);
}

// Getter and Setter functions for the game
// Setters are used in the init to set different variables
// Getters are used in the update to get the speed from the init to be used
int Player::getSpeed() const
{
  return speed;
}

void Player::setSpeed(int speed)
{
  Player::speed = speed;
}
const Vector2& Player::getPlayerDirection() const
{
  return player_direction;
}
void Player::setPlayerDirection(const Vector2& playerDirection)
{
  player_direction = playerDirection;
}
