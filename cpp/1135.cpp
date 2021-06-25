/*
    There are n cities numbered from 1 to n.

    You are given connections, where each connections[i] = [city1, city2, cost] represents the cost to connect city1 and city2 together.  (A connection is bidirectional: connecting city1 and city2 is the same as connecting city2 and city1.)

    Return the minimum cost so that for every pair of cities, there exists a path of connections (possibly of length 1) that connects those two cities together.  The cost is the sum of the connection costs used. If the task is impossible, return -1.



    Example 1:

    Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
    Output: 6
    Explanation: 
    Choosing any 2 edges will connect all cities so we choose the minimum 2.

    Example 2:

    Input: n = 4, connections = [[1,2,3],[3,4,4]]
    Output: -1
    Explanation: 
    There is no way to connect all cities even if all edges are used.



    Note:

        1 <= n <= 10000
        1 <= connections.length <= 10000
        1 <= connections[i][0], connections[i][1] <= n
        0 <= connections[i][2] <= 105
        connections[i][0] != connections[i][1]


*/

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        auto compare = [](const vector<int>& l, const vector<int>& r) {
            return l[2] < r[2];
        };
        
        sort(connections.begin(), connections.end(), compare);
        
        vector<int> components(N + 1, 0);
        for (int i = 0; i <= N; ++i) {
            components[i] = i;
        }
        
        int ans = 0;
        int e = connections.size();
        for (int i = 0; i < e; ++i) {
            int p1 = connections[i][0];
            while (p1 != components[p1]) {
                p1 = components[p1];
            }
            
            int p2 = connections[i][1];
            while (p2 != components[p2]) {
                p2 = components[p2];
            }
            
            if (p1 != p2) {
                if (p1 < p2) {
                    components[p2] = p1;
                } 
                else {
                    components[p1] = p2;
                }
                ans += connections[i][2];
                --N;
            }
        }
        
        return N == 1 ? ans : -1;
    }
};
