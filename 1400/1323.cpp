class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        
        int index = -1;
        for (int i = 0; temp > 0; ++i, temp /= 10) {
            int residue = temp % 10;
            if (residue == 6) {
                index = i;
            }
        }
        
        return index >= 0 ? num + 3 * int(pow(10, index)) : num;
    }
};
