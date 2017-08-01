/*
    The API: int read4(char *buf) reads 4 characters at a time from a file.

    The return value is the actual number of characters read. For example, 
    it returns 3 if there is only 3 characters left in the file.

    By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

    Note:
    The read function may be called multiple times.
*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int actual_num = 0;
        for(; !char_stack.empty(); ++actual_num) {
            *(buf + actual_num) = char_stack.top();
            char_stack.pop();
        }
        for(int i = actual_num; i < n && actual_num == i; i += 4, actual_num += read4(buf + actual_num)) {}
        while(actual_num > n) {
            char_stack.push(*(buf + actual_num - 1));
            *(buf + actual_num--) = '\0';
        }
        
        return min(actual_num, n);
    }
    
private:
    stack<char> char_stack;
};
