/*
    Write a program to find the n-th ugly number.
    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
    For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
    Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
*/

// Indices of three lists. This is a better way to solve the questions.
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (res.size() < n) {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int mn = min(m2, min(m3, m5));
            if (mn == m2) ++i2;
            if (mn == m3) ++i3;
            if (mn == m5) ++i5;
            res.push_back(mn);
        }
        return res.back();
    }
};

// Use the structure of a binary search tree.
// It can sort the elements autometically.
// Insert the 2, 3, 5 time the first element and remove this one.
// After n - 1 time, the first element is the result.
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> seq;
        seq.insert(1);
        int count = 1;
        while(count < n)
        {
            long long num = *(seq.begin());
            seq.insert(num * 2);
            seq.insert(num * 3);
            seq.insert(num * 5);
            seq.erase(seq.begin());
            ++count;
        }
        
        return *(seq.begin());
    }
};
