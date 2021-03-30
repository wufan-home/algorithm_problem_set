/*
    We start at some node in a directed graph, and every turn, we walk along a directed edge of the graph. If we reach a terminal node (that is, it has no outgoing directed edges), we stop.

    We define a starting node to be safe if we must eventually walk to a terminal node. More specifically, there is a natural number k, so that we must have stopped at a terminal node in less than k steps for any choice of where to walk.

    Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

    The directed graph has n nodes with labels from 0 to n - 1, where n is the length of graph. The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph, going from node i to node j.



    Example 1:
    Illustration of graph

    Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    Output: [2,4,5,6]
    Explanation: The given graph is shown above.

    Example 2:

    Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    Output: [4]



    Constraints:

        n == graph.length
        1 <= n <= 104
        0 <= graph[i].legnth <= n
        graph[i] is sorted in a strictly increasing order.
        The graph may contain self-loops.
        The number of edges in the graph will be in the range [1, 4 * 104].


*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        
        // Pre-scan.
        vector<bool> safeNodes(size, false);
        for (int i = 0; i < size; ++i) {
            if (graph[i].empty()) {
                safeNodes[i] = true;
            }
        }
        
        unordered_set<int> unsafeNodes;
        list<int> path;
        for (int node = 0; node < size; ++node) {
            if (safeNodes[node] || unsafeNodes.count(node) != 0) {
                // Do not need to check the unsafe nodes.
                continue;
            }
            vector<bool> visited(size, false);
            dfs(graph, node, path, safeNodes, unsafeNodes, visited);
        }
        
        vector<int> res;
        for (int i = 0; i < size; ++i) {
            if (safeNodes[i]) {
                res.push_back(i);
            }
        }
        
        return res;
    }
    
private:
    void dfs(vector<vector<int>>& graph, int node, list<int>& path, vector<bool>& safeNodes, unordered_set<int>& unsafeNodes, vector<bool>& visited) {
        int neighbourSize = graph[node].size();
        for (int i = 0; i < neighbourSize; ++i) {
            // Do not check more, if the node is adjacent a not safe node, i.e., one of neighbours is not safe.
            // A unsafe node's neighbours may be safe. The checking process needs to continue.
            if (visited[graph[node][i]] || unsafeNodes.count(graph[node][i]) != 0) {
                unsafeNodes.insert(node);
                for (int& notSafeNode : path) {
                    unsafeNodes.insert(notSafeNode);
                }
                return;
            }
        }
        
        path.push_back(node);
        visited[node] = true;
        
        for (int i = 0; i < neighbourSize; ++i) {
            if (safeNodes[graph[node][i]]) {
                continue;
            }
            
            dfs(graph, graph[node][i], path, safeNodes, unsafeNodes, visited);
            
            if (unsafeNodes.count(node) != 0) {
                break;
            }
        }
        
        if (unsafeNodes.count(node) == 0) {
            safeNodes[node] = true;
        }
        
        path.pop_back();
        visited[node] = false;
    }
};
