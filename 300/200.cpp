#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int numIslands(vector<vector<char> >& grid)
{
        if(grid.empty() || grid[0].empty())
		return 0;

	int offset[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int rv = 0;
	for(int i = 0; i < grid.size(); ++i)
	{
		for(int j = 0; j < grid[0].size(); ++j)
		{
			if(grid[i][j] == '0' || grid[i][j] == '#')
				continue;

			++rv;
			queue<pair<int, int> > pt_queue;
			pt_queue.push(make_pair(i, j));
			while(!pt_queue.empty())
			{
				pair<int, int> pt = pt_queue.front();
				pt_queue.pop();

				for(int k = 0; k < 4; ++k)
				{
					int x = pt.first + offset[k][0];
					int y = pt.second + offset[k][1];
					if( x >= 0 && x < grid.size() &&
					    y >= 0 && y < grid[0].size() &&
					    grid[x][y] == '1')
					{
						pt_queue.push(make_pair(x, y));
						grid[x][y] = '#';
					}
				}
			}
		}
	}

	for(int i = 0; i < grid.size(); ++i)
	{
		for(int j = 0; j < grid[0].size(); ++j)
		{
			if(grid[i][j] == '#')
				grid[i][j] = '1';
		}
	}

	return rv;
}
