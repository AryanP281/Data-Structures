
/***********************Preprocessor Directives********************/
#include <iostream>
#include "BinaryTree.h"

/***********************Functions********************/
template<typename T>
void BinaryTree<T>::InsertIntoTree(node* parent, node* toInsert)
{
	if (toInsert->data < parent->data)
	{
		if (parent->leftChild != nullptr)
			InsertIntoTree(parent->leftChild, toInsert);
		else
			parent->leftChild = toInsert;
	}
	else
	{
		if (parent->rightChild != nullptr)
			InsertIntoTree(parent->rightChild, toInsert);
		else
			parent->rightChild = toInsert;
	}

	return;
}

template<typename T>
Node<T>* BinaryTree<T>::SearchFor(node* parent, T data)
{
	if (parent->data == data)
		return parent;

	if (data < parent->data)
	{
		return parent->leftChild == nullptr ? nullptr : SearchFor(parent->leftChild, data);
	}
	else
		return parent->rightChild == nullptr ? nullptr : SearchFor(parent->rightChild, data);
}

template<typename T>
void BinaryTree<T>::InOrderTraverse(node* parent)
{
	//Checking if the parent has a left child
	if (parent->leftChild != nullptr)
	{
		//In-order traversing the left child
		InOrderTraverse(parent->leftChild);
	}

	//Printing the parent
	std::cout << parent->data << ", ";

	//Traversing the right child
	if (parent->rightChild != nullptr)
		InOrderTraverse(parent->rightChild);
}

template<typename T>
void BinaryTree<T>::PreOrderTraverse(node* parent)
{
	//Printing the parent
	std::cout << parent->data << ", ";

	//Traversing the left child
	if(parent->leftChild != nullptr)
		PreOrderTraverse(parent->leftChild);

	//Traversing the right child
	if (parent->rightChild != nullptr)
		PreOrderTraverse(parent->rightChild);
}

template<typename T>
void BinaryTree<T>::PostOrderTraverse(node* parent)
{
	//Traversing the left child
	if (parent->leftChild != nullptr)
		PostOrderTraverse(parent->leftChild);
	//Traversing the right child
	if (parent->rightChild != nullptr)
		PostOrderTraverse(parent->rightChild);
	//Printing the parent
	std::cout << parent->data << ", ";
}

template<typename T>
void BinaryTree<T>::DeallocateNodes(node* parent)
{
	//Checking if the node is a leaf node
	if (parent->leftChild == nullptr && parent->rightChild == nullptr)
	{
		delete parent;
		return;
	}
	else
	{
		//Deallocating the children nodes
		if (parent->leftChild != nullptr)
			DeallocateNodes(parent->leftChild);
		if (parent->rightChild != nullptr)
			DeallocateNodes(parent->rightChild);

		//Deallocating the parent nodes
		delete[] parent;

		return;
	}
}

/***********************Constructors And Destructors********************/
template<typename T>
BinaryTree<T>::BinaryTree()
{
	//Initializing root to null
	this->root = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	DeallocateNodes(this->root);
}

/***********************Methods********************/
template<typename T>
void BinaryTree<T>::Insert(T element)
{
	//Checking if its the root node
	if (this->root == nullptr)
	{
		this->root = new node;
		this->root->data = element;
		this->root->leftChild = nullptr;
		this->root->rightChild = nullptr;
		return;
	}

	//Adding new nodes to the tree
	node* nd = new node;
	nd->data = element;
	nd->leftChild = nullptr;
	nd->rightChild = nullptr;
	InsertIntoTree(this->root, nd);
}

template<typename T>
Node<T>* BinaryTree<T>::Search(T element)
{
	return SearchFor(this->root, element);
}

template<typename T>
void BinaryTree<T>::InOrderTraverseAndPrint()
{
	InOrderTraverse(this->root);
}

template<typename T>
void BinaryTree<T>::PreOrderTraverseAndPrint()
{
	PreOrderTraverse(this->root);
}

template<typename T>
void BinaryTree<T>::PostOrderTraverseAndPrint()
{
	PostOrderTraverse(this->root);
}