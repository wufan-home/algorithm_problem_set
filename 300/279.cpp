/*
    Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) 
    which sum to n.

    For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

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


#include <iostream>
#include <stack>
#include <cmath>

using namespace std;


void num_squares_aux(int n, stack<int>& components, int& min_num)
    {
      if(n == 0) {
            if(min_num == 0 || components.size() < min_num)
                min_num = components.size();
        } else {
            int max_root = int(sqrt(n));
            for(int i = max_root; i >= 1; --i) {
                components.push(max_root);
                num_squares_aux(n - i * i, components, min_num);
                components.pop();
            }
        }
    }
    
    int numSquares(int n) {
        int min_num = 0;
        stack<int> components;
        int max_root = int(sqrt(n));
        for(int i = max_root; i >= 1; --i) {
            components.push(max_root);
            num_squares_aux(n - i * i, components, min_num);
            components.pop();
        }
        return min_num;
    }

int main()
{
  cout << numSquares(46) << endl;
}
