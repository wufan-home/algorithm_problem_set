/*
    Imagine you have a special keyboard with the following keys:

    Key 1: (A): Print one 'A' on screen.

    Key 2: (Ctrl-A): Select the whole screen.

    Key 3: (Ctrl-C): Copy selection to buffer.

    Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

    Now, you can only press the keyboard for N times (with the above four keys), 
    find out the maximum numbers of 'A' you can print on screen.
*/

class Solution {
public:
    int maxA(int N) {
        vector<int> lengths(N + 1, 1);
        for(int i = 1; i <= N; ++i)
            lengths[i] = i;
        
        for(int i = 7; i <= N; ++i)
        {
            for(int j = 3; j <= 5; ++j)
                lengths[i] = max(lengths[i], lengths[i - j] * (j - 1));
        }
        
        return lengths[N];
    }
};
