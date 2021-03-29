/*
    Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

    Example 1:
    Given points = [[1,1],[-1,1]], return true.

    Example 2:
    Given points = [[1,1],[-1,-1]], return false.

    Follow up:
    Could you do better than O(n2)?
*/

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        unordered_map<int, unordered_set<int>> m;
        int maxX = INT_MIN;
        int minX = INT_MAX;
        for(int i = 0; i < points.size(); ++i)
        {
            maxX = max(maxX, points[i].first);
            minX = min(minX, points[i].first);
            
            if(m.find(points[i].second) == m.end())
                m[points[i].second] = unordered_set<int>();
            
            m[points[i].second].insert(points[i].first);
        }
        
        double midX = double(maxX + minX) / 2.0;
        
        double error = pow(0.1, 9);
        for(int i = 0; i < points.size(); ++i)
        {
            int x = points[i].first;
            int y = points[i].second;
            
            double d = fabs(double(x) - midX);
            if(d < error)
                continue;
            
            if((x < midX && m[y].find(int(midX + d)) == m[y].end()) ||
               (x > midX && m[y].find(int(midX - d)) == m[y].end()))
                return false;
        }
        
        return true;
    }
};
