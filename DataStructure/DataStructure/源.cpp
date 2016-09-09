#include <iostream>
#include "MyList.h"
#include "YList.h"
#include "HeapSort.h"
#include "Sort.h"
using namespace std;

int main()
{
	int A[] = { 0,4,5,1,3,2,4,6,2,3,4,5,69,3,2 };
	Sort<int> s(A, sizeof(A) / 4);
	s.QuickSort();
	for (int i = 0; i < sizeof(A)/4; i++)
		cout << A[i] << " ";

	system("pause");
	return 0;
}