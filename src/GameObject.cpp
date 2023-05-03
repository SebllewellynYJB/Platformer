#include <iostream>

#include "GameObject.h"

// Game object Functions-First 4 are taken from worksheet 3
// Creates a new sprite
GameObject::GameObject()
{
  sprite = new sf::Sprite();
}

// Deletes sprite
GameObject::~GameObject()
{
  if (sprite != nullptr)
  {
    delete sprite;
    sprite = nullptr;
  }
}
// Loads the sprite in
bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
  if (!texture.loadFromFile(filename))
  {
    std::cout  <<"texture did not load";
  }
  sprite->setTexture(texture);
}

// using this will allow you to set the position, scale and other aspects
sf::Sprite* GameObject::getSprite()
{
  return sprite;
}

