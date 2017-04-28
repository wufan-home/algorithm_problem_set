/*
  Given a 2d grid map of '1's (land) and '0's (water), 
  count the number of islands. An island is surrounded 
  by water and is formed by connecting adjacent lands horizontally or vertically. 
  You may assume all four edges of the grid are all surrounded by water.
  Example 1:
  11110
  11010
  11000
  00000
  Answer: 1
  Example 2:
  11000
  11000
  00100
  00011
  Answer: 3
*/

int numIslands(vector<vector<char> >& grid)
{
        if(grid.empty() || grid[0].empty())
		return 0;

	int offset[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int result = 0;
	for(int i = 0; i < grid.size(); ++i)
	{
		for(int j = 0; j < grid[0].size(); ++j)
		{
			if(grid[i][j] == '0' || grid[i][j] == '#')
				continue;

			++result;
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

	return result;
}
