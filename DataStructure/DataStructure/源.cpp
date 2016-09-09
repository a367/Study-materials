#include <iostream>
#include "MyList.h"
#include "YList.h"
#include "HeapSort.h"
#include "Sort.h"
#include "ShortestPath.h"
#define maxValue 0x7fffffff
using namespace std;


int main()
{
	/*int A[] = { 0,4,5,1,3,2,4,6,2,3,4,5,69,3,2 };
	Sort<int> s(A, sizeof(A) / 4);
	s.QuickSort();
	for (int i = 0; i < sizeof(A)/4; i++)
		cout << A[i] << " ";
*/

	int A[6][6] = { {0,7,9,maxValue ,maxValue ,14},
					{7,0,10,15,maxValue,maxValue},
					{9,10,0,11,maxValue,2},
					{ maxValue ,15,11,0,6,maxValue },
					{ maxValue ,maxValue ,maxValue ,6,0,9},
					{14,maxValue ,2,maxValue ,9,0} };
	
	ShortestPath<int> sp((int**)A, 6, maxValue);
	sp.Dijkstra(0);
	system("pause");
	return 0;
}