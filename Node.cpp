#include "Node.h"

//Default Constructors
Node::Node(std::shared_ptr<Tile> tile, std::shared_ptr<Node> next)
{
	this->tile = tile; 
	this->next = next;
}

//Copy Constructors
Node::Node(Node& other)
{
	this->tile = other.tile;
	this->next = other.next;
}

//Deconstructor
Node::~Node()
{
}
