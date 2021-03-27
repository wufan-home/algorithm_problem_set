/*
	Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
	find the area of largest rectangle in the histogram.

	Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

	The largest rectangle is shown in the shaded area, which has area = 10 unit.

	For example,
	Given heights = [2,1,5,6,2,3],
	return 10.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        
        heights.push_back(0);
        stack<pair<int, int>> st;
        for(int i = 0; i < heights.size(); ++i)
        {
            if(st.empty() || heights[i] > st.top().second)
            {
                st.push(make_pair(1, heights[i]));
                continue;
            }
            
            int height = 0;
            int width = 0;
            for(; !st.empty() && st.top().second >= heights[i]; st.pop())
            {
                height = st.top().second;
                width += st.top().first;
                res = max(res, height * width);
            }
            
            res = max(res, min(height, heights[i]) * (++width));
            st.push(make_pair(width, min(height, heights[i])));
        }
        
        return res;
    }
};
