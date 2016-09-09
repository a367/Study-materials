#pragma once


class Heapsort
{
private:
	int* A;
	int len;
	int real_len;
public:
	Heapsort(int* x, int l) :A(x), len(l), real_len(l) { sort(); }
	int left(int i){return i * 2 + 1;}
	int right(int i){ return i * 2 + 2; }
	int parent(int i) { return (i - 1) / 2; }
	void swap(int& a, int& b) { int t = b; b = a; a = t; }
	void maxHeapify(int root)
	{
		int l = left(root), r = right(root);
		int largest = (l < len && A[root] < A[l]) ? l : root;
		largest = (r < len && A[largest] < A[r]) ? r : largest;
		if (largest != root)
		{
			swap(A[largest], A[root]);
			maxHeapify(largest);
		}
	}

	void buildMaxHeap()
	{
		for (int i = len / 2 - 1; i >= 0; i--)
			maxHeapify(i);
	}

	void sort()
	{
		buildMaxHeap();
		while(len > 1)
		{
			swap(A[0], A[--len]);
			maxHeapify(0);
		}

	}
	
};