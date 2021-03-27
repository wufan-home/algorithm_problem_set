/*
    Given a list of the scores of different students, items, where items[i] = [IDi, scorei] represents one score from a student with IDi, calculate each student's top five average.

    Return the answer as an array of pairs result, where result[j] = [IDj, topFiveAveragej] represents the student with IDj and their top five average. Sort result by IDj in increasing order.

    A student's top five average is calculated by taking the sum of their top five scores and dividing it by 5 using integer division.



    Example 1:

    Input: items = [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
    Output: [[1,87],[2,88]]
    Explanation: 
    The student with ID = 1 got scores 91, 92, 60, 65, 87, and 100. Their top five average is (100 + 92 + 91 + 87 + 65) / 5 = 87.
    The student with ID = 2 got scores 93, 97, 77, 100, and 76. Their top five average is (100 + 97 + 93 + 77 + 76) / 5 = 88.6, but with integer division their average converts to 88.

    Example 2:

    Input: items = [[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100]]
    Output: [[1,100],[7,100]]



    Constraints:

        1 <= items.length <= 1000
        items[i].length == 2
        1 <= IDi <= 1000
        0 <= scorei <= 100
        For each IDi, there will be at least five scores.
*/

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int, vector<int>, compare>> studentScores;
        priority_queue<int, vector<int>, compare> existedStudents;
        int size = items.size();
        for (int i = 0; i < size; ++i) {
            if (studentScores.count(items[i][0]) == 0) {
                studentScores[items[i][0]] = priority_queue<int, vector<int>, compare>();
                existedStudents.push(items[i][0]);
            }
            
            studentScores[items[i][0]].push(items[i][1]);
            
            if (studentScores[items[i][0]].size() > 5) {
                studentScores[items[i][0]].pop();
            }
        }
        
        vector<vector<int>> res;
        for (; !existedStudents.empty(); existedStudents.pop()) {
            int student = existedStudents.top();
            int sum = 0;
            for (; !studentScores[student].empty(); studentScores[student].pop()) {
                sum += studentScores[student].top();
            }
            
            res.push_back(vector<int>({student, sum / 5}));
        }
        
        return res;
    }
    
private:
    struct compare {
        bool operator() (const int l, const int r) {
            return l >= r;
        }
    };
};
