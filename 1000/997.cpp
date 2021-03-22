/*
    In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

    If the town judge exists, then:

        The town judge trusts nobody.
        Everybody (except for the town judge) trusts the town judge.
        There is exactly one person that satisfies properties 1 and 2.

    You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

    If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.



    Example 1:

    Input: N = 2, trust = [[1,2]]
    Output: 2

    Example 2:

    Input: N = 3, trust = [[1,3],[2,3]]
    Output: 3

    Example 3:

    Input: N = 3, trust = [[1,3],[2,3],[3,1]]
    Output: -1

    Example 4:

    Input: N = 3, trust = [[1,2],[2,3]]
    Output: -1

    Example 5:

    Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
    Output: 3



    Constraints:

        1 <= N <= 1000
        0 <= trust.length <= 10^4
        trust[i].length == 2
        trust[i] are all different
        trust[i][0] != trust[i][1]
        1 <= trust[i][0], trust[i][1] <= N

*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if (N == 1) {
            return 1;
        }
        
        int size = trust.size();
        
        int res = -1;
        int max_trust = 0;
        
        vector<pair<bool, int>> count(N + 1, make_pair(false, 0));
        for (int i = 0; i < size; ++i) {
            count[trust[i][0]].first = true;
            ++count[trust[i][1]].second;
            if (count[trust[i][1]].second > max_trust) {
                max_trust = count[trust[i][1]].second;
                res = trust[i][1];
            }
        }
        
        return max_trust == N - 1  && count[res].first == false ? res : -1;
    }
};
