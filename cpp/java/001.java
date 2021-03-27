class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        HashMap<Integer, Integer> substractIndex = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; ++i) {
            if (substractIndex.containsKey(nums[i])) {
                res[0] = substractIndex.get(nums[i]);
                res[1] = i;
                break;
            }
            
            substractIndex.put(target - nums[i], i);
        }
        
        return res;
    }
}
