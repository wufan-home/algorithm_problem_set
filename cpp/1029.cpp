/*
    A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

    Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.



    Example 1:

    Input: costs = [[10,20],[30,200],[400,50],[30,20]]
    Output: 110
    Explanation: 
    The first person goes to city A for a cost of 10.
    The second person goes to city A for a cost of 30.
    The third person goes to city B for a cost of 50.
    The fourth person goes to city B for a cost of 20.

    The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.

    Example 2:

    Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
    Output: 1859

    Example 3:

    Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
    Output: 3086



    Constraints:

        2 * n == costs.length
        2 <= costs.length <= 100
        costs.length is even.
        1 <= aCosti, bCosti <= 1000


*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int num = costs.size();
        auto compare_a = [](const vector<int>& l, const vector<int>& r) { return l[1] - l[0] > r[1] - r[0]; };
        auto compare_b = [](const vector<int>& l, const vector<int>& r) { return l[0] - l[1] > r[0] - r[1]; };
        
        int sum_cost = 0;
        
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(compare_a)> pq_citya(compare_a);
        for (int i = 0; i < num / 2; ++i) {
            sum_cost += costs[i][0];
            pq_citya.push(costs[i]);
        }
        
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(compare_b)> pq_cityb(compare_b);
        for (int i = num / 2; i < num; ++i) {
            sum_cost += costs[i][1];
            pq_cityb.push(costs[i]);
        }
        
        while (true) {
            int temp_cost = sum_cost - pq_citya.top()[0] + pq_citya.top()[1] - pq_cityb.top()[1] + pq_cityb.top()[0];
            
            if (temp_cost >= sum_cost) {
                break;
            }
            
            vector<int> remove_a = pq_citya.top();
            pq_citya.pop();
            pq_citya.push(pq_cityb.top());
            pq_cityb.pop();
            pq_cityb.push(remove_a);
            
            sum_cost = temp_cost;
        }
        
        return sum_cost;
    }
};

// This is a better solution.

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int num = costs.size();
        auto compare_a = [](const vector<int>& l, const vector<int>& r) { return l[0] - l[1] < r[0] - r[1]; };
        
        sort(costs.begin(), costs.end(), compare_a);
        
        int sum = 0;
        for (int i = 0; i < num; ++i) {
            sum += costs[i][i < num / 2 ? 0 : 1];
        }
        
        return sum;
    }
};
