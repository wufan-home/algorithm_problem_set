/*
    Given a string containing only digits, restore it by returning all possible valid IP address combinations.

    For example:
    Given "25525511135",

    return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12)
            return ips;

        getIps(s, 0, 1);
        return ips;
    }
    
private:
    void getIps(const string& s, int start, int section)
    {
        if(s.empty())
            return;

        for(int l = 1; l <= min(3, int(s.size() - start)); ++l)
        {
            if((l > 1 && s[start] == '0') || atoi(s.substr(start, l).c_str()) > 255)
                break;
            
            for(int j = 0; j < l; ++j)
                ip.push_back(s[start + j]);
                
            if(section < 4)
            {
                ip.push_back('.');
                getIps(s, start + l, section + 1);
                ip.pop_back();
            }
            else if(s.size() - start == l)
            {
                ips.push_back(ip);
            }
            
            for(; !ip.empty() && ip[ip.size() - 1] != '.'; ip.pop_back()) {}
        }    
    }
    
    string ip;
    vector<string> ips;
};
