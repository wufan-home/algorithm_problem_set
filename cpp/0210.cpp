/*
    There are a total of n courses you have to take, labeled from 0 to n - 1.

    Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

    Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

    There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

    For example:

    2, [[1,0]]
    There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

    4, [[1,0],[2,0],[3,1],[3,2]]
    There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

    Note:
    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.
    click to show more hints.

    Hints:
    This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
    Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
    Topological sort could also be done via BFS.
*/

// Topological sort, DFS.
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> adj(numCourses, unordered_set<int>());
        vector<int> pre(numCourses, 0);
        for (auto edge : prerequisites) {
            adj[edge[1]].insert(edge[0]);
            ++pre[edge[0]];
        }
        
        vector<int> schedule;
        stack<int> st;
        vector<bool> visited(numCourses, false);
        for (int c = 0; c < numCourses; ++c) {
            if (pre[c] == 0) {
                schedule.push_back(c);
                st.push(c);
                visited[c] = true;
            }
        }
        
        while (!st.empty()) {
            int c = st.top();
            st.pop();
            for (auto n : adj[c]) {
                if (visited[n]) {
                    return vector<int>();
                }
                
                if (--pre[n] == 0) {
                    schedule.push_back(n);
                    st.push(n);
                    visited[c] = true;
                }
            }
        }
        
        return schedule.size() == numCourses ? schedule : vector<int>();
    }
};
