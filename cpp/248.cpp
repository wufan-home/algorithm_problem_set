/*
    A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

    Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

    For example,
    Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

    Note:
    Because the range might be a large number, the low and high numbers are represented as string.
*/

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int count = 0;
        int size = high.size();
        
        if(compare("0", low) == true && compare(high, "0") == true)
            ++count;
        
        if(compare("1", low) == true && compare(high, "1") == true)
            ++count;
        
        if(compare("8", low) == true && compare(high, "8") == true)
            ++count;
        
        vector<pair<string, string>> digits = vector<pair<string, string>>({
            make_pair("0", "0"), 
            make_pair("1", "1"), 
            make_pair("6", "9"), 
            make_pair("9", "6"), 
            make_pair("8", "8")
        });
        
        cached[0] = vector<string>(1, "");
        cached[1] = vector<string>({"0", "1", "8"});
        
        for(int i = 2; i <= size; ++i)
        {
            cached[i] = vector<string>();
            for(auto a : cached[i - 2])
            {
                for(int j = 0; j < digits.size(); ++j)
                {
                    string cur = digits[j].first + a + digits[j].second;
                    if(cur[0] != '0' && compare(cur, low) == true && compare(high, cur) == true)
                    { 
                        //cout << "->" << cur << endl;
                        ++count;
                    }
                    cached[i].push_back(cur);
                }
            }
        }
        
        return count;
    }
    
private:
    unordered_map<int, vector<string>> cached;
    
    bool compare(const string& l, const string& r)
    {
        if(l.size() > r.size())
            return true;
        else if(l.size() < r.size())
            return false;
        else
        {
            for(int i = 0; i < l.size(); ++i)
            {
                if(l[i] > r[i])
                    return true;
                else if(l[i] < r[i])
                    return false;
            }
        }
        
        return true;
    }
};
