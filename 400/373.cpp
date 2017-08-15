/*
    You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

    Define a pair (u,v) which consists of one element from the first array and one element from the second array.

    Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

    Example 1:
    Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

    Return: [1,2],[1,4],[1,6]

    The first 3 pairs are returned from the sequence:
    [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
    Example 2:
    Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

    Return: [1,1],[1,1]

    The first 2 pairs are returned from the sequence:
    [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
    Example 3:
    Given nums1 = [1,2], nums2 = [3],  k = 3 

    Return: [1,3],[2,3]

    All possible pairs are returned from the sequence:
    [1,3],[2,3]
    Credits:
    Special thanks to @elmirap and @StefanPochmann for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        int size1 = nums1.size();
        int size2 = nums2.size();
        for(int i = 0; i < size1; ++i)
        {
            for(int j = 0; j < size2; ++j)
            {
                int sum = nums1[i] + nums2[j];
                pq.push(vector<int>({sum, nums1[i], nums2[j]}));
                if(pq.size() > k)
                    pq.pop();
            }
        }
        
        vector<pair<int, int>> res;
        for(; !pq.empty(); pq.pop())
            res.push_back(make_pair(pq.top()[1], pq.top()[2]));
        
        return res;
    }
    
private:
    struct compare
    {
        bool operator() (const vector<int> &l, const vector<int> &r) 
        {
            return l[0] < r[0];
        }
    };
};
