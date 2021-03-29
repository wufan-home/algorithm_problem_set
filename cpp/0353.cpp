/*
    Design a Snake game that is played on a device with screen size = width x height. 
    Play the game online if you are not familiar with the game.

    The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

    You are given a list of food's positions in row-column order. 
    When a snake eats the food, its length and the game's score both increase by 1.

    Each food appears one by one on the screen. 
    For example, the second food will not appear until the first food was eaten by the snake.

    When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

    Example:
    Given width = 3, height = 2, and food = [[1,2],[0,1]].

    Snake snake = new Snake(width, height, food);

    Initially the snake appears at position (0,0) and the food at (1,2).

    |S| | |
    | | |F|

    snake.move("R"); -> Returns 0

    | |S| |
    | | |F|

    snake.move("D"); -> Returns 0

    | | | |
    | |S|F|

    snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

    | |F| |
    | |S|S|

    snake.move("U"); -> Returns 1

    | |F|S|
    | | |S|

    snake.move("L"); -> Returns 2 (Snake eats the second food)

    | |S|S|
    | | |S|

    snake.move("U"); -> Returns -1 (Game over because snake collides with border)
*/

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        mSnake.push_back(make_pair(0, 0));
        
        mFood = food;
        cur = 0;
        mHeight = height;
        mWidth = width;
        
        mMap["U"] = make_pair(-1, 0);
        mMap["L"] = make_pair(0, -1);
        mMap["R"] = make_pair(0, 1);
        mMap["D"] = make_pair(1, 0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int x = mSnake.front().first + mMap[direction].first;
        int y = mSnake.front().second + mMap[direction].second;
        
        if(x < 0 || x == mHeight || y < 0 || y == mWidth)
            return -1;
        
        if(cur == mFood.size() || x != mFood[cur].first || y != mFood[cur].second)
            mSnake.pop_back();
        else
            ++cur;
        
        for(list<pair<int, int>>::iterator it = mSnake.begin(); it != mSnake.end(); ++it)
        {
            if(it->first == x && it->second == y)
                return -1;
        }
        
        mSnake.push_front(make_pair(x, y));
        
        return cur;
    }
    
private:
    list<pair<int, int>> mSnake;
    vector<pair<int, int>> mFood;
    unordered_map<string, pair<int, int>> mMap;
    
    int cur;
    int mHeight;
    int mWidth;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
