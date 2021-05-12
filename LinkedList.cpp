
#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;

   // TODO
   tail = nullptr;
   size = 0;
}

LinkedList::~LinkedList() {

   clear();
}

void LinkedList::deleteFront() {
  if (head != nullptr) {
    Node* toDelete = head;
    head = toDelete->next;
    delete toDelete;
    size--;
  }
}

void LinkedList::deleteBack() {
  Node* toDelete = head;
  Node* prev = nullptr;
  while (toDelete->next != nullptr) {
    prev = toDelete;
    toDelete = toDelete->next;
  }
  prev->next = nullptr;
  tail = prev;
  delete toDelete;
  size--;
}

void LinkedList::deleteTile(Tile* tile) {
  bool found = false;
  Node* current = head;
  Node* prev = nullptr;

  // tile to be deleted sits at the beginning
  if (current->tile->compareTile(tile)) {
    deleteFront();
  } else {
    while (current != nullptr && found == false) {
      if (current->tile->compareTile(tile)) {
        found = true;
      } else {
        prev = current;
        current = current->next;
      }
    }
    //delete back
    if (current->next == nullptr) {
      deleteBack();
    } else {
      //delete middle
      prev->next = current->next;
      delete current;
      size--;
    }
  }
}

void LinkedList::addBack(Tile* tile) {
  Node* node = new Node(tile, nullptr);
  if (tail != nullptr) {
    tail->next = node;
    tail = node;
    size++;
  } else {
    head = node;
    tail = node;
    size++;
  }
}

Tile* LinkedList::getFront() {
  return head->tile;
}

int LinkedList::getSize() {
  return size;
}

void LinkedList::clear() {
  Node* copyNode = nullptr;
  Node* current = head;

  while (current != nullptr) {
    copyNode = current->next;
    delete current;
    current = copyNode;
  }
  size = 0;
}

bool LinkedList::contains(Tile* TiletobeCompared) {
  bool found = false;
  Node* current = head;

  while (current != nullptr && found == false) {
    if (current->tile->compareTile(TiletobeCompared)) {
      found = true;
    } else {

      current = current->next;
    }
  }

  return found;

}

void LinkedList::remove(Tile*TiletobeRemoved) {
  if (head != nullptr) {
    Node* toDelete = head;
    while ((toDelete->tile->compareTile(tileToBeRemoved) == false)
        && toDelete != nullptr) {
      toDelete = toDelete->next;
    }

    if (toDelete != nullptr) {
      delete toDelete;
      size--;
    }
  }

}

int LinkedList::tileExist(Tile* TiletobeCompared) {
  int count = 0;

  if (head != nullptr) {
    Node* current = head;

    while (current != nullptr) {
      if (current->tile->compareTile(TiletobeCompared)) {
        count++;
      }

      current = current->next;
    }
  }

  return count;

}

std::string LinkedList::displayLList() {
  std::string result = "";
  Node* current = head;

  while (current != nullptr) {
    
    if (current->next != nullptr) {

      result = result + current->tile->getColour()
          + std::to_string(current->tile->getShape()) + ",";

    }
    
    else {

      result = result + current->tile->getColour()
          + std::to_string(current->tile->getShape());
    }
    current = current->next;
  }

  return result;
}
