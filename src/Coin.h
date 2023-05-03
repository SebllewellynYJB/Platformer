#ifndef Coin_H
#define Coin_H

#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Coin : public GameObject
{

 public:
  Coin();
  bool isIsvisible() const;
  void setIsvisible(bool isvisible);

 private:
  bool isvisible = true;

};

#endif // PLATFORMERSFML_COIN_H
