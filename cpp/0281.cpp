/*
    Given two 1d vectors, implement an iterator to return their elements alternately.

    For example, given two 1d vectors:

    v1 = [1, 2]
    v2 = [3, 4, 5, 6]
    By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

    Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

    Clarification for the follow up question - Update (2015-09-18):
    The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

    [1,2,3]
    [4,5,6,7]
    [8,9]
    It should return [1,4,8,2,5,9,3,6,7].
*/

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        vectors.push_back(v1);
        vectors.push_back(v2);
        indices = vector<int>(2, 0);
        
        cur = 0;
        size = 2;
    }

    int next() {
        while(indices[cur] == vectors[cur].size())
            cur = (cur + 1) % size;
        
        int value = vectors[cur][indices[cur]++];
        cur = (cur + 1) % size;
        return value;
    }

    bool hasNext() {
        for(int i = 0; i < vectors.size(); ++i)
        {
            if(indices[i] < vectors[i].size())
                return true;
        }
        
        return false;
    }
    
private:
    vector<vector<int>> vectors;
    vector<int> indices;
    
    int cur;
    int size;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
