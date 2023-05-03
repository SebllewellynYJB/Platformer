#ifndef Enemy_H
#define Enemy_H

#include <SFML//Audio.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameObject.h"

class Enemy : public GameObject
{

 public:
  const Vector2& getDirection() const;
  void setDirection(const Vector2& direction);
  bool isIsvisible() const;
  void setIsvisible(bool isvisible);
  void move(sf::RenderWindow& window , float dt);
  int getSpeed() const;
  void setSpeed(int speed);

 private:
  bool collision(sf::RenderWindow& window);
  Vector2 direction {0,0};
  int speed = 0;
  
  bool isvisible = true;
};

#endif // PLATFORMERSFML_ENEMY_H
