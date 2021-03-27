/*
    Given an integer n, return 1 - n in lexicographical order.

    For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

    Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int cur = 1; res.size() < n;)
        {
            res.push_back(cur);
            
            if(cur <= n / 10)
                cur *= 10;
            else 
            {
                if(cur >= n)
                    cur /= 10;
                ++cur;
                for(; cur % 10 == 0; cur /= 10) {}
            }
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> sortedList;
        for(int i = 1; i < 10; ++i)
        {
            if(i > n)
                break;
            
            sortedList.push_back(i);
            createSortedList(i * 10, n, sortedList);
        }
        return sortedList;
    }
    
private:
    void createSortedList(int cur, int n, vector<int>& list)
    {
        if(cur > n)
            return;
        
        for(int i = 0; i < 10; ++i)
        {
            //cout << cur << endl;
            if(cur > n)
                break;
            
            list.push_back(cur);
            createSortedList(cur * 10, n, list);
            ++cur;
        }
    }
};
