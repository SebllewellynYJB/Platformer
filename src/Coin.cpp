#include "Coin.h"

Coin::Coin()
{

}

bool Coin::isIsvisible() const
{
  return isvisible;
}

void Coin::setIsvisible(bool isvisible)
{
  Coin::isvisible = isvisible;
}
