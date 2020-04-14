#pragma once
/**********************Preprocessor Directives*******************/
#include <exception>
#include "Node.h"

/**********************Classes*******************/

template<typename T>
class CircularLinkedList
{
private:
	Node<T>* last; //A pointer to the last node in the array

	//Functions
	Node<T>* GetNode(Node<T>* startNode, int relPosition) const /*Return the node at the given
	offset from the start node*/
	{
		Node<T>* currentNode = startNode;
		for (int a = 0; a <= relPosition; ++a)
		{
			currentNode = currentNode->next;
		}

		return currentNode;
	}

public:
	//Constructors And Destructors
	CircularLinkedList() : last(nullptr)
	{
	}
	~CircularLinkedList()
	{
		Node<T>* currentNode = this->last->next;
		while (currentNode != this->last)
		{
			Node<T>* temp = currentNode->next;
			delete currentNode;
			currentNode = temp;
		}

		delete currentNode;
	}


	//Methods
	const Node<T>* LastNode() const /*Returns the last node in the list*/
	{
		return this->last;
	}

	void Append(T data) /*Creates a node and adds it to the end of the list*/
	{
		//Creating a new Node
		Node<T>* newNode = new Node<T>;
		newNode->data = data;

		//Checking if the list is empty
		if (this->last == nullptr)
		{
			this->last = newNode;
			this->last->next = this->last;
			return;
		}

		//Appending node to non-empty list
		Node<T>* temp = this->last;
		this->last = newNode;
		this->last->next = temp->next;
		temp->next = this->last;
	}
	
	void Insert(Node<T>* prevNode, T data) /*Creates a new node and adds it after the
	given node*/
	{
		if (prevNode != nullptr)
		{
			//Creating a new node
			Node<T>* newNode = new Node<T>;
			newNode->data = data;

			Node<T>* temp = prevNode->next;
			prevNode->next = newNode;
			newNode->next = temp;
		}
		else
			throw std::exception("The node to add after cannot be null");
	}

	bool Delete(T key) /*Deletes the element with the given key from the list. Returns 
	true if the node was found and deleted*/
	{
	
		Node<T>* currentNode = this->last;

		do
		{
			if (currentNode->next->data == key)
			{
				Node<T>* temp = currentNode->next;
				//Checking if the last node is to be deleted
				if (temp == this->last)
					this->last = currentNode;
				currentNode->next = temp->next;
				delete temp;
				return true;
			}
			currentNode = currentNode->next;

		} while (currentNode->next != this->last->next);

		return false;
	}

	bool DeleteAt(int position) /*Deletes the element at the given postion from the list. Returns
	true if the node was found and deleted*/
	{

		Node<T>* prevNode = this->last;
		Node<T>* currentNode = this->last->next;
		int currentPos = 0;

		do
		{

			if (currentPos == position)
			{
				prevNode->next = currentNode->next;

				//Checking if the last node was deleted
				if (currentNode == this->last)
					this->last = prevNode;

				delete currentNode;
				return true;
			}

			//Updating the params
			prevNode = currentNode;
			currentNode = currentNode->next;
			++currentPos;

		} while (currentNode != this->last->next);

		return false;
	}

	bool Exists(T key) /*Returns true if a node with the given data exists in the list*/
	{
		Node<T>* currentNode = this->last->next;

		do
		{
			if (currentNode->data == key)
				return true;
			currentNode = currentNode->next;

		} while (currentNode != this->last->next);

		return false;
	}

	T Get(int position) /*Returns the data in the node at given the position*/
	{
		return GetNode(this->last->next, position)->data;
	}

	const Node<T>* NodeAt(int position) const /*Returns the node at the given position*/
	{
		return this->GetNode(this->last->next, position);
	}

};
