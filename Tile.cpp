
#include "Tile.h"


Tile::Tile(Colour colour, Shape shape) {
	this->colour = colour;
	this->shape = shape;
}

void Tile::setColour(Colour colour) {
	this->colour = colour;
}

Colour Tile::getColour() {
	return colour;
}

void Tile::setShape(Shape shape) {
	this->shape = shape;
}

Shape Tile::getShape() {
	return Shape;
}

Tile::compareTile(Tile tileA, Tile tileB) {
	if (TileA->getColour() == tileB.getColour() || TileA->getShape() && TileB->getShape()) {
		compareResult = true;
	} else {
		compareResult = false;
	}
	return compareResult;
}
