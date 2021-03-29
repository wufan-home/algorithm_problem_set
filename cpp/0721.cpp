/*
    Given a list accounts, each element accounts[i] is a list of strings, 
    where the first element accounts[i][0] is a name, and the rest of the elements 
    are emails representing emails of the account.

    Now, we would like to merge these accounts. 
    Two accounts definitely belong to the same person if there is some email 
    that is common to both accounts. Note that even if two accounts have the same name, 
    they may belong to different people as people could have the same name. 
    A person can have any number of accounts initially, but all of their accounts definitely have the same name.

    After merging the accounts, return the accounts in the following format: 
    the first element of each account is the name, and the rest of the elements are emails in sorted order. 
    The accounts themselves can be returned in any order.

    Example 1:
    Input: 
    accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], 
    ["John", "johnnybravo@mail.com"], 
    ["John", "johnsmith@mail.com", "john_newyork@mail.com"], 
    ["Mary", "mary@mail.com"]]
    Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  
    ["John", "johnnybravo@mail.com"], 
    ["Mary", "mary@mail.com"]]
    Explanation: 
    The first and third John's are the same person as they have the common email "johnsmith@mail.com".
    The second John and Mary are different people as none of their email addresses are used by other accounts.
    We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], 
    ['John', 'johnnybravo@mail.com'], 
    ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
    Note:

    The length of accounts will be in the range [1, 1000].
    The length of accounts[i] will be in the range [1, 10].
    The length of accounts[i][j] will be in the range [1, 30].
*/

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int size = accounts.size();
        unordered_map<string, vector<int>> m;
        for(int i = 0; i < size; ++i)
        {
            for(int j = 1; j < accounts[i].size(); ++j)
            {
                if(m.find(accounts[i][j]) == m.end())
                    m[accounts[i][j]] = vector<int>();
                
                m[accounts[i][j]].push_back(i);
            }
        }
        
        unordered_set<int> visited;
        unordered_set<string> visited_email;
        vector<vector<string>> res;
        for(int i = 0; i < size; ++i)
        {
            if(visited.find(i) != visited.end())
                continue;
            
            res.push_back(vector<string>(1, accounts[i][0]));
            visited.insert(i);
            dfs(accounts, i, m, visited, visited_email, res);
            sort(res.back().begin() + 1, res.back().end());
        }
        
        return res;
    }
    
private:
    void dfs(const vector<vector<string>> &accounts, int start, 
             unordered_map<string, vector<int>> &m, 
             unordered_set<int> &visited, 
             unordered_set<string> &visited_email,
             vector<vector<string>> &res)
    {
        for(int i = 1; i < accounts[start].size(); ++i)
        {
            if(visited_email.find(accounts[start][i]) != visited_email.end())
                continue;
            
            res.back().push_back(accounts[start][i]);
            visited_email.insert(accounts[start][i]);
            vector<int> &next = m[accounts[start][i]];
            for(int j = 0; j < next.size(); ++j)
            {
                if(visited.find(next[j]) != visited.end())
                    continue;
                
                visited.insert(next[j]);
                dfs(accounts, next[j], m, visited, visited_email, res);
            }
        }
    }
};
