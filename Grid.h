#ifndef ASSIGN2_Grid_H
#define ASSIGN2_Grid_H

#include <iostream>
#include <vector>
#include "Tile.h"

class Grid {

  public:
    
    //Constructors
    Grid(char y, int x);
    Grid(char y, int x, Tile t);
    Grid(const Grid &c);
    
    //Getters
    int getX();
    int getY();
    Tile getTile();
    
    //Operator Overloading
    friend std::ostream &operator<<(std::ostream &out, const Grid &c);
    Grid &operator=(const Grid &c);
    friend bool operator==(const Grid &c1, const Grid &c2);

    //Changing the Grid position
    void migratingX(int x);
    void migratingY(int y);

private:
    int M_x;
    int M_y;

    Tile M_tile;

};
#endif //GRID_H