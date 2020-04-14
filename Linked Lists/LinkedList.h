#pragma once

/**********************Preprocessor Directives*******************/
#include "Node.h"

/**********************Classes*******************/
template<typename T>
class LinkedList
{
private :
	Node<T>* head; //The head node

	//Functions
	bool Search(Node<T>* currentNode, T key) const /*Searches for the given key in the list*/
	{
		if (currentNode->data == key)
			return true;
		else if (currentNode->next == nullptr)
			return false;

		return Search(currentNode->next, key);
	}
	Node<T>* GetNode(Node<T>* startNode, int relPosition) const /*Returns the node at the given
	position (which is relative to startNode)*/
	{
		Node<T>* currentNode = startNode;
		for (int a = 0; a <= relPosition; ++a, currentNode = currentNode->next)
		{
			if (a == relPosition)
				return currentNode;
			else if (currentNode->next == nullptr)
				break;
		}

		return nullptr;
	}

public:
	//Constructors And Destructors
	LinkedList() : head(nullptr)
	{

	}
	
	~LinkedList()
	{
		int listLength = this->Length() - 1;
		for (; listLength > -1; --listLength)
		{
			Delete(listLength);
		}
	}

	//Methods
	const Node<T>* HeadNode() const //Returns the head node
	{
		return this->head;
	}

	void Push(T data) //Creates a node and adds it to the head of the list
	{
		Node<T>* node = new Node<T>(data); //Creating a node

		if (this->head != nullptr)
		{
			Node<T>* temp = this->head;
			this->head = node;
			this->head->next = temp;
		}
		else
			this->head = node;
	}
	void Insert(Node<T>* prevNode, T data) /*Creates
	a new node and inserts it after the given previous node*/
	{
		if (prevNode != nullptr)
		{
			Node<T>* newNode = new Node<T>(data); //Creating a new node

			Node<T>* temp = prevNode->next;
			prevNode->next = newNode;
			newNode->next = temp;
		}
		else
			throw std::exception("Pointer to previous node cannot be null");
	}

	bool Delete(T key) /*Delete's the node with the give key i.e data. Returns true if the node
	was found and deleted and false otherwise*/
	{
		//Checking if the head node is to be deleted
		if (this->head->data == key)
		{
			Node<T>* temp = this->head;
			this->head = temp->next;
			delete temp;
			return true;
		}

		Node<T>* currentNode = this->head;
		while (currentNode->next != nullptr)
		{
			if (currentNode->next->data == key)
			{
				Node<T>* temp = currentNode->next;
				currentNode->next = temp->next;
				delete temp;
				return true;
			}
			currentNode = currentNode->next;
		}

		return false;
	}

	bool DeleteAt(int position) /*Delete's the node with the give key i.e data. Returns true if the
	node was found and deleted and false otherwise*/
	{
		//Checking if the head node is to be deleted
		if (position == 0)
		{
			Node<T>* temp = this->head;
			this->head = temp->next;
			delete temp;
			return true;
		}

		Node<T>* currentNode = this->head;
		for (int a = 0; currentNode->next != nullptr; ++a, currentNode = currentNode->next)
		{
			if (a + 1 == position)
			{
				Node<char>* temp = currentNode->next;
				currentNode->next = temp->next;
				delete temp;
				return true;
			}
		}

		return false;
	}

	int Length() const /*Returns the length of the list*/
	{
		Node<T>* currentNode = this->head;
		int length = 0;
		while (currentNode != nullptr)
		{
			++length;
			currentNode = currentNode->next;
		}
		return length;
	}

	bool Exists(T key) /*Returns whether the given key exists in the list*/
	{
		return Search(this->head, key);
	}

	T Get(int position) /*Returns the data in the node at given the position*/
	{
		Node<T>* node = GetNode(this->head, position);

		if (node != nullptr)
			return node->data;
	}

	const Node<T>* NodeAt(int position) const /*Returns the node at the given position*/
	{
		return GetNode(this->head, position);
	}

};

