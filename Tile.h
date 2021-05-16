#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include <sstream>
#include <iostream>
#include <string>
#include <memory>

typedef char Colour;

typedef int Shape;

class Tile {
public:
  
   Tile(Colour colour, Shape shape);

   Tile();

   ~Tile();

   Tile(Tile& other);

   Shape getShape();

   std::string getTileString();

   bool blankStatus();

   void printTile();

   Colour getColour();

private: 
   Colour colour;

   Shape  shape;

   bool isBlank;

};

#endif // ASSIGN2_TILE_H
