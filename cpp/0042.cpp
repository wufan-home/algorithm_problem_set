/*
	Given n non-negative integers representing an elevation map where the width of each bar is 1, 
	compute how much water it is able to trap after raining.
	For example, 
	Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3)
            return 0;
        
        int waterAmount = 0;
        stack<int> stackForPositions;
        for(int i = 0; i < height.size(); ++i)
        {
            if(isIndexOfLocalPeak(height, i))
            {
                const int curHeight = height[i];
                while(stackForPositions.size() > 1)
                {
                    const int lastHeight = height[stackForPositions.top()];
                    if(lastHeight >= curHeight)
                        break;
                        
                    stackForPositions.pop();
                }
                
                if(stackForPositions.size() == 1 && height[stackForPositions.top()] <= curHeight)
                {
                    const int lastHeightIndex = stackForPositions.top();
                    stackForPositions.pop();
                    waterAmount += computeWaterAmount(height, lastHeightIndex, i);
                }
                
                stackForPositions.push(i);
            }
        }
        
        while(stackForPositions.size() > 1)
        {
            int right = stackForPositions.top();
            stackForPositions.pop();
            waterAmount += computeWaterAmount(height, stackForPositions.top(), right);
        }
        
        return waterAmount;
    }
    
private:
    bool isIndexOfLocalPeak(const vector<int>& height, int index)
    {
        return index == 0 || 
                (index == height.size() - 1 && height[index] > height[index - 1]) || 
                (height[index - 1] < height[index] && height[index] >= height[index + 1]) ||
                (height[index - 1] <= height[index] && height[index] > height[index + 1]); 
    }
    
    int computeWaterAmount(const vector<int>& height, int start, int end)
    {
        int waterAmount = 0;
        int minHeight = min(height[start], height[end]);
        for(int i = start + 1; i < end; ++i)
            waterAmount += minHeight - (height[i] > minHeight ? minHeight : height[i]);
            
        return waterAmount;
    }
};
