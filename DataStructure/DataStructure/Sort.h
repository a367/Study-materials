#pragma once

template <class T>
class Sort
{
public:
	Sort(T *Array, int l) : A(Array), len(l) {}
	~Sort() { }

	void BubbleSort()
	{
		for (int i = 0; i < len; i++)
			for (int j = 1; j < len - i; j++)
				if (A[j] < A[j - 1]) swap(A[j], A[j - 1]);
	}

	void InsertSort()
	{
		for (int i = 1; i < len; i++)
		{
			T k = A[i]; int j = i - 1;
			for (; j > 0 && A[j] > k; j--)
				A[j + 1] = A[j];
			A[j + 1] = k;
		}
	}

	void SelectSort()
	{
		for (int i = 0; i < len; i++)
		{
			T m_min = A[i]; int m_i = i;
			for (int j = i + 1; j < len; j++)
				if (m_min > A[j]) { m_min = A[j]; m_i = j; }
			swap(A[m_i], A[i]);
		}
	}

	void QuickSort(int l = 0, int r = -1)
	{
		if (r == -1) r = len;
		if (l > r - 2) return;
		int m = partition(l, r);
		QuickSort(l, m);
		QuickSort(m + 1, r);
	}
	
	void MergeSort()
	{
		int l = 0, r = len;
		L = new T[len / 2 + 1]; R = new T[len / 2 + 1];
		MergeSortByRecursion(l, r);
		delete[] L, R;
	}

	

private:
	T *A, *L, *R;
	int len;
	int partition(int l, int r)
	{
		T x = A[r - 1];
		for (int j = l; j < r - 1; j++)
			if (A[j] <= x) swap(A[l++], A[j]);
		swap(A[l], A[r - 1]);
		return l;
	}
	void merge(int l, int m, int r)
	{
		int n1 = m - l, n2 = r - m;
		for (int i = 0; i < n1; i++)
			L[i] = A[l + i];
		for (int i = 0; i < n2; i++)
			R[i] = A[m + i];

		int i = 0, j = 0, k = l;
		while(i < n1 && j < n2)
			A[k++] = L[i] <= R[j] ? L[i++] : R[j++];
		while (i < n1) A[k++] = L[i++];
		while (j < n2) A[k++] = R[j++];
	}
	void MergeSortByRecursion(int l, int r)
	{
		if (l > r - 2) return;
		int m = (l + r) / 2;
		MergeSortByRecursion(l, m);
		MergeSortByRecursion(m, r);
		merge(l, m, r);
	}
	void swap(T& a, T& b) { T c = b; b = a; a = c; }
};