/*
    Find the contiguous subarray within an array (containing at least one number) which has the largest product.

    For example, given the array [2,3,-2,4],
    the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxValue = INT_MIN;
       
        int maxPositiveProduct = 1;
        int minNegativeProduct = INT_MIN;
        for(int i = 0; i < nums.size(); ++i)
        {
            maxPositiveProduct *= nums[i];
            maxValue = max(maxValue, maxPositiveProduct);
            if(nums[i] == 0)
            {
                maxPositiveProduct = 1;
                minNegativeProduct = INT_MIN;
            }
            else if(nums[i] > 0)
            {
                if(minNegativeProduct > INT_MIN)
                    minNegativeProduct *= nums[i];
            }
            else
            {
                if(minNegativeProduct > INT_MIN)
                {
                    minNegativeProduct *= nums[i];
                    maxValue = max(maxValue, minNegativeProduct);
                    swap(maxPositiveProduct, minNegativeProduct);
                }
                else
                {
                    minNegativeProduct = maxPositiveProduct;
                    maxPositiveProduct = 1;
                }
            }
        }
        
        return maxValue;
    }
};
