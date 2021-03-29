/*
    Implement an iterator to flatten a 2d vector.

    For example,
    Given 2d vector =

    [
      [1,2],
      [3],
      [4,5,6]
    ]
    By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

    Follow up:
    As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        matrix = vec2d;
        colSizes = vector<int>(vec2d.size(), 0);
        
        index = 0;
        row = 0;
        for(int i = 0; i < vec2d.size(); ++i)
            colSizes[i] = (i == 0 ? 0 : colSizes[i - 1]) + vec2d[i].size();
            
        for(; row < colSizes.size() && matrix[row].empty(); ++row) {}
    }

    int next() {
        int col = index - (row == 0 ? 0 : colSizes[row - 1]);
        int value = matrix[row][col];
        if(++index == colSizes[row])
            for(++row; row < colSizes.size() && matrix[row].empty(); ++row) {}
        
        return value;
    }

    bool hasNext() {
        return !colSizes.empty() && index < colSizes[matrix.size() - 1];
    }
    
private:
    vector<vector<int>> matrix;
    vector<int> colSizes;
    int row;
    int index;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
