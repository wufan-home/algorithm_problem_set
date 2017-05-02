/*
   Implement strStr().
   Returns the index of the first occurrence of needle in haystack, 
   or -1 if needle is not part of haystack. 
   Solution: 1) Brute-force.
   2) KMP or other methods.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;

        int bound = (int) haystack.size() - (int) needle.size() + 1;
        for(int i = 0; i < bound; ++i)
        {
            int j = 0;
            for(; j < needle.size(); ++j)
            {
                if(haystack[i + j] != needle[j])
                    break;
            }
            if(j == needle.size())
                return i;
        }
        
        return -1;
    }
}

//======================= KMP =========================

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
            
        if(haystack.size() == needle.size())
            return haystack == needle ? 0 : -1;

        // Compute partial match table.
        vector<int> partialMatchTable(needle.size(), 0);
        for(int substringLength = 1; substringLength < needle.size(); ++substringLength)
        {
            //cout << "substr = " << needle.substr(0, substringLength) << endl;
            for(int l = substringLength - 1; l > 0 ; --l)
            {
                bool match = true;
                for(int i = 0, j = substringLength - l; i < l; ++i, ++j)
                {
                    if(needle[i] != needle[j])
                        match = false;
                }
                /*cout << "left = " << needle.substr(0, l) << " - " 
                    << "right = " << needle.substr(substringLength - l, l) 
                    << " - " << match << endl;*/
                if(match)
                {
                    partialMatchTable[substringLength - 1] = l;
                    break;
                }
            }
        }
        
        /*for(int i = 0; i < partialMatchTable.size(); ++i)
        {
            cout << needle.substr(0, i + 1) << ", ";
            cout << partialMatchTable[i] << endl;
        }
        cout << endl;*/

        int bound = (int) haystack.size() - (int) needle.size() + 1;
        for(int i = 0; i < bound;)
        {
            int j = 0;
            for(; j < needle.size(); ++j)
            {
                if(haystack[i + j] != needle[j])
                    break;
            }
            
            if(j == needle.size())
                return i;
            else
                i += j == 0 ? 1 : (j - partialMatchTable[j - 1]);
        }
        
        return -1;
    }
};
