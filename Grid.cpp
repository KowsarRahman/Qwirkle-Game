#include "Grid.h"

#include <string>

Grid::Grid(char y, int x) {
  M_x = x;
  M_y = y - 65;
}

Grid::Grid(char y, int x, Tile t) {
  M_x = x;
  M_y = y - 65;
  M_tile = t;
}

Grid::Grid(const Grid &c) {
  M_y = c.M_y;
  M_x = c.M_x;
  M_tile = c.M_tile;
}

int Grid::getX() {
  return M_x;
}

int Grid::getY() {
  return M_y;
}

Tile Grid::getTile() {
  return M_tile;
}

std::ostream &operator<<(std::ostream &out, const Grid &c) {
  out << (char) (c.M_y + 65) << c.M_x;
  return out;
}

Grid &Grid::operator=(const Grid &c) {
  M_y = c.M_y;
  M_x = c.M_x;
  M_tile = c.M_tile;
  return *this;
}

bool operator==(const Grid &c1, const Grid &c2) {
  return c1.M_x == c2.M_x && c1.M_y == c2.M_y;
}

void Grid::migratingX(int x) {
  M_x += x;
}

void Grid::migratingY(int y) {
  M_y += y;
}