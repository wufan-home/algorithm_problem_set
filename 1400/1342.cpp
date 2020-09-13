class Solution {
public:
    int numberOfSteps (int num) {
        int rv = 0;
        
        for (; num > 1; num = num >> 1) {
            rv += (num & 1) + 1;
        }
        
        return rv + (num & 1);
    }
};
