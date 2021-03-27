/*
    Given a sorted array, two integers k and x, find the k closest elements to x in the array. 
    The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

    Example 1:
    Input: [1,2,3,4,5], k=4, x=3
    Output: [1,2,3,4]
    Example 2:
    Input: [1,2,3,4,5], k=4, x=-1
    Output: [1,2,3,4]
    Note:
    The value k is positive and will always be smaller than the length of the sorted array.
    Length of the given array is positive and will not exceed 104
    Absolute value of elements in the array and x will not exceed 104
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.empty() || k == 0)
            return vector<int>();
        
        int l = 0;
        int r = arr.size() - 1;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(arr[mid] < x)
                l = mid + 1;
            else
                r = mid;
        }
        
        if(r == -1)
        {
            l = -1;
            r = 0;
        }
        else if(l == arr.size() - 1)
        {
            l = arr.size() - 1;
            r = arr.size();
        }
        else
            l = r - 1;
        
        vector<int> res;
        
        while(res.size() < k)
        {
            int left = l == -1 ? INT_MAX : x - arr[l];
            int right = r == arr.size() ? INT_MAX : arr[r] - x;
            
            if(left <= right)
                res.push_back(arr[l--]);
            else
                res.push_back(arr[r++]);
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};
