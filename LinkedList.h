#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Tile.h"
#include "Node.h"

#include <vector>
#include <string>
#include <random>
#include <algorithm>

class LinkedList {
public:

   LinkedList();

   ~LinkedList();
   
   //Adding Front and Back
   void addFront(std::shared_ptr<Tile> tile);
   void addBack(std::shared_ptr<Tile> tile);

   // Sorting Functions
   void softDeleteByIndex(int index);
   std::shared_ptr<Tile> getByIndex(int index);
   std::shared_ptr<Tile> popHead();

   //Index Functions
   int findIndex(Colour colour, Shape shape);
   void deleteByIndex(int index);

   

   // Get number of elements in the list
   int getSize();

   std::shared_ptr<Node> getHead();
   
   // Clears list, it does not delete any nodes use only before shuffle
   void clear();
   // pass vector to list to create it
   void initiliseList(std::vector<std::string> tiles);
   void shuffleLinkedList();
   
   
   void printList();
   std::string getListForDisplay();
   

private:
   std::shared_ptr<Node> head;
};

#endif // ASSIGN2_LINKEDLIST_H
