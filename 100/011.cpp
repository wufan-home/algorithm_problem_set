/*
  Given n non-negative integers a1, a2, ..., an, 
  where each represents a point at coordinate (i, ai). 
  n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
  Find two lines, which together with x-axis forms a container, such that the container contains the most water.
  Note: You may not slant the container.

  Solution: Greedy method. Since the height is determined by the min value of two vertical lines, 
  the height won't increase if we move the longer vertical line. The width always decreases, then
  it implies better solution, i.e., a larger container, can only be obtained by moving the shorter vertical line.
*/

int maxArea(vector<int>& height) {
        if(height.size() < 2)
		return 0;

	int max_area = 0;
	for(int s = 0, e = height.size() - 1; s < e;)
	{
		int area = (e - s) * min(height[s], height[e]);
		max_area = max(area, max_area);
		height[s] <= height[e] ? ++s : --e;
	}

	return max_area;
}
 
