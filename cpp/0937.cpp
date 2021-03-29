/*
    You have an array of logs.  Each log is a space delimited string of words.

    For each log, the first word in each log is an alphanumeric identifier.  Then, either:

        Each word after the identifier will consist only of lowercase letters, or;
        Each word after the identifier will consist only of digits.

    We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

    Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

    Return the final order of the logs.



    Example 1:

    Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
    Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]



    Constraints:

        0 <= logs.length <= 100
        3 <= logs[i].length <= 100
        logs[i] is guaranteed to have an identifier, and a word after the identifier.


*/

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // Partition.
        int size = logs.size();
        int barrier = size - 1;
        for (int i = size - 1; i >= 0; --i) {
            if (checkLogType(logs[i])) {
                swap(logs[i], logs[barrier--]);
            }
        }

        sort(logs.begin(), logs.begin() + barrier + 1, compare);
        return logs;
    }
    
private:
    static bool compare(const string& l, const string& r) {
        int lsize = l.size();
        int ls = 0;
        for (; ls < lsize && l[ls++] != ' ';) {}
        
        int rsize = r.size();
        int rs = 0;
        for (; rs < rsize && r[rs++] != ' ';) {}
        
        for (; ls < lsize && rs < rsize; ++ls, ++rs) {
            if (l[ls] > r[rs]) {
                return false;
            }
            
            if (l[ls] < r[rs]) {
                return true;
            }
        }
        
        if (ls < lsize && rs == rsize) {
            return false;
        }
        
        return true;
    }
    
    bool checkLogType(const string& log) {
        // Get content
        int size = log.size();
        int index = 0;
        for (; index < size && log[index] != ' '; ++index) {}
        return log[++index] >= '0' && log[index] <= '9';
    }
};
