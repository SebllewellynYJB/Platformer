#ifndef GameObject_H
#define GameObject_H

#include<SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

#include "Vector.h"

class GameObject
{

 public:
  //Game object functions - First 4 are taken from worksheet 3
  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();

 protected:
  sf::Sprite* sprite = nullptr;

 private:

};

#endif