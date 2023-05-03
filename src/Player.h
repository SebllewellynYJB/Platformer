#ifndef Player_H
#define Player_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

#include "GameObject.h"

class Player : public GameObject
{

 public:
  Player();
  const Vector2& getPlayerDirection() const;
  void setPlayerDirection(const Vector2& playerDirection);
  void keyPressed(sf::RenderWindow& window, sf::Event event);
  void move(sf::RenderWindow& window, float dt, sf::Event event);
  int getSpeed() const;
  void setSpeed(int speed);
  // Player direction for key movement
  Vector2 player_direction = {0,0};

 private:
  void keyReleased(sf::RenderWindow& window,sf::Event event);
  int speed = 0;

};

#endif // PLATFORMERSFML_PLAYER_H
