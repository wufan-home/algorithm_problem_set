// 206.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <utility>
#include <unordered_set>
#include <iostream>
#include <stack>

using namespace std;

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	if (numCourses == 0 || prerequisites.empty())
		return true;

	const int& n = numCourses;
	const vector<pair<int, int>>& p = prerequisites;

	vector<vector<int>> deps(n, vector<int>(n, 0));
	for (int i = 0; i < p.size(); ++i)
	{
		deps[p[i].first][p[i].second] = 1;
		++deps[p[i].second][p[i].second];
	}

	vector<int> schedule;
	for (int i = 0; i < n; ++i)
	{
		if (deps[i][i] == 0)
		{
			unordered_set<int> visited;
			stack<int> node_stack;
			node_stack.push(i);
			while (!node_stack.empty())
			{
				int cur = node_stack.top();
				node_stack.pop();
				for (int j = 0; j < n; ++j)
				{
					if (j == cur || !deps[cur][j])
						continue;
					if (visited.find(j) != visited.end())
						return false;
					if (find(schedule.begin(), schedule.end(), j) == schedule.end())
					{
						visited.insert(j);
						schedule.push_back(j);
						node_stack.push(j);
					}
				}
				visited.insert(cur);
				schedule.push_back(cur);
			}
		}
	}

	return schedule.size() == n;
}

int main()
{
	vector<pair<int, int>> pres(1, make_pair(0, 1));
	pres.push_back(make_pair(1, 2));
	pres.push_back(make_pair(2, 3));
	pres.push_back(make_pair(3, 0));
	pres.push_back(make_pair(4, 3));
	cout << canFinish(5, pres) << endl;
    return 0;
}

