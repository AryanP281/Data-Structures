#pragma once

/**********************Preprocessor Directives*******************/

/**********************Structs*******************/
template<typename T>
struct Node
{
	T data; //The data stored in the node
	Node* next; //Pointer to the next node in the list

	Node() : Node(nullptr) {}
	Node(Node<T>* nextNode) { next = nextNode; }
	Node(T data, Node<T>* nextNode = nullptr) : Node(nextNode) { this->data = data; }
};

template<typename T>
struct DoubleLinkedNode
{
	T data; //The data stored in the node
	DoubleLinkedNode* next; //Pointer to the next node in the list
	DoubleLinkedNode* prev; //Pointer to the prev node in the list

	DoubleLinkedNode() : DoubleLinkedNode(nullptr, nullptr) {}
	DoubleLinkedNode(DoubleLinkedNode<T>* prevNode, DoubleLinkedNode<T>* nextNode)
	{ 
		next = nextNode; 
		prev = prevNode;
	}
	DoubleLinkedNode(T data, DoubleLinkedNode<T>* prevNode = nullptr, Node<T>* nextNode = nullptr) : DoubleLinkedNode(prevNode, nextNode)
	{ this->data = data; }
};