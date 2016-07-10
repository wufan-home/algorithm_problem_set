/*
  Given a list of non negative integers, arrange them such that they form the largest number.
  For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
  Note: The result may be very large, so you need to return a string instead of an integer.

  Solution: The most difficult point of this problem is to design the compare function.
  We say number 1 will be placed after the number 2 iff the string num_1 + num_2 is smaller than
  the string num_2 + num_1.
*/

bool Compare(const string& str1, const string& str2)
{
        string first = str1 + str2;
        string second = str2 + str1;
        for(int i = 0; i < first.size(); ++i)
        {
		if(first[i] != second[i])
		{
			if(first[i] >= second[i])
				return true;
			else
				break;
		}
        }
        
        return false;
}

string largestNumber(vector<int> &num)
{
        if(num.empty())
		return "";
            
        vector<string> strs(num.size(), "");
        for(int i = 0; i < num.size(); ++i)
		strs[i] = to_string(num[i]);
	
        sort(strs.begin(), strs.end(), Compare);
        string result("");
        for(int i = 0; i < strs.size(); ++i)
		result += strs[i];
            
        while(result[0] == '0' && result.size() > 1)
		result.erase(result.begin());
            
        return result;
}
