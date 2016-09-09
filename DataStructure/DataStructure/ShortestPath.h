#pragma once
#include <iostream>
using namespace std;

template <class T>
class ShortestPath
{
public:
	ShortestPath(T** graph, int num, T max_value) 
		: G(graph), n(num), maxValue(max_value){}
	void Dijkstra(int start);
private:
	T **G;
	int n;
	T maxValue;
	T min(T a, T b) { return a < b ? a : b; }
};

template <class T>
void ShortestPath<T>::Dijkstra(int start)
{
	T *Dist = new T[n];
	for (int i = 0; i < n; i++)
		Dist[i] = i == start ? 0 : maxValue;

	for (int c = 0; c < n; c++)
	{
		int min_i; T min_v = maxValue;
		for (int i = 0; i < n;i++)
			if (min_v>Dist[i]) { min_i = i; min_v = Dist[i]; }
		for (int j = 0; j < n; j++)
			if (j != min_i) Dist[j] = min(Dist[j], Dist[min_i] + G[min_i][j]);
	}

	for (int i = 0; i < n; i++)
		cout << Dist[i] << " ";
	delete[] Dist;
}