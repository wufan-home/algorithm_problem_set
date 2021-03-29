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

// Quick Selection

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int size = points.size();
        
        vector<pair<int, int>> cache(size, make_pair(0, 0));
        for (int i = 0; i < size; ++i) {
            cache[i] = make_pair(i, points[i][0] * points[i][0] + points[i][1] * points[i][1]);
        }
        
        int start = 0;
        int end = size - 1;
        while (start < end) {
            int middle = end;
            int distance = cache[start].second;
            for (int i = start + 1; i <= middle;) {
                if (cache[i].second > distance) {
                    swap(cache[i], cache[middle--]);
                }
                else {
                    ++i;
                }
            }
            
            swap(cache[start], cache[middle]);
            
            if (middle == K) {
                break;
            }
            else if (middle > K) {
                end = middle - 1;
            }
            else {
                start = middle + 1;
            }
        }
        
        vector<vector<int>> res(K, vector<int>(2, -1));
        for (int i = 0; i < K; ++i) {
            res[i] = points[cache[i].first];
        }
        
        return res;
    }
};
