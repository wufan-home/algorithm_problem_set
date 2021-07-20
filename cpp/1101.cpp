/*
    In a social group, there are n people, with unique integer ids from 0 to n-1.

    We have a list of logs, where each logs[i] = [timestamp, id_A, id_B] contains a non-negative integer timestamp, and the ids of two different people.

    Each log represents the time in which two different people became friends.  Friendship is symmetric: if A is friends with B, then B is friends with A.

    Let's say that person A is acquainted with person B if A is friends with B, or A is a friend of someone acquainted with B.

    Return the earliest time for which every person became acquainted with every other person. Return -1 if there is no such earliest time.



    Example 1:

    Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
    Output: 20190301
    Explanation: 
    The first event occurs at timestamp = 20190101 and after 0 and 1 become friends we have the following friendship groups [0,1], [2], [3], [4], [5].
    The second event occurs at timestamp = 20190104 and after 3 and 4 become friends we have the following friendship groups [0,1], [2], [3,4], [5].
    The third event occurs at timestamp = 20190107 and after 2 and 3 become friends we have the following friendship groups [0,1], [2,3,4], [5].
    The fourth event occurs at timestamp = 20190211 and after 1 and 5 become friends we have the following friendship groups [0,1,5], [2,3,4].
    The fifth event occurs at timestamp = 20190224 and as 2 and 4 are already friend anything happens.
    The sixth event occurs at timestamp = 20190301 and after 0 and 3 become friends we have that all become friends.


    Note:

    2 <= n <= 100
    1 <= logs.length <= 104
    0 <= logs[i][0] <= 109
    0 <= logs[i][1], logs[i][2] <= n - 1
    It's guaranteed that all timestamps in logs[i][0] are different.
    logs are not necessarily ordered by some criteria.
    logs[i][1] != logs[i][2]
    
    并差集更新组关系的时候，必须更新root的相对关系，不能是leave的相对关系。否则是换组。
    所以这里有是不是需要更新所有同组其它元素的相对关系。否则会有explosion。
    这里是不是要这么做看数据量。数据量不大，是不用的。
*/

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int size = logs.size();
        vector<int> uf(n, -1);
        for (int i = 0; i < n; ++i) {
            uf[i] = i;
        }
        auto compare = [](const vector<int>& l, const vector<int>& r) {
            return l[0] < r[0];
        };
        sort(logs.begin(), logs.end(), compare);
        int ans = -1;
        for (int i = 0; i < size; ++i) {
            int root1 = uf[logs[i][1]];
            for (; root1 != uf[root1]; root1 = uf[root1]) {}
            
            int root2 = uf[logs[i][2]];
            for (; root2 != uf[root2]; root2 = uf[root2]) {}
            
            if (root1 == root2) {
                continue;
            }
            else if (root1 < root2) {
                uf[root2] = root1;
            }
            else {
                uf[root1] = root2;
            }

            if (--n == 1) {
                ans = logs[i][0];
                break;
            }
        }
        
        return ans;
    }
};
