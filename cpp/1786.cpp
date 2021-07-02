/*
    There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.

    A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.

    The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.

    Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.



    Example 1:

    Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
    Output: 3
    Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The three restricted paths are:
    1) 1 --> 2 --> 5
    2) 1 --> 2 --> 3 --> 5
    3) 1 --> 3 --> 5

    Example 2:

    Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
    Output: 1
    Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The only restricted path is 1 --> 3 --> 7.



    Constraints:

        1 <= n <= 2 * 104
        n - 1 <= edges.length <= 4 * 104
        edges[i].length == 3
        1 <= ui, vi <= n
        ui != vi
        1 <= weighti <= 105
        There is at most one edge between any two nodes.
        There is at least one path between any two nodes.


*/

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<unordered_map<int, int>> adj(n + 1, unordered_map<int, int>());
        for (int i = 0; i < e; ++i) {
            adj[edges[i][0]][edges[i][1]] = edges[i][2];
            adj[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        
        vector<vector<int>> spl(n + 1, vector<int>({INT_MAX, 0, 0}));
        spl[n][0] = 0;
        spl[n][1] = 1;
        auto compare = [](const pair<int, int>& l, const pair<int, int>& r) {
            return l.second > r.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        int ans = 0;
        for (pq.push({n, spl[n][0]}); !pq.empty(); pq.pop()) {
            int node = pq.top().first;
            int w = pq.top().second;
            if (spl[node][2]) {
                continue;
            }
            spl[node][2] = 1;
            
            for (auto next : adj[node]) {
                if (spl[next.first][2] == 0) {
                    spl[next.first][0] = min(spl[next.first][0], w + next.second);
                    pq.push({next.first, spl[next.first][0]});
                }
                else if (spl[node][0] > spl[next.first][0]) {
                    spl[node][1] = (spl[node][1] + spl[next.first][1]) % (1000000007);
                }
            }
        }
        
        return spl[1][1];
    }
};
