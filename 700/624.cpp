/*
    Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.

    Example 1:
    Input: 
    [[1,2,3],
     [4,5],
     [1,2,3]]
    Output: 4
    Explanation: 
    One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
    Note:
    Each given array will have at least 1 number. There will be at least two non-empty arrays.
    The total number of the integers in all the m arrays will be in the range of [2, 10000].
    The integers in the m arrays will be in the range of [-10000, 10000].
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        if(arrays.size() < 2)
            return 0;

        unordered_map<int, vector<int>> valueToIndexList;
        vector<int> distincts;
        
        for(int i = 0; i < arrays.size(); ++i)
        {
            for(int j = 0; j < arrays[i].size(); ++j)
            {
                if(valueToIndexList.find(arrays[i][j]) == valueToIndexList.end())
                {
                    valueToIndexList[arrays[i][j]] = vector<int>();
                    distincts.push_back(arrays[i][j]);
                }
                else if(valueToIndexList[arrays[i][j]][valueToIndexList[arrays[i][j]].size() - 1] == i)
                    continue;
                
                valueToIndexList[arrays[i][j]].push_back(i);
            }
        }
        
        int maxDist = 0;
        sort(distincts.begin(), distincts.end());
        
        for(int r = distincts.size() - 1; r >= 0; --r)
        {
            for(int l = 0; l < r; ++l)
            {
                if(valueToIndexList[distincts[l]].size() > 1 || 
                    valueToIndexList[distincts[r]].size() > 1 || 
                    valueToIndexList[distincts[l]][0] != valueToIndexList[distincts[r]][0])
                        maxDist = max(maxDist, distincts[r] - distincts[l]);
            }
        }
        
        return maxDist;
    }
};
