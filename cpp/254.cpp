/*
    Numbers can be regarded as product of its factors. For example,

    8 = 2 x 2 x 2;
      = 2 x 4.
    Write a function that takes an integer n and return all possible combinations of its factors.

    Note: 
    You may assume that n is always positive.
    Factors should be greater than 1 and less than n.
    Examples: 
    input: 1
    output: 
    []
    input: 37
    output: 
    []
    input: 12
    output:
    [
      [2, 6],
      [2, 2, 3],
      [3, 4]
    ]
    input: 32
    output:
    [
      [2, 16],
      [2, 2, 8],
      [2, 2, 2, 4],
      [2, 2, 2, 2, 2],
      [2, 4, 4],
      [4, 8]
    ]
*/

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> factorSets;
        int bound = sqrt(n);
        for(int i = 2; i <= bound; ++i)
        {
            if(n % i == 0)
            {
                vector<vector<int>> smallerFactorSet = getFactorsAux(n / i);
                for(int j = 0; j < smallerFactorSet.size(); ++j)
                {
                    if(i > smallerFactorSet[j][0])
                        continue;

                    vector<int> factor(1 + smallerFactorSet[j].size(), i);
                    for(int k = 1; k <= smallerFactorSet[j].size(); ++k)
                        factor[k] = smallerFactorSet[j][k - 1];
                        
                    factorSets.push_back(factor);
                }
            }
        }
    
        return factorSets;
    }
    
private:
    vector<vector<int>> getFactorsAux(int n)
    {
        vector<vector<int>> factorSets;
        for(int i = 2; i < n; ++i)
        {
            if(n % i == 0)
            {
                vector<vector<int>> smallerFactorSet = getFactorsAux(n / i);
                for(int j = 0; j < smallerFactorSet.size(); ++j)
                {
                    if(i > smallerFactorSet[j][0])
                        continue;

                    vector<int> factor(1 + smallerFactorSet[j].size(), i);
                    for(int k = 1; k <= smallerFactorSet[j].size(); ++k)
                        factor[k] = smallerFactorSet[j][k - 1];
                        
                    factorSets.push_back(factor);
                }
            }
        }
        
        factorSets.push_back(vector<int>(1, n));
        
        return factorSets;
    }
};
