/*
	Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
	
	Use the coprime pair as a key in a tree map is the key point to this problem.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); ++i)
        {
            int duplicate = 1;
            map<pair<int, int>, int> m;
            for(int j = i + 1; j < points.size(); ++j)
            {
                if(points[j].x == points[i].x && points[j].y == points[i].y)
                {
                    ++duplicate;
                    continue;
                }
                
                int upper = points[j].x - points[i].x;
                int lower = points[j].y - points[i].y;
                if(upper == 0)
                    ++m[make_pair(0, 1)];
                else if(lower == 0)
                    ++m[make_pair(1, 0)];
                else
                {
                    if(lower < 0)
                    {
                        upper *= -1;
                        lower *= -1;
                    }
                    
                    int g = gcd(abs(upper), abs(lower));
                    ++m[make_pair(upper / g, lower / g)];
                }
            }
            
            res = max(res, duplicate);
            for(auto a : m)
                res = max(res, a.second + duplicate);
        }
        
        return res;
    }
    
private:
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
};
