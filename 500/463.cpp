/*
    You are given a map in form of a two-dimensional integer grid 
    where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). 
    The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). 
    The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
    One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
    Determine the perimeter of the island.
    Example:
    [[0,1,0,0],
     [1,1,1,0],
     [0,1,0,0],
     [1,1,0,0]]
    Answer: 16
*/


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int max_island_perimeter = 0;
        
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                    max_island_perimeter = max(max_island_perimeter, get_perimeter(grid, i, j));
            }
        }
        
        return max_island_perimeter;
    }
    
private:
    const int steps[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    queue<pair<int, int>> queue_for_point;

    int get_perimeter(vector<vector<int>>& grid, const int x, const int y)
    {
        int perimeter = 0;
        grid[x][y] = -1;
        queue_for_point.push(make_pair(x, y));
        while(!queue_for_point.empty())
        {
            const int i = queue_for_point.front().first;
            const int j = queue_for_point.front().second;
            queue_for_point.pop();
            
            perimeter += get_perimeter_by_cell(grid, i, j);
        }
        
        return perimeter;
    }
    
    int get_perimeter_by_cell(vector<vector<int>>& grid, const int x, const int y)
    {
        int perimeter_by_cell = 0;
        for(int i = 0; i < 4; ++i)
        {
            if(x + steps[i][0] < 0 || 
                x + steps[i][0] >= grid.size() || 
                y + steps[i][1] < 0 || 
                y + steps[i][1] >= grid[0].size() ||
                grid[x + steps[i][0]][y + steps[i][1]] == 0)
                    ++perimeter_by_cell;
            else if(grid[x + steps[i][0]][y + steps[i][1]] == 1)
            {
                grid[x + steps[i][0]][y+ steps[i][1]] = -1;
                queue_for_point.push(make_pair(x + steps[i][0], y + steps[i][1]));
            }
        }
        
        return perimeter_by_cell;
    }
};
