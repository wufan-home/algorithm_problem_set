/*
    On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

        "G": go straight 1 unit;
        "L": turn 90 degrees to the left;
        "R": turn 90 degrees to the right.

    The robot performs the instructions given in order, and repeats them forever.

    Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.



    Example 1:

    Input: instructions = "GGLLGG"
    Output: true
    Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
    When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.

    Example 2:

    Input: instructions = "GG"
    Output: false
    Explanation: The robot moves north indefinitely.

    Example 3:

    Input: instructions = "GL"
    Output: true
    Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...



    Constraints:

        1 <= instructions.length <= 100
        instructions[i] is 'G', 'L' or, 'R'.


*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> moves({{0, 1}, {-1, 0}, {0, -1}, {1, 0}});
        
        int x = 0;
        int y = 0;
        int face = 0; // 0 - north
        
        int len = instructions.size();
        for (int i = 0; i < len; ++i) {
            if (instructions[i] == 'G') {
                x += moves[face][0];
                y += moves[face][1];
            }
            else if (instructions[i] == 'L') {
                ++face;
                face %= 4;
            }
            else {
                if (--face < 0) {
                    face += 4;
                }
            }
        }
        
        return (x == 0 && y == 0) || (face != 0);
    }
};
