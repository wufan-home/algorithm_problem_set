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
        int ans = 0;
        int size = heights.size();
        stack<pair<int, int>> st;
        st.push({heights[0], 1});
        for (int i = 1; i < size; ++i) {
            if (heights[i] >= st.top().first) {
                st.push({heights[i], 1});
                continue;
            }
            
            int h = 0;
            int w = 0;
            for (; !st.empty() && st.top().first >= heights[i]; st.pop()) {
                h = st.top().first;
                w += st.top().second;
                ans = max(ans, h * w);
            }
            
            h = min(h, heights[i]);
            w += 1;
            st.push({h, w});
        }
        
        for (int h = 0, w = 0; !st.empty(); st.pop()) {
            h = st.top().first;
            w += st.top().second;
            ans = max(ans, h * w);
        }
        
        return ans;
    }
};
