/*
    You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

    We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.



    Example 1:

    Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    Output: 2

    Example 2:

    Input: times = [[1,2,1]], n = 2, k = 1
    Output: 1

    Example 3:

    Input: times = [[1,2,1]], n = 2, k = 2
    Output: -1



    Constraints:

        1 <= k <= n <= 100
        1 <= times.length <= 6000
        times[i].length == 3
        1 <= ui, vi <= n
        ui != vi
        0 <= wi <= 100
        All the pairs (ui, vi) are unique. (i.e., no multiple edges.)


*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int size = times.size();
        
        vector<set<pair<int, int>>> adj(N + 1, set<pair<int, int>>());
        
        for (int i = 0; i < size; ++i) {
            adj[times[i][0]].insert(make_pair(times[i][1], times[i][2]));
        }
        
        queue<pair<int, int>> q;
        vector<int> target_latency(N + 1, INT_MAX);
        target_latency[K] = 0;
        
        q.push(make_pair(K, 0));
        while (!q.empty()) {
            int cur = q.front().first;
            int latency = q.front().second;
            q.pop();
            
            for (auto next : adj[cur]) {
                int new_latency = next.second + latency;
                if (new_latency < target_latency[next.first]) {
                    target_latency[next.first] = new_latency;
                    q.push(make_pair(next.first, new_latency));
                }
            }
        }
        
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            res = max(res, target_latency[i]);
        }
        
        return res == INT_MAX ? -1 : res;
        
    }
};
