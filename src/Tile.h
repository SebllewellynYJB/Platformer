#ifndef Tile_H
#define Tile_H

#include "GameObject.h"

class Tile : public GameObject
{

 public:
  bool isVisible() const;
  void setIsVisible(bool isVisible);

 private:
  bool is_visible = true;

};

#endif
