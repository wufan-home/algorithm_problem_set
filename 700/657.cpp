/*
    Initially, there is a Robot at position (0, 0). Given a sequence of its moves, 
    judge if this robot makes a circle, which means it moves back to the original place.

    The move sequence is represented by a string. And each move is represent by a character. 
    The valid robot moves are R (Right), L (Left), U (Up) and D (down). 
    The output should be true or false representing whether the robot makes a circle.

    Example 1:
    Input: "UD"
    Output: true
    Example 2:
    Input: "LL"
    Output: false
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for(int i = 0; i < moves.size(); ++i)
        {
            char step = moves[i];
            if(step == 'U')
                y += 1;
            else if(step == 'D')
                y -= 1;
            else if(step == 'L')
                x -= 1;
            else
                x += 1;
        }
        
        return x == 0 && y == 0;
    }
};
