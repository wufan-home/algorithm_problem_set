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
        int size = people.size();
        vector<pair<int, int>> reconstruction;
        if(size == 0)
            return reconstruction;
            
        unordered_map<int, vector<int>> rankGroupsByHeight;
        unordered_map<int, int> heightMapIndex;
        vector<pair<int, int>> heightCount;
        for(int i = 0; i < size; ++i)
        {
            int height = people[i].first;
            int rank = people[i].second;
            if(rankGroupsByHeight.find(height) == rankGroupsByHeight.end())
            {
                rankGroupsByHeight[height] = vector<int>();
                heightMapIndex[height] = 0;
                heightCount.push_back(make_pair(height, 0));
            }
            
            rankGroupsByHeight[height].push_back(rank);
        }
        
        for(unordered_map<int, vector<int>>::iterator it = rankGroupsByHeight.begin(); 
            it != rankGroupsByHeight.end(); ++it)
        {
            vector<int> &ranks = it->second;
            sort(ranks.begin(), ranks.end());
        }
        sort(heightCount.begin(), heightCount.end(), compare);
        
        while(reconstruction.size() < size)
        {
            for(int i = 0; i < heightCount.size(); ++i)
            {
                int height = heightCount[i].first;
                int count = heightCount[i].second;
                //cout << rankGroupsByHeight[height][heightMapIndex[height]] << " <-->" << count << endl;
                if(rankGroupsByHeight[height][heightMapIndex[height]] == count)
                {
                    reconstruction.push_back(make_pair(height, count));
                    
                    ++heightMapIndex[height];
                    for(int j = 0; j <= i; ++j)
                        ++heightCount[j].second;
                    
                    /*for(int j = 0; j < heightCount.size(); ++j)
                        cout << heightCount[j].first << ": " << heightCount[j].second << "; ";
                    cout << endl;*/
                    
                    break;
                }
            }
            /*if(reconstruction.size() == 4)
                break;*/
        }
        
        return reconstruction;
    }
    
private:
    static bool compare(const pair<int, int> &l, const pair<int, int> &r)
    {
        return l.first <= r.first;
    }
};
