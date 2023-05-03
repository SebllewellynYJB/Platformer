#include <iostream>

#include "Enemy.h"

// Collision of moving tile. This is set in the update in the game cpp
bool Enemy::collision(sf::RenderWindow& window)
{
  // Gets the postion of the object and checks if it's greater than 0 in the y-axis. Then check the whole window height and then gets the size of the window
  // in the y-axis. Then sets direction in x and y-axis. Repeats this for x-axis but just reversing the direction
  if ((getSprite()->getPosition().y < 0)||
      (getSprite()->getPosition().y + getSprite()->getGlobalBounds().height > window.getSize().y))
  {
    setDirection(Vector2(getDirection().x,-getDirection().y));
    return true;
  }
  if ((getSprite()->getPosition().x < 0)||
      (getSprite()->getPosition().x + getSprite()->getGlobalBounds().width > window.getSize().x))
  {
    setDirection(Vector2(-getDirection().x, getDirection().y));
    return true;
  }
}

// This will be used in the render to render if the object is visible or not
bool Enemy::isIsvisible() const
{
  return isvisible;
}

// Will check is the object is visible by using true and false
void Enemy::setIsvisible(bool isvisible)
{
  Enemy::isvisible = isvisible;
}

void Enemy::move(sf::RenderWindow& window , float dt)
{
  collision(window);
  getSprite()->move(getDirection().x * getSpeed()*dt, getDirection().y * getSpeed()*dt);
}

// Getter and Setter functions for the game
// Setters are used in the init to set different variables
// Getters are used in the update to get the speed from the init to be used
int Enemy::getSpeed() const
{
  return speed;
}

void Enemy::setSpeed(int speed)
{
  Enemy::speed = speed;
}

// This is used in the update function that gets the direction from the init
const Vector2& Enemy::getDirection() const
{
  return direction;
}

// This is used in the init function to set the direction
void Enemy::setDirection(const Vector2& direction)
{
  Enemy::direction = direction;
}