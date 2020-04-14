#pragma once
/*******************Preprocessor Directives**************/
#include <exception>
#include "Node.h"

/*******************Classes**************/
template<typename T>
class DoublyLinkedList
{
private:
	//Variables
	DoubleLinkedNode<T>* head;

	//Functions
	DoubleLinkedNode<T>* NodeAt(DoubleLinkedNode<T>* startNode, int relPosition) const /*Finds
	and returns the node at the give position relative to the given start node*/
	{
		DoubleLinkedNode<T>* currentNode = startNode;

		//Setting the step direction depending on the desired traversal direction
		int step = relPosition < 0 ? -1 : 1;

		for (int a = 0; std::abs(a) <= std::abs(relPosition); a += step)
		{
			if (std::abs(a) == std::abs(relPosition))
				return currentNode;

			if (step == -1 && currentNode->prev == nullptr)
				break;
			else if (step == 1 && currentNode->next == nullptr)
				break;

			//Moving to the next node
			currentNode = step == -1 ? currentNode->prev : currentNode->next;
		}

		return nullptr;

	}

public:

	//Constructors And Destructors
	DoublyLinkedList() : head(nullptr)
	{
	}

	~DoublyLinkedList()
	{
		DoubleLinkedNode<T>* currentNode = this->head;
		while (currentNode != nullptr)
		{
			DoubleLinkedNode<T>* temp = currentNode->next;
			delete currentNode;
			currentNode = temp;
		}
	}

	//Methods
	const DoubleLinkedNode<T>* GetHead() const /*Returns the head of the list*/
	{
		return this->head;
	}

	int Length() const /*Returns the length of the list*/
	{
		DoubleLinkedNode<T>* currentNode = this->head;
		int length = 0;
		while (currentNode != nullptr)
		{
			++length;
			currentNode = currentNode->next;
		}

		return length;
	}

	void Push(T data) /*Creates a new node and add it to the front i.e makes it the head*/
	{
		DoubleLinkedNode<T>* node = new DoubleLinkedNode<T>;
		node->data = data;

		//Checking if the list is empty
		if (this->head == nullptr)
		{
			this->head = node;
			this->head->next = nullptr;
			this->head->prev = nullptr;
			return;
		}

		//Setting the new node as the head node
		node->next = this->head;
		node->prev = nullptr;
		this->head->prev = node;
		this->head = node;
	}

	void InsertAt(int position, T data) /*Creates a new node and inserts it at the given position*/
	{
		DoubleLinkedNode<T>* prevNode = this->NodeAt(this->head, position);
		if (prevNode == nullptr)
			throw std::exception("Index out of range");

		//Creating a new node
		DoubleLinkedNode<T>* newNode = new DoubleLinkedNode<T>;
		newNode->data = data;

		//Placing the node
		newNode->prev = prevNode->prev;
		newNode->next = prevNode;
		prevNode->prev = newNode;
		if(newNode->prev != nullptr)
			newNode->prev->next = newNode;

		//Checking if the node was added to head
		if (position == 0)
			this->head = newNode;
	}

	bool Delete(T key) /*Deletes the node with the given key from the list. Returns true
	if the node was found and deleted*/
	{
		DoubleLinkedNode<T>* currentNode = this->head;

		//Checking if the head node is to be deleted
		if (this->head->data == key)
		{
			DoubleLinkedNode<T>* temp = this->head;
			if (this->head->next != nullptr)
			{
				this->head->next->prev = nullptr;
				this->head = this->head->next;
			}
			else
				this->head = nullptr;

			delete temp;
			return true;
		}

		while (currentNode != nullptr)
		{
			if (currentNode->data == key)
			{
				currentNode->prev->next = currentNode->next;
				if (currentNode->next != nullptr)
					currentNode->next->prev = currentNode->prev;
				delete currentNode;
				return true;
			}

			currentNode = currentNode->next;
		}

		return false;
	}

	bool DeleteAt(int relPosition, DoubleLinkedNode<T>* startNode = nullptr) /*Deletes
	the node at the given position relative to the start node*/
	{
		if (startNode == nullptr)
			startNode = this->head;
		
		DoubleLinkedNode<T>* node = NodeAt(startNode, relPosition);
		if (node == nullptr)
			return false;

		//Checking if the node to be deleted is the head
		if (node == this->head)
		{
			if (node->next != nullptr)
				node->next->prev = nullptr;
			this->head = node->next;
			delete node;
			return true;
		}

		if (node->prev != nullptr)
			node->prev->next = node->next;
		if (node->next != nullptr)
			node->next->prev = node->prev;
		delete node;

		return true;
	}

	T Get(int relPosition, DoubleLinkedNode<T>* startNode = nullptr) /*Returns the data
	stored in the node at the given position*/
	{
		if (startNode == nullptr)
			startNode = this->head;
		
		return NodeAt(startNode, relPosition)->data;
	}

	const DoubleLinkedNode<T>* GetNode(int relPosition, DoubleLinkedNode<T>* startNode = nullptr)
	/*Returns the node at the given position*/
	{
		if (startNode == nullptr)
			startNode = this->head;
		
		return NodeAt(startNode, relPosition);
	}

};
