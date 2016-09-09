#pragma once
#include <iostream>
#include <string>
#include "MyList.h"
using namespace std;


class YList
{
private:
	ListNode<char> *head1 = NULL;
	ListNode<char> *head2 = NULL;
	ListNode<char> *comm = NULL;
	int len1 = 0;
	int len2 = 0;
	int comm_len = 0;
public:
	YList(string s1, string s2)
	{
		int n1 = s1.size(), n2 = s2.size();
		
		while (s1[n1 - comm_len - 1] == s2[n1 - comm_len - 1])
			comm_len++;
		len1 = n1 - comm_len;
		len2 = n2 - comm_len;

		head1 = new ListNode<char>(s1[0]);
		head2 = new ListNode<char>(s2[0]);
		
		ListNode<char> *tail1 = head1;
		for (int i = 1; i < len1; i++)
		{
			tail1->next = new ListNode<char>(s1[i]);
			tail1 = tail1->next;
		}

		ListNode<char> *tail2 = head2;
		for (int i = 1; i < len1; i++)
		{
			tail2->next = new ListNode<char>(s2[i]);
			tail2 = tail2->next;
		}
		if (comm_len != 0)
		{
			comm = new ListNode<char>(s1[len1]);
			ListNode<char> *cur = comm;
			tail1->next = comm; tail2->next = comm;

			for (int i = len1+1; i < n1; i++)
			{
				cur->next = new ListNode<char>(s1[i]);
				cur = cur->next;
			}
		}
	}

	void print()
	{
		cout << "s1:";
		ListNode<char>* cur = head1;
		while (cur != NULL)
		{
			cout << cur->val;
			cur = cur->next;
		}
		
		cout << endl << "s2:";
		cur = head2;
		while (cur != NULL)
		{
			cout << cur->val;
			cur = cur->next;
		}
		cout << endl;
	}

	~YList()
	{
		ListNode<char> *cur = head1, *next;
		while (cur != comm)
		{
			next = cur->next;
			delete cur;
			cur = next;
		}

		cur = head2;
		while (cur != comm)
		{
			next = cur->next;
			delete cur;
			cur = next;
		}

		cur = comm;
		while (cur != NULL)
		{
			next = cur->next;
			delete cur;
			cur = next;
		}

	}
};