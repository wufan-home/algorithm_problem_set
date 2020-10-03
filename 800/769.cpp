/*
  Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 10].
arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
*/

/*
 * Solution: This problem requires an ascending array. The key to the problem is that the values of one segment 
 * should be bigger than any elements before this group. It suffices as long as we show 
 * the values are bigger than any local maximum values of previous groups.
 * 1 - For a descending segment, they must be within a group.
 * 2 - For a ascending segement, We need to compare all the elements with the current local maximum value:
 * 2.1 - If they are bigger than the value, add a new group and update the maximum value.
 * 2.2. - If they are smaller than the value, check them with the previous maximum values:
 * 2.2.1 - If they are smaller than any of them, the previous groups should be merged into the current group.
 * 3 - For this reason, we use a stack to record of all previous maximum values. 
 * 
 * Similar questions: Trapper water.
 * */

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (arr.size() == 1)
            return 1;

        std::stack<int> stack_max;
        int maximum = INT_MIN;
        
        int size = arr.size();
        for (int i = 0; i < size; ++i) {
            if (arr[i] > maximum) {
                stack_max.push(arr[i]);
                maximum = arr[i];
            }
            else {
                while (!stack_max.empty()) {
                    if (arr[i] > stack_max.top())
                        break;
                        
                    stack_max.pop();
                }
                
                stack_max.push(maximum);
            }
        }
        
        return stack_max.size();
    }
};
