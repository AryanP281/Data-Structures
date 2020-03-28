#pragma once

/***********************Structs********************/
template<typename T> struct Node
{
	T data;
	Node* leftChild;
	Node* rightChild;
};

/***********************Classes********************/
template<typename T> class BinaryTree
{
private:
	typedef Node<T> node;

	node* root;

	//Functions
	void InsertIntoTree(node* parent, node* nodeToInsert); //Inserts the node in the appropriate location
	void DeallocateNodes(node* parent); //Deallocates the memory used by the nodes
	node* SearchFor(node* parent, T data); //Searches for the given element in the tree
	void InOrderTraverse(node* parent); //Prints the data in the nodes using in-order traversal
	void PreOrderTraverse(node* parent); //Prints the data in the nodes using pre-order traversal
	void PostOrderTraverse(node* parent); //Prints the data in the nodes using post-order traversal

public:
	//Constructors And Destructors
	BinaryTree();
	~BinaryTree();

	//Methods
	void Insert(T element); //Inserts a new node in the tree
	node* Search(T element); //Searches and returns the node with the given element
	void InOrderTraverseAndPrint(); //Prints the nodes' data using In-Order traverse
	void PreOrderTraverseAndPrint(); //Prints the nodes' data using Pre-Order traverse
	void PostOrderTraverseAndPrint(); //Prints the nodes' data using Post-Order traverse
};