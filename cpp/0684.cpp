/*
    In this problem, a tree is an undirected graph that is connected and has no cycles.

    You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

    Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.



    Example 1:

    Input: edges = [[1,2],[1,3],[2,3]]
    Output: [2,3]

    Example 2:

    Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
    Output: [1,4]



    Constraints:

        n == edges.length
        3 <= n <= 1000
        edges[i].length == 2
        1 <= ai < bi <= edges.length
        ai != bi
        There are no repeated edges.
        The given graph is connected.


*/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size = edges.size();
        vector<int> groups(size + 1);
        for (int i = 0; i < size + 1; ++i) {
            groups[i] = i;
        }
        
        for (int i = 0; i < edges.size(); ++i) {
            int target0 = groups[edges[i][0]];
            while (groups[target0] != target0) {
                target0 = groups[target0];
            }
            
            int target1 = groups[edges[i][1]];
            while (groups[target1] != target1) {
                target1 = groups[target1];
            }
            
            if (groups[target0] == groups[target1]) {
                return edges[i];
            }
            
            if (target0 <= target1) {
                groups[target1] = target0;
            }
            else {
                groups[target0] = target1;
            }
        }
        
        return vector<int>();
    }
};
