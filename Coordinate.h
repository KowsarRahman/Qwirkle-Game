#ifndef ASSIGN2_COORDINATE_H
#define ASSIGN2_COORDINATE_H

#include <iostream>
#include <vector>
#include "Tile.h"

class Coordinate {

  public:
    
    //Constructors
    Coordinate(char y, int x);
    Coordinate(char y, int x, Tile t);
    Coordinate(const Coordinate &c);
    
    //Getters
    int getX();
    int getY();
    Tile getTile();
    
    //Operator Overloading
    friend std::ostream &operator<<(std::ostream &out, const Coordinate &c);
    Coordinate &operator=(const Coordinate &c);
    friend bool operator==(const Coordinate &c1, const Coordinate &c2);

    //Changing the coordinate position
    void migratingX(int x);
    void migratingY(int y);

private:
    int M_x;
    int M_y;

    Tile M_tile;

};

#endif // ASSIGN2_COORDINATE_H