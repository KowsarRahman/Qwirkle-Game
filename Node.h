#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"

#include <memory>

class Node {
public:

   Node(std::shared_ptr<Tile> tile, std::shared_ptr<Node> next);
   
   Node(Node& other);

   ~Node();
   
   //Shared pointers
   std::shared_ptr<Node> next;
   std::shared_ptr<Tile> tile;

   
};

#endif // ASSIGN2_NODE_H
