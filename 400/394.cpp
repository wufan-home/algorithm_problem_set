/*
    Given an encoded string, return it's decoded string.

    The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets 
    is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

    You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

    Furthermore, you may assume that the original data does not contain any digits and that digits 
    are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

    Examples:

    s = "3[a]2[bc]", return "aaabcbc".
    s = "3[a2[c]]", return "accaccacc".
    s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

*/

class Solution {
public:
    string decodeString(string s) {
        if(s.empty())
           return "";
           
        string res;
        stack<pair<int, string>> st;
        for(int i = 0; i < s.size();)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                int j = i;
                for(; j < s.size() && s[j] != '['; ++j) {}
                int repeat = atoi(s.substr(i, j - i).c_str());
                i = j + 1;
                st.push(make_pair(repeat, ""));
            }
            else if(s[i] == ']')
            {
                int repeat = st.top().first;
                string &str = st.top().second;
                string repeatStr;
                for(int j = 0; j < repeat; ++j)
                    repeatStr.append(str);
                
                st.pop();
                if(!st.empty())
                    st.top().second.append(repeatStr);
                else
                    res.append(repeatStr);
                ++i;
            }
            else
            {
                string repeatStr;
                for(; i < s.size(); ++i)
                {
                    if(s[i] == ']' || (s[i] >= '0' && s[i] <= '9'))
                        break;
                    
                    repeatStr.push_back(s[i]);
                }
                if(!st.empty())
                    st.top().second.append(repeatStr);
                else
                    res.append(repeatStr);
            }
        }
        
        return res;
    }
};
