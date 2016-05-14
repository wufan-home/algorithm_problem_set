#include <vector>
#include <set>
#include <stack>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool TopoSort(vector<vector<int> >& edges, int start,
	      unordered_set<int>& visited, vector<int>& result)
{
	//Kahn algo.
	if(edges[start].empty())
	{
		result.push_back(start);
		return true;
	}

	while(!edges[start].empty())
	{
		vector<int>::iterator it = edges[start].end() - 1;
		if(find(result.begin(), result.end(), *it) != result.end())
			edges[start].pop_back();
		else
		{
			if(visited.find(*it) != visited.end())
				return false;

			visited.insert(*it);
			if(!TopoSort(edges, *it, visited, result))
				return false;
			visited.erase(*it);
		}
	}

	return true;
}

bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites)
{
	if(numCourses == 0 || prerequisites.empty())
		return true;

	vector<vector<int> > edges(numCourses, vector<int>());
	for(int i = 0; i < prerequisites.size(); ++i)
		edges[prerequisites[i].second].push_back(prerequisites[i].first);

	vector<int> result;
	unordered_set<int> visited;
	for(int i = 0; i < numCourses; ++i)
	{
		if(!TopoSort(edges, i, visited, result))
			return false;
	}

	return true;
}


int main()
{
	/*8
[[1,0],[2,6],[1,7],[5,1],[6,4],[7,0],[0,5],[5,1],[6,4]]*/
	vector<pair<int, int> > pres;
	pres.push_back(make_pair(1, 0));
	pres.push_back(make_pair(2, 6));
	pres.push_back(make_pair(1, 7));
	pres.push_back(make_pair(5, 1));
	pres.push_back(make_pair(6, 4));
	pres.push_back(make_pair(7, 0));
	pres.push_back(make_pair(0, 5));
	pres.push_back(make_pair(5, 1));
	pres.push_back(make_pair(6, 4));
	cout << canFinish(8, pres) << endl;
	return 1;
}
