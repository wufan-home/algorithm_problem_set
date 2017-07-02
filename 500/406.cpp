/*
    Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), 
    where h is the height of the person and k is the number of people in front of this person 
    who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

    Note:
    The number of people is less than 1,100.

    Example

    Input:
    [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

    Output:
    [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), compare);
        for(int i = people.size() - 1; i >= 0;)
        {
            int height = people[i].first;
            int start = i;
            for(; start >= 0 && people[start].first == height; --start) {}
            ++start;
            for(int j = i; j >= start; --j)
            {
                int position = people[j].second;
                for(int k = j; position > k - start; ++k)
                    swap(people[k], people[k + 1]);
            }
            
            i = start - 1;
        }
        
        return people;
    }
    
private:
    static bool compare(const pair<int, int>& l, const pair<int, int>& r)
    {
        return l.first < r.first || (l.first == r.first && l.second < r.second);
    }
};
