string countAndSay(int n) {
	string rv = "1";
        for(int i = 2; i <= n; ++i)
	{
		string cand = "";
		for(int sample = 0; sample < rv.size();)
		{
			int test = sample;
			for(; sample < rv.size() && rv[test] == rv[sample]; ++test) {}

			cand.push_back(test - sample + '0');
			cand.push_back(rv[sample]);
			sample = test;
		}
		rv = cand;
	}

	return rv;
}

string DoCount(string& str)
    {
        string result("");
        str.push_back('#');
        char ch = str[0];
        int count = 1;
        for(int i = 1; i < str.size(); ++i)
        {
            if(str[i] != str[i - 1])
            {
                result.push_back(count + '0');
                result.push_back(ch);
                count = 1;
                ch = str[i];
            }
            else
                ++count;
        }
        return result;
    }
    
    string countAndSay(int n) 
    {
        string result("1");
        for(int i = 1; i < n; ++i)
            result = DoCount(result);
        return result;
    }
