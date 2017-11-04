/*
    Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
    write a function to check whether these edges make up a valid tree.

    For example:

    Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

    Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

    Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, 
    [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

// DFS


// Union-find approach.
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(edges.size() != n - 1)
            return false;
        
        vector<int> rels(n, 0);
        for(int i = 0; i < n; ++i)
            rels[i] = i;
        
        for(int i = 0; i < edges.size(); ++i)
        {
            int large = max(edges[i].first, edges[i].second);
            int small = min(edges[i].first, edges[i].second);
            
            while(large != rels[large])
                large = rels[large];
            
            if(small <= rels[large])
                rels[large] = small;
            else
                rels[small] = large;
        }
        
        int count = 0;
        for(int i = 0; i < rels.size(); ++i)
        {
            if(rels[i] == i)
            {
                if(count == 1)
                    return false;
                
                ++count;
            }
        }
        
        return true;
    }
};
