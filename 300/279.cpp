/*
    Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) 
    which sum to n.

    For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

// math
class Solution {
public:
    int numSquares(int n) {
        if(n < 0)
            return 0;
            
        if(n <= 1)
            return 1;
            
        int root = int(sqrt(n));
        if(root * root == n)
            return 1;
            
        while(n % 4 == 0)
            n /= 4;
            
        if(n % 8 == 7)
            return 4;
            
        for(int a = 0; a <= root; ++a)
        {
            int b = int(sqrt(n - a * a));
            if(a * a + b * b == n)
                return 2;
        }
        
        return 3;
    }
};

// dp
class Solution {
public:
    int numSquares(int n) {
        if(n < 2)
            return 1;
        
        vector<int> cache(n + 1, INT_MAX);
        cache[0] = 1;
        cache[1] = 1;
        squares(n, cache);
        return cache[n];
    }
    
private:
    void squares(int num, vector<int>& cache)
    {
        if(num < 2)
            return;
        
        int bound = (int)sqrt(num);
        if(bound * bound == num)
        {
            cache[num] = 1;
            return;
        }
        
        for(int i = 1; i <= bound; ++i)
        {
            int next = num - i * i;
            if(cache[next] == INT_MAX)
                squares(next, cache);
            
            cache[num] = min(cache[num], 1 + cache[next]);
        }
    }
};
