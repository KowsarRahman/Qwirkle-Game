#include "Tile.h"

Tile::Tile(Colour colour, Shape shape)
{
	this->shape = shape;
	this->colour = colour;
	this->isBlank = false;
	
}

Tile::Tile()
{
	this->isBlank = true;
}

Tile::~Tile()
{
}

Tile::Tile(Tile& other)
{
	this->isBlank = false;
	this->shape = other.shape;
	this->colour = other.colour;
}

Shape Tile::getShape()
{
	return this->shape;
}

Colour Tile::getColour()
{
	return this->colour;
}



std::string Tile::getTileString()
{
	std::ostringstream stringStream;
	stringStream << this->colour;
	stringStream << this->shape;
	return stringStream.str();
}

bool Tile::blankStatus()
{
	return this->isBlank;
}

void Tile::printTile()
{
	std::cout << this->colour << this->shape << ", ";
}


