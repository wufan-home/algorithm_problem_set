/*
 * Follow up for H-Index: What if the citations array is sorted in ascending order? 
 * Could you optimize your algorithm?
 
    []
    [0,0,0]
    [1]
    [1, 1, 1]
    [0,1,3,5,6]
 */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int l = 0;
        int r = size - 1;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(citations[mid] == size - mid)
                return size - mid;
            else if(citations[mid] > size - mid)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return size - l;
    }
};
