/*

*/

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() { }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(m_message_timestamp.find(message) == m_message_timestamp.end()) 
            m_message_timestamp[message] = INT_MAX;

        if(abs(m_message_timestamp[message] - timestamp) >= 10)
        {
            m_message_timestamp[message] = timestamp;
            return true;
        }
        
        return false;
    }
private:
    unordered_map<string, int> m_message_timestamp;
};

