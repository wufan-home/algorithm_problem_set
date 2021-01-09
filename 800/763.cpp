/**/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        
        int length = S.size();
        
        // Two pointers
        vector<int> maxRightIndex(26, -1);
        for (int i = 0; i < length; ++i) {
            maxRightIndex[S[i] - 'a'] = max(maxRightIndex[S[i] - 'a'], i);
        }
        
        int leftEnd = -1;
        int rightEnd = -1;
        for(int i = 0; i < length; ++i) {
            rightEnd = max(rightEnd, maxRightIndex[S[i] - 'a']);
            if (i == rightEnd) {
                res.push_back(i - leftEnd);
                leftEnd = i;
            }
        }
        
        return res;
    }
};
