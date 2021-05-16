#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {
public:
   Tile(Colour c, Shape s);
   Tile(const Tile &t);
   Tile();

   // Getters
   Colour getColour();
   Shape getShape();

   // Setters
   void setColour(Colour c);
   void setShape(Shape s);

   // compare 2 tiles
   bool compareTile(Tile *tile);

   bool isSameColour(const Tile &tile);
   bool isSameShape(const Tile &tile);

   // friend std::ostream &operator<<(std::ostream &out, const Tile &tile);
   // Tile &operator=(const Tile &tile);
   // friend bool operator==(const Tile &t1, const Tile &t2);


private:

   Colour colour;
   Shape shape;
};

#endif // ASSIGN2_TILE_H
