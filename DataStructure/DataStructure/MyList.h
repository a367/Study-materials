#pragma once
#include <iostream>
using namespace std;

template<class T>
class ListNode
{
public:
	T val;
	ListNode* next;
	ListNode(T x) : val(x), next(NULL){}
};


template<class T>
class MyList
{
private:
	int size = 0;
	ListNode<T>* head = NULL;
	ListNode<T>* tail = NULL;
public:
	MyList() {}
	
	void push_back(T m_val)
	{
		if (size == 0)
		{
			head = new ListNode<T>(m_val);
			tail = head;
		}
		else
		{
			tail->next = new ListNode<T>(m_val);
			tail = tail->next;
		}
		size++;
	}

	void pop_back()
	{
		if (size == 0)
			return;
		if (size == 1)
		{
			delete head;
			size--;
			return;
		}
			
		ListNode<T> *cur = head;
		while (cur->next != tail)
			cur = cur->next;
		cur->next == NULL;
		delete tail;
		tail = cur;
		size--;
	}

	void print()
	{
		ListNode<T> *cur = head;
		while (cur != NULL)
		{
			cout << cur->val << endl;
			cur = cur->next;
		}
	}

	~MyList()
	{
		ListNode<T> *cur = head, *next;
		while (cur != NULL)
		{
			next = cur->next;
			delete cur;
			cur = next;
		}
	}
};