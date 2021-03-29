/*
    Find the total area covered by two rectilinear rectangles in a 2D plane.

    Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

    Rectangle Area
    Assume that the total area is never beyond the maximum possible value of int.
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int shared_area;
        if(G <= A || E >= C || B >= H || F >= D)
            shared_area = 0;
        else {
            vector<int> x_coordinates;
            x_coordinates.push_back(A);
            x_coordinates.push_back(C);
            x_coordinates.push_back(E);
            x_coordinates.push_back(G);
            sort(x_coordinates.begin(), x_coordinates.end());
        
            vector<int> y_coordinates;
            y_coordinates.push_back(B);
            y_coordinates.push_back(D);
            y_coordinates.push_back(F);
            y_coordinates.push_back(H);
            sort(y_coordinates.begin(), y_coordinates.end());
        
            shared_area = (x_coordinates[2] - x_coordinates[1]) * (y_coordinates[2] - y_coordinates[1]);
        }
        
        int area_1 = (C - A) * (D - B);
        int area_2 = (G - E) * (H - F);
        
        return area_1 + area_2 - shared_area;
    }
};
