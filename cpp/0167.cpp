/*
  Given an array of integers that is already sorted in ascending order, 
  find two numbers such that they add up to a specific target number.
  The function twoSum should return indices of the two numbers such that they add up to the target, 
  where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
  You may assume that each input would have exactly one solution.
  Input: numbers={2, 7, 11, 15}, target=9
  Output: index1=1, index2=2

  Solution: It seems that there is no better solution we may have.
*/

vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> index;
        if(numbers.empty())
            return index;
            
        for(int l = 0, r = numbers.size() - 1; l < r;)
        {
            long long num = numbers[l] + numbers[r];
            if(num == target)
            {
                index.push_back(l + 1);
                index.push_back(r + 1);
                break;
            }
            else if(num > target)
                for(--r; l < r && numbers[r] == numbers[r + 1]; --r) {}
            else
                for(++l; l < r && numbers[l - 1] == numbers[l]; ++l) {}
        }
        
        return index;
}
