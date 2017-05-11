/*
    Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

    For example,
    Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
     1 [3  -1  -3] 5  3  6  7       3
     1  3 [-1  -3  5] 3  6  7       5
     1  3  -1 [-3  5  3] 6  7       5
     1  3  -1  -3 [5  3  6] 7       6
     1  3  -1  -3  5 [3  6  7]      7
    Therefore, return the max sliding window as [3,3,5,5,6,7].

    Note: 
    You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

    Follow up:
    Could you solve it in linear time?
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty() || k == 0 || k > nums.size())
            return vector<int>();
            
        vector<int> maximums;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i >= k)
                removeElement(i - k);

            int maximum = addNewElement(nums[i], i);
            
            if(i >= k - 1)
                maximums.push_back(maximum);
        }
        
        return maximums;
    }
private:
    struct ListNode
    {
        int val;
        int index;
        ListNode *next;
        
        ListNode(int val, int index) : val(val), index(index), next(NULL) {}
    };
    
    int addNewElement(int val, int index)
    {
        if(sortedWindow == NULL)
            sortedWindow = new ListNode(val, index);
        else if(val >= sortedWindow->val)
        {
            ListNode *temp = sortedWindow;
            sortedWindow = new ListNode(val, index);
            sortedWindow->next = temp;
        }
        else
        {
            for(ListNode *cur = sortedWindow; cur != NULL; cur = cur->next)
            {
                if(cur->next == NULL)
                {
                    cur->next = new ListNode(val, index);
                    break;
                }
                else if(val >= cur->next->val)
                {
                    ListNode *temp = cur->next;
                    cur->next = new ListNode(val, index);
                    cur->next->next = temp;
                    break;
                }
            }
        }

        return max(val, sortedWindow->val);
    }
    
    void removeElement(int invalidIndex)
    {
        if(sortedWindow->index == invalidIndex)
        {
            ListNode *temp = sortedWindow->next;
            delete sortedWindow;
            sortedWindow = temp;
        }
        else
        {
            for(ListNode *cur = sortedWindow; cur->next != NULL; cur = cur->next)
            {
                if(cur->next->index == invalidIndex)
                {
                    ListNode *temp = cur->next->next;
                    delete cur->next;
                    cur->next = temp;
                    break;
                }
            }
        }
    }
    
    ListNode *sortedWindow;
};
