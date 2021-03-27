class Solution:
    directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

    def dfs(self, grid: List[List[str]], i: int, j: int):
        if (i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] != '1'):
            return
        
        grid[i][j] = '2'
        for direction in self.directions:
            self.dfs(grid, i + direction[0], j + direction[1])
    
    def numIslands(self, grid: List[List[str]]) -> int:
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    res += 1
                    self.dfs(grid, i, j)
                    
        return res
