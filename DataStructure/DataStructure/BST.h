#pragma once

template <class T>
class BstNode
{
public:
	friend class BST<T>;
	BstNode(T x) :val(x) {}
	~BstNode() {}
private:
	T val;
	BstNode<T> *leftChild = NULL;
	BstNode<T> *rightChild = NULL;
};

template <class T>
class BST
{
public:
	BST() {}
	const 
	~BST() {}
private:
	
};