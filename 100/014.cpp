/*
  Write a function to find the longest common prefix string amongst an array of strings.
*/


 string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
            
        string prefix = strs[0];
        int prefix_end_index = strs[0].size() - 1;
        for(int i = 1; i < strs.size(); ++i)
        {
            for(int j = 0; j <= prefix_end_index; ++j)
            {
                if(strs[i][j] != strs[0][j])
                {
                    prefix_end_index = j - 1;
                    break;
                }
            }
        }
        
        return strs[0].substr(0, prefix_end_index + 1);
    }
