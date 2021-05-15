
#include "Tile.h"


Tile::Tile(Colour colour, Shape shape) {
	this->colour = colour;
	this->shape = shape;
}

void Tile::setColour(Colour colour) {
	this->colour = colour;
}

Colour Tile::getColout() {
	return colour;
}

void Tile::setShape(Shape shape) {
	this->shape = shape;
}

Shape Tile::getShape() {
	return Shape;
}
