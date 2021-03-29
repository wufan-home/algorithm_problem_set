/*
    Given the coordinates of four points in 2D space, return whether the four points could construct a square.

    The coordinate (x,y) of a point is represented by an integer array with two integers.

    Example:
    Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
    Output: True
    Note:

    All the input integers are in the range [-10000, 10000].
    A valid square has four equal sides with positive length and four equal angles (90-degree angles).
    Input points have no order.
*/

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> lengths({getLength(p1, p2), getLength(p2, p3), 
                                    getLength(p3, p4), getLength(p4, p1), 
                                    getLength(p1, p3), getLength(p2, p4)});
        
        if(lengths.size() != 2)
            return false;
        
        unordered_set<int>::iterator it = lengths.begin();
        int first = *(it++);
        int second = *it;
        return first == 2 * second || 2 * first == second;
    }
    
private:

    int getLength(const vector<int>& p1, const vector<int>& p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};
