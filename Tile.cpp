#include "Tile.h"

Tile::Tile(Colour c, Shape s) {
  this->colour = c;
  this->shape = s;
}

Tile::Tile(const Tile &t) {
  colour = t.colour;
  shape = t.shape;
}

Tile::Tile() {
  shape = 0;
  colour = ' ';
}


//Getters
Shape Tile::getShape() {
  return shape;
}

Colour Tile::getColour() {
  return colour;
}


//Setters
void Tile::setShape(Shape s) {
  shape = s;
}

void Tile::setColour(Colour c) {
  colour = c;
}

//Tile Functions

bool Tile::compareTile(Tile *tile) {
  bool result = false;
  if (this->colour == tile->getColour() && this->shape == tile->getShape()) {
    result = true;
  }
  return result;
}

bool Tile::isSameColour(const Tile &tile) {
  return colour == tile.colour;
}

bool Tile::isSameShape(const Tile &tile) {
  return shape == tile.shape;
}

// std::ostream &operator<<(std::ostream &out, const Tile &tile) {
//   out << tile.colour << std::to_string(tile.shape);
//   return out;
// }

// Tile &Tile::operator=(const Tile &tile) {
//   colour = tile.colour;
//   shape = tile.shape;
//   return *this;
// }

// bool operator==(const Tile &t1, const Tile &t2) {
//   return t1.colour == t2.colour && t1.shape == t2.shape;
// }


