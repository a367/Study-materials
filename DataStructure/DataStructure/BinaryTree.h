#pragma once
#include <iostream>
using namespace std;

template<class T>
class BinartTreeNode
{
public:
	friend class BinaryTree;
	BinartTreeNode(T x, BinartTreeNode<T> *left, BinartTreeNode<T> *right) :
		val(x), left_child(left), right_child(right) {}
private:
	T val;
	BinartTreeNode<T> *left_child, *right_child;
};

template <class T>
class BinaryTree
{
public:
	BinaryTree() {}
	~BinaryTree() {}
private:
	BinartTreeNode<T> *root = NULL;
};