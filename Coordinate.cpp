#include "Coordinate.h"

#include <string>

Coordinate::Coordinate(char y, int x) {
  M_x = x;
  M_y = y - 65;
}

Coordinate::Coordinate(char y, int x, Tile t) {
  M_x = x;
  M_y = y - 65;
  M_tile = t;
}

Coordinate::Coordinate(const Coordinate &c) {
  M_y = c.M_y;
  M_x = c.M_x;
  M_tile = c.M_tile;
}

int Coordinate::getX() {
  return M_x;
}

int Coordinate::getY() {
  return M_y;
}

Tile Coordinate::getTile() {
  return M_tile;
}

std::ostream &operator<<(std::ostream &out, const Coordinate &c) {
  out << (char) (c.M_y + 65) << c.M_x;
  return out;
}

Coordinate &Coordinate::operator=(const Coordinate &c) {
  M_y = c.M_y;
  M_x = c.M_x;
  M_tile = c.M_tile;
  return *this;
}

bool operator==(const Coordinate &c1, const Coordinate &c2) {
  return c1.M_x == c2.M_x && c1.M_y == c2.M_y;
}

void Coordinate::migratingX(int x) {
  M_x += x;
}

void Coordinate::migratingY(int y) {
  M_y += y;
}