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

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> dependency(numCourses, vector<int>());
        
        for(int i = 0; i < prerequisites.size(); ++i)
            dependency[prerequisites[i].first].push_back(prerequisites[i].second);
        
        stack<int> stackForCourses;
        vector<bool> finished(numCourses, false);
        vector<bool> cached(numCourses, false);
        for(int i= 0; i < numCourses; ++i)
        {
            if(!finished[i])
            {
                stackForCourses.push(i);
                while(!stackForCourses.empty())
                {
                    int curCourse = stackForCourses.top();
                    if(finished[curCourse] || dependency[curCourse].empty() || cached[curCourse])
                    {
                        finished[curCourse] = true;
                        cached[curCourse] = false;
                        stackForCourses.pop();
                    }
                    else
                    {
                        cached[curCourse] = true;
                        for(int j = 0; j < dependency[curCourse].size(); ++j)
                        {
                            if(finished[dependency[curCourse][j]])
                                continue;
                                
                            if(cached[dependency[curCourse][j]])
                                return false;
                                
                            stackForCourses.push(dependency[curCourse][j]);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
