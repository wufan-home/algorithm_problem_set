/*
  Median is the middle value in an ordered integer list. 
  If the size of the list is even, 
  there is no middle value. So the median is the mean of the two middle value.
  Examples:

  [2,3,4] , the median is 3

  [2,3], the median is (2 + 3) / 2 = 2.5

  Design a data structure that supports the following two operations:

  void addNum(int num) - Add a integer number from the data stream to the data structure.
  double findMedian() - Return the median of all elements so far.

  For example:

  add(1)
  add(2)
  findMedian() -> 1.5
  add(3) 
  findMedian() -> 2

*/

class compare
{
public:
    bool operator() (const int lhs, const int rhs) const
    {
        return lhs >= rhs;
    }
};

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() { }
    
    void addNum(int num) {
        if(left_pq.empty() || num <= left_pq.top())
            left_pq.push(num);
        else
            right_pq.push(num);
       
        if(left_pq.size() >= right_pq.size() + 2)
        {
            right_pq.push(left_pq.top());
            left_pq.pop();
        }
        else if(right_pq.size() >= left_pq.size() + 2)
        {
            left_pq.push(right_pq.top());
            right_pq.pop();
        }
    }
    
    double findMedian() {
        const int total_size = left_pq.size() + right_pq.size();
        if(total_size % 2 != 0)
        {
            return left_pq.size() >= right_pq.size() ?
                left_pq.top() : right_pq.top();
        }
        else
        {
            return ((double) left_pq.top() + (double) right_pq.top()) / 2;
        }
    }

private:
    priority_queue<int, vector<int>, compare> right_pq;
    priority_queue<int> left_pq;
};
