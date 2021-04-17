/*
    Given a rectangular cake with height h and width w, and two arrays of integers horizontalCuts and verticalCuts where horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

    Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a huge number, return this modulo 10^9 + 7.



    Example 1:

    Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
    Output: 4 
    Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.

    Example 2:

    Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
    Output: 6
    Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.

    Example 3:

    Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
    Output: 9



    Constraints:

        2 <= h, w <= 10^9
        1 <= horizontalCuts.length < min(h, 10^5)
        1 <= verticalCuts.length < min(w, 10^5)
        1 <= horizontalCuts[i] < h
        1 <= verticalCuts[i] < w
        It is guaranteed that all elements in horizontalCuts are distinct.
        It is guaranteed that all elements in verticalCuts are distinct.
*/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {  
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int max_h = max(horizontalCuts[0], h - horizontalCuts.back());
        int row = horizontalCuts.size();
        for (int i = 0; i < row - 1; ++i) {
            max_h = max(max_h, horizontalCuts[i + 1] - horizontalCuts[i]);
        } 

        int max_w = max(verticalCuts[0], w - verticalCuts.back());
        int col = verticalCuts.size();
        for (int i = 0; i < col - 1; ++i) {
            max_w = max(max_w, verticalCuts[i + 1] - verticalCuts[i]);
        } 
            
        int modulo = pow(10, 9) + 7;
        return ((long long) max_h * max_w) % modulo;
    }
};
