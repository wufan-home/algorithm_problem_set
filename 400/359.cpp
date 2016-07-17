/*
  Design a logger system that receive stream of messages along with its timestamps, 
  each message should be printed if and only if it is not printed in the last 10 seconds.
  Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.
  It is possible that several messages arrive roughly at the same time.
  Example:
  Logger logger = new Logger();
  // logging string "foo" at timestamp 1
  logger.shouldPrintMessage(1, "foo"); returns true; 
  // logging string "bar" at timestamp 2
  logger.shouldPrintMessage(2,"bar"); returns true;
  // logging string "foo" at timestamp 3
  logger.shouldPrintMessage(3,"foo"); returns false;
  // logging string "bar" at timestamp 8
  logger.shouldPrintMessage(8,"bar"); returns false;
  // logging string "foo" at timestamp 10
  logger.shouldPrintMessage(10,"foo"); returns false;
  // logging string "foo" at timestamp 11
  logger.shouldPrintMessage(11,"foo"); returns true;

  Solutions: 1. Use a hash-map to take all string and timestamp pairs.
  2. Use the method to least-used memory block.
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

class Logger {
public:
    struct ListNode
    {
        ListNode() : m_time(-1), m_message(""), next(NULL) {}
        int m_time;
        string m_message;
        ListNode *next;
    };
    
    Logger() : m_size(10)
    {
        m_head = new ListNode();
        ListNode *cur = m_head;
        for(int i = 0; i < 10; ++i, cur = cur->next)
            cur->next = new ListNode();
    }
    
    bool shouldPrintMessage(int timestamp, string message) 
    {
        for(ListNode *back = m_head, *front = m_head->next; ; back = front, front = front->next)
        {
            if(abs(front->m_time - timestamp) >= 10)
            {
                front->m_time = -1;
                front->m_message = "";
            }
                
            if(front->m_message == message)
                return false;
                
            if(front->next == NULL)
            {
                back->next = NULL;
                front->m_time = timestamp;
                front->m_message = message;
                ListNode *temp = m_head->next;
                m_head->next = front;
                front->next = temp;
                break;
            }
        }

        return true;
    }
private:
    ListNode *m_head;
};

