#include "Tile.h"

//Visibility information
bool Tile::isVisible() const
{
  return is_visible;
}

void Tile::setIsVisible(bool isVisible)
{
  is_visible= isVisible;
}