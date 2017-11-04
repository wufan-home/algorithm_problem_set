/*
 * Given an array of citations (each citation is a non-negative integer) of a researcher, 
 * write a function to compute the researcher's h-index.

 * According to the definition of h-index on Wikipedia: 
 * "A scientist has index h if h of his/her N papers have at least h citations each, 
 * and the other N − h papers have no more than h citations each."

 * For example, given citations = [3, 0, 6, 1, 5], 
 * which means the researcher has 5 papers in total 
 * and each of them had received 3, 0, 6, 1, 5 citations respectively. 
 * Since the researcher has 3 papers with at least 3 citations each 
 * and the remaining two with no more than 3 citations each, his h-index is 3.

 * Note: If there are several possible values for h, the maximum one is taken as the h-index. 
 */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
            return 0;
        
        int maxIndex = 0;
        for(int i = 0; i < citations.size(); ++i)
            maxIndex = max(maxIndex, citations[i]);
        
        vector<int> count(maxIndex + 1, 0);
        for(int i = 0; i < citations.size(); ++i)
            ++count[citations[i]];
        
        for(int i = maxIndex; i > 0; --i)
        {
            if(count[i] >= i)
                return min(count[i], i);
            
            count[i - 1] += count[i];
        }
        
        return 0;
    }
};
