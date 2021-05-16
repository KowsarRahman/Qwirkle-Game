#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList()
{
	
	if (this->head != nullptr)
	{
		std::shared_ptr<Node> currentNode = this->head->next;
		std::shared_ptr<Node> previousNode = this->head;

		
		if (currentNode == nullptr)
		{
		}
		else
		{
			
			while (currentNode != nullptr)
			{
				
				previousNode = currentNode;
				currentNode = currentNode->next;
			}
			
			this->head = nullptr;
		}
	}
}

void LinkedList::addFront(std::shared_ptr<Tile> tile)
{
	
	if (this->head == nullptr)
	{
		
		std::shared_ptr<Node> newNode = std::make_shared<Node>(tile, nullptr);
		this->head = newNode;
	}
	else
	{
		
		std::shared_ptr<Node> newNode = std::make_shared<Node>(tile, this->head);
		
		this->head = newNode;
	}
}

void LinkedList::addBack(std::shared_ptr<Tile> tile)
{
	std::shared_ptr<Node> currentNode = this->head;
	std::shared_ptr<Node> previousNode = this->head;

	
	if (this->head == nullptr)
	{
		this->head = std::make_shared<Node>(tile, nullptr);
	}
	else
	{
		
		while (currentNode != nullptr)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

		
		std::shared_ptr<Node> newNode = std::make_shared<Node>(tile, nullptr);
		previousNode->next = newNode;
	}
}

int LinkedList::findIndex(Colour colour, Shape shape)
{
	int index = -1;
	int counter = 0;
	bool foundTile = false;

	std::shared_ptr<Node> currentNode = this->head;

	
	while (currentNode != nullptr && !foundTile)
	{
		std::shared_ptr<Tile> tile = currentNode->tile;
		if (tile->getColour() == colour && tile->getShape() == shape)
		{
			foundTile = true;
			index = counter;
		}
		else
		{
			
			currentNode = currentNode->next;
			counter++;
		}
	}

	return index;
}

void LinkedList::deleteByIndex(int index)
{
	
	if (index >= 0)
	{
		std::shared_ptr<Node> deleteNode;
		
		if (index == 0)
		{
			deleteNode = this->head;

			
			this->head = deleteNode->next;
		}
		else
		{
			std::shared_ptr<Node> previousNode = this->head;
			std::shared_ptr<Node> currentNode = this->head;
			int counter = 0;

			
			while (counter < index)
			{
				
				previousNode = currentNode;
				currentNode = currentNode->next;
				counter++;
			}

			
			deleteNode = currentNode;
			
			previousNode->next = deleteNode->next;
		}
	}
}

void LinkedList::softDeleteByIndex(int index)
{
	
	if (index >= 0)
	{
		std::shared_ptr<Node> deleteNode;
		
		if (index == 0)
		{
			deleteNode = this->head;

			
			this->head = deleteNode->next;
		}
		else
		{
			std::shared_ptr<Node> previousNode = this->head;
			std::shared_ptr<Node> currentNode = this->head;
			int counter = 0;

			
			while (counter < index)
			{
				
				currentNode = currentNode->next;
				counter++;
			}

			
			deleteNode = currentNode;
			
			previousNode->next = deleteNode->next;
		}
		deleteNode->tile = std::make_shared<Tile>();
		
	}
}

std::shared_ptr<Tile> LinkedList::getByIndex(int index)
{
	std::shared_ptr<Node> foundNode;
	
	if (index >= 0)
	{
		
		if (index == 0)
		{
			foundNode = this->head;
		}
		else
		{
			std::shared_ptr<Node> currentNode = this->head;
			int counter = 0;

			
			while (counter < index)
			{
			
				currentNode = currentNode->next;
				counter++;
			}

			
			foundNode = currentNode;
		}
	}

	return foundNode->tile;
}

std::shared_ptr<Tile> LinkedList::popHead()
{
	std::shared_ptr<Tile> returnTile;

	returnTile = this->getHead()->tile;

	
	this->head = this->head->next;

	return returnTile;
}

int LinkedList::getSize()
{
	int counter = 0;

	std::shared_ptr<Node> currentNode = this->head;

	while (currentNode != nullptr)
	{
		
		currentNode = currentNode->next;
		counter++;
	}

	return counter;
}



void LinkedList::clear()
{
	this->head = nullptr;
}



void LinkedList::printList()
{
	
	std::shared_ptr<Node> currentNode = this->head;

	
	while (currentNode != nullptr)
	{
		std::shared_ptr<Tile> tile = currentNode->tile;
		tile->printTile();
		
		currentNode = currentNode->next;
	}
	std::cout << std::endl;
}

std::shared_ptr<Node> LinkedList::getHead()
{
	return this->head;
}

void LinkedList::shuffleLinkedList()
{
	
	std::vector<std::shared_ptr<Node>> vector =
	std::vector<std::shared_ptr<Node>>();

	std::shared_ptr<Node> currentNode = this->getHead();


	while (currentNode != nullptr)
	{
		vector.push_back(currentNode);
		currentNode = currentNode->next;
	}
	
	std::default_random_engine gen(time(0));

	std::shuffle(std::begin(vector), std::end(vector), gen);

	
	this->clear();

	while (vector.size() > 0)
	{
		std::shared_ptr<Node> node = vector.back();
		vector.pop_back();
		this->addFront(node->tile);
	}
}

void LinkedList::initiliseList(std::vector<std::string> tiles)
{
	for (std::vector<std::string>::iterator it = tiles.begin();
	 it != tiles.end(); it++)
	{
		
		std::string currentTile = *it;
		Colour colour = (Colour)currentTile.at(0);
		Shape shape = (Shape)currentTile.at(1);

		shape -= 48;
		addFront(std::make_shared<Tile>(colour, shape));
	}
}

std::string LinkedList::getListForDisplay()
{
	std::string list;

	std::shared_ptr<Node> currentNode = this->head;


	while (currentNode != nullptr)
	{
		std::shared_ptr<Tile> tile = currentNode->tile;
		list.append(tile->getTileString());
		list.append(",");
		
		currentNode = currentNode->next;
	}
	return list.substr(0, list.length() - 1);
}




