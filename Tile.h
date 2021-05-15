#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {
public:
	Tile(Colour colour, Shape shape);
	
	void setColour(char colour);
	char getColour();

	void setShape(int shape);
	int getShape();

private:
	Colour colour;
	Shape  shape;
};

endif // ASSIGN2_TILE_H
