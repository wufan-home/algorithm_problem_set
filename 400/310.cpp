/*
   For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3

return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5

return [3, 4]

Hint:

    How many MHTs can a graph have at most?

    Note:

(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”

(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf. 
*/

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <queue>

using namespace std;

vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges)
{
	vector<int> rv;
	if(n == 0)
		return rv;

	if(edges.empty())
	{
		for(int i = 0; i < n; ++i)
			rv.push_back(i);
		return rv;
	}

	vector<unordered_set<int> > adj(n, unordered_set<int>());
	for(int i = 0; i < edges.size(); ++i)
	{
		adj[edges[i].first].insert(edges[i].second);
		adj[edges[i].second].insert(edges[i].first);
	}
	
	queue<int> leaves;
	for(int i = 0; i < n; ++i)
	{
		if(adj[i].size() == 1)
			leaves.push(i);
	}

	while(!leaves.empty())
	{
		int cur = leaves.front();
		if((leaves.size() == 1) ||
		   (leaves.size() == 2 &&
		    adj[*adj[cur].begin()].size() == 1))
			break;
		else
		{
			leaves.pop();
			int parent = *adj[cur].begin();
			adj[parent].erase(cur);
			adj[cur].clear();
			if(adj[parent].size() == 1)
				leaves.push(parent);
		}

		for(int i)
	}

	for(; !leaves.empty(); leaves.pop())
		rv.push_back(leaves.front());

	return rv;
}

/*

*/

int main()
{
	vector<pair<int, int> > edges;
	edges.push_back(make_pair(0, 3));
	edges.push_back(make_pair(1, 3));	
	edges.push_back(make_pair(2, 3));
	//edges.push_back(make_pair(4, 3));
	//edges.push_back(make_pair(5, 4));
	vector<int> rv = findMinHeightTrees(4, edges);
	for(int i = 0; i < rv.size(); ++i)
		cout << rv[i] << ", ";
	cout << endl;
}
