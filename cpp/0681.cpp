/*
    Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

    You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.



    Example 1:

    Input: time = "19:34"
    Output: "19:39"
    Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.
    It is not 19:33, because this occurs 23 hours and 59 minutes later.

    Example 2:

    Input: time = "23:59"
    Output: "22:22"
    Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22.
    It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.



    Constraints:

        time.length == 5
        time is a valid time in the form "HH:MM".
        0 <= HH < 24
        0 <= MM < 60

    Test cases:
        "19:34"
        "10:59"
        "23:59"
        "00:00"
        "11:11"  // Important: Found the bug that the resd should be initialied by the input time.
        "22:59"
        "22:52"
*/

class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> digit;
        for (int i = 0; i < 5; ++i) {
            if (time[i] != ':') {
                digit.push_back(time[i] - '0');
            }
        }
        
        int min_diff = 1440;
        int absolute_time_input = (digit[0] * 10 + digit[1]) * 60 + (digit[2] * 10 + digit[3]);
        vector<int> resd(digit);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    for (int l = 0; l < 4; ++l) {
                        if (digit[i] > 2 || (digit[i] == 2 && digit[j] > 4) || digit[k] > 5) {
                            continue;
                        }
                        
                        int absolute_time = (digit[i] * 10 + digit[j]) * 60 + (digit[k] * 10 + digit[l]);
                        int diff = absolute_time - absolute_time_input;
                        if (diff) {
                            diff += (diff < 0 ? 1440 : 0);
                            if (diff < min_diff) {
                                min_diff = diff;
                                resd[0] = digit[i];
                                resd[1] = digit[j];
                                resd[2] = digit[k];
                                resd[3] = digit[l];
                            }
                        }
                    }
                }
            }
        }
        
        string res;
        res.push_back(resd[0] + '0');
        res.push_back(resd[1] + '0');
        res.push_back(':');
        res.push_back(resd[2] + '0');
        res.push_back(resd[3] + '0');

        return res;
    }
};
