/*
  You are climbing a stair case. 
  It takes n steps to reach to the top.
  Each time you can either climb 1 or 2 steps. 
  In how many distinct ways can you climb to the top? 

  Solution:
  Fibbonaci sequence and the below solution is a dynamic programming method.
*/

#include <vector>

using namespace std;

int climbStairs(int n) {
        if(n <= 1)
		return 1;
            
        vector<int> methods(n + 1, 1);
        for(int i = 2; i < n + 1; ++i)
            methods[i] = methods[i - 1] + methods[i - 2];
            
        return methods[n];
}
