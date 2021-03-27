class Solution {
public:
    int fib(int N) {
        if (N == 0)
            return 0;
        
        if (N <= 2)
            return 1;
        
        int add_1 = 1;
        int add_2 = 1;
        int sum = 0;
        for (int i = 3; i <= N; ++i) {
            sum = add_1 + add_2;
            add_1 = add_2;
            add_2 = sum;
        }
        
        return sum;
    }
};
