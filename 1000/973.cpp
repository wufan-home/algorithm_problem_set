/*

*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int size = points.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        
        for (int i = 0; i < size; ++i) {
            if (pq.size() < K) {
                pq.push(make_pair(i, points[i][0] * points[i][0] + points[i][1] * points[i][1]));
            }
            else {
                int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
                if (distance < pq.top().second) {
                    pq.pop();
                    pq.push(make_pair(i, distance));
                }
            }
        }
        
        vector<vector<int>> res(K, vector<int>(2, 0));
        for (int i = 0; !pq.empty(); ++i, pq.pop()) {
            int index = pq.top().first;
            res[i] = points[index];
        }
        
        return res;
    }
    
private:
    struct compare {
        bool operator() (const pair<int, int> &l, const pair<int, int> &r) {
            return l.second <= r.second;
        }
    };
};
