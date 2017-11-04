/*
    Given a string of numbers and operators, return all possible results from computing 
    all the different possible ways to group numbers and operators. The valid operators are +, - and *.

    Example 1
    Input: "2-1-1".

    ((2-1)-1) = 0
    (2-(1-1)) = 2
    Output: [0, 2]


    Example 2
    Input: "2*3-4*5"

    (2*(3-(4*5))) = -34
    ((2*3)-(4*5)) = -14
    ((2*(3-4))*5) = -10
    (2*((3-4)*5)) = -10
    (((2*3)-4)*5) = 10
    Output: [-34, -14, -10, -10, 10]
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if(input.empty())
            return vector<int>();
        
        vector<int> res;
        for(int i = 0; i < input.size(); ++i)
        {
            if(input[i] < '0' || input[i] > '9')
            {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                
                addResults(left, right, input[i], res);
            }
        }
        
        if(res.empty())
            res.push_back(atoi(input.c_str()));
        
        return res;
    }
    
private:
    void addResults(vector<int>& left, vector<int>& right, char op, vector<int>& res)
    {
        for(auto l : left)
        {
            for(auto r : right)
            {
                if(op == '+')
                    res.push_back(l + r);
                else if(op == '-')
                    res.push_back(l - r);
                else if(op == '*')
                    res.push_back(l * r);
            }
        }
    }
};
