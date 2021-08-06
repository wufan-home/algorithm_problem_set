/*
	There are a total of n courses you have to take, labeled from 0 to n - 1.

	Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

	Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

	For example:

	2, [[1,0]]
	There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

	2, [[1,0],[0,1]]
	There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

	Note:
	The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
	You may assume that there are no duplicate edges in the input prerequisites.
	click to show more hints.

	Hints:
	This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
	Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
	Topological sort could also be done via BFS.
*/

// Topological sort, DFS.
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
                    return false;
                }
                
                if (--pre[n] == 0) {
                    schedule.push_back(n);
                    st.push(n);
                    visited[c] = true;
                }
            }
        }
        
        return schedule.size() == numCourses ? true : false;
    }
};
