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
