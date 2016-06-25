/*
  Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
  Find all unique quadruplets in the array which gives the sum of target.
  Note: The solution set must not contain duplicate quadruplets.
  For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
  A solution set is:
  [
    [-1,  0, 0, 1],
    [-2, -1, 1, 2],
    [-2,  0, 0, 2]
  ]

  Solution: The key of the solution is to cut off the branches that do not need to reach.
*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > rv;
        if(nums.size() < 4)
    		return rv;
    
    	sort(nums.begin(), nums.end());
    	for(int i4 = nums.size() - 1; i4 >= 3;)
    	{
    	    if(nums[i4] + nums[i4 - 3] + nums[i4 - 2] + nums[i4 - 1] < target)
    	        break;
    	        
    	    if(nums[i4] + nums[0] + nums[1] + nums[2] <= target)
    	    {
    		    for(int i3 = i4 - 1; i3 >= 2;)
    		    {
    		        if(nums[i4] + nums[i3] + nums[i3 - 2] + nums[i3 - 1] < target)
    		            break;
    		      
    		        if(nums[i4] + nums[i3] + nums[1] + nums[0] <= target)
    		        {
    			        int t1 = target - nums[i3] - nums[i4];
    			        for(int i1 = 0, i2 = i3 - 1; i1 < i2;)
    			        {
    				        int sum = nums[i1] + nums[i2];
    				        if(t1 == sum)
    				        {
    					        vector<int> cand(1, nums[i1]);
    					        cand.push_back(nums[i2]);
    					        cand.push_back(nums[i3]);
    					        cand.push_back(nums[i4]);
    					        rv.push_back(cand);
    				        }
    				        if(sum > t1)
    					        for(--i2; i1 < i2 && nums[i2] == nums[i2 + 1]; --i2) {}
    				        else
    					        for(++i1; i1 < i2 && nums[i1] == nums[i1 - 1]; ++i1) {}
    			        }
    			    }

    			    for(--i3; i3 >= 2 && nums[i3] == nums[i3 + 1]; --i3) {}
    		    }
    	    }
    
    		for(--i4; i4 >= 3 && nums[i4] == nums[i4 + 1]; --i4) {}
    	}
    
    	return rv;
}
