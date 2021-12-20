#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std;

class Graph
{
	vector <vector<int>> arc;

public:
	
	Graph(const vector<vector<int>>& x);
	void TopSort(const unordered_map<int, int>& numVertex);
};

