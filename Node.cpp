
#include "Node.h"

Node::Node(Tile* tile, Node* next)
{
   // We shall implement a deep copy of Tile
   this->tile = new Tile(tile->getColour(), tile->getShape());
   this->next = next;
}

Node::~Node() {
  //deleting tile
  delete tile;
}

Node::Node(Node& other)
{
   // Again, we are implementing a deep copy
   this->tile = new Tile(*(other.tile));
   this->next = other.next;
}
