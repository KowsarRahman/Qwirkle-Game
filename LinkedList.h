
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#inlcude <string>


class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   //Removing a tile from Tile bag
   void deleteBack();
   void deleteFront();

   //Deleting a tile from the LinkedList
   void deleteTile(Tile* tile);
   //Adding a Tile in LinkedList
   void addBack(Tile* tile); 

   int getSize();
   void clear();
   
   //Getting tile from the front bag
   Tile* getFront();

   //Some other Tile Functions
   bool contains(Tile* TiletobeCompared);
   void remove(Tile* TiletobeRemoved);
   int tileExist(Tile* TiletobeCompared);

   //Displays the LinkedList
   std::string displayLList();

private:
   
   Node* head;
   Node* tail;
   int size;
};

#endif // ASSIGN2_LINKEDLIST_H
