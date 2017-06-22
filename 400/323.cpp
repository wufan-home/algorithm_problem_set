/*
    Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
    write a function to find the number of connected components in an undirected graph.

    Example 1:
         0          3
         |          |
         1 --- 2    4
    Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

    Example 2:
         0           4
         |           |
         1 --- 2 --- 3
    Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

    Note:
    You can assume that no duplicate edges will appear in edges. Since all edges are undirected, 
    [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> connection(n, 0);
        for(int i = 0; i < n; ++i)
            connection[i] = i;
        
        for(int i = 0; i < edges.size(); ++i)
        {
            //Search roots;
            int root1 = edges[i].first;
            for(; root1 != connection[root1]; root1 = connection[root1]) {}
            
            int root2 = edges[i].second;
            for(; root2 != connection[root2]; root2 = connection[root2]) {}
            
            if(root1 < root2)
                connection[root2] = root1;
            else if(root1 > root2)
                connection[root1] = root2;
        }
        
        int componentNumber = 0;
        for(int i = 0; i < n; ++i)
            componentNumber += (connection[i] == i ? 1 : 0);
            
        return componentNumber;
    }
};
