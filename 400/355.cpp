/*
  Design a simplified version of Twitter where users can post tweets, 
  follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
  postTweet(userId, tweetId): Compose a new tweet.
  getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. 
  Each item in the news feed must be posted by users who the user followed or by the user herself. 
  Tweets must be ordered from most recent to least recent.
  follow(followerId, followeeId): Follower follows a followee.
  unfollow(followerId, followeeId): Follower unfollows a followee.
  Example:
  Twitter twitter = new Twitter();
  // User 1 posts a new tweet (id = 5).
  twitter.postTweet(1, 5);
  // User 1's news feed should return a list with 1 tweet id -> [5].
  twitter.getNewsFeed(1);
  // User 1 follows user 2.
  twitter.follow(1, 2);
  // User 2 posts a new tweet (id = 6).
  twitter.postTweet(2, 6);
  // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
  // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
  twitter.getNewsFeed(1);
  // User 1 unfollows user 2.
  twitter.unfollow(1, 2);
  // User 1's news feed should return a list with 1 tweet id -> [5],
  // since user 1 is no longer following user 2.
  twitter.getNewsFeed(1);
*/

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() { }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(m_accounts.find(userId) == m_accounts.end())
            m_accounts[userId] = unordered_set<int>();
        if(m_accounts[userId].empty())
            m_accounts[userId].insert(userId);
        
        m_posts.push_back(make_pair(tweetId, userId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. 
	Each item in the news feed must be posted by users who the user followed or by the user herself. 
	Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> news;
        //if(m_accounts.find(userId) == m_accounts.end())
          //  cout << userId << " is not found! " << endl;

        for(int i = m_posts.size() - 1, write = 0; i >= 0 && write < 10; --i)
        {
            if(m_accounts[userId].find(m_posts[i].second) != m_accounts[userId].end())
            {
                news.push_back(m_posts[i].first);
                ++write;
            }
        }
        return news;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(m_accounts.find(followerId) == m_accounts.end())
            cout << followerId << " is not found! add" << endl;
            
        if(m_accounts.find(followerId) == m_accounts.end())
        {
            m_accounts[followerId] = unordered_set<int>();
            m_accounts[followerId].insert(followerId);
        }  

        m_accounts[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(m_accounts.find(followerId) != m_accounts.end() && 
            m_accounts[followerId].find(followeeId) != m_accounts[followerId].end() &&
            followerId != followeeId)
            m_accounts[followerId].erase(followeeId);
    }
    
private:
    vector<pair<int, int> > m_posts;
    unordered_map<int, unordered_set<int> > m_accounts;
};

class Twitter1 {
public:
    /** Initialize your data structure here. */
    Twitter() : current(0) {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(m_relations.find(userId) == m_relations.end())
            m_relations[userId] = unordered_set<int>();
        if(m_relations[userId].empty())
            m_relations[userId].insert(userId);

        m_posts[userId].push_back(make_pair(tweetId, current++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. 
	Each item in the news feed must be posted by users who the user followed or by the user herself. 
	Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> news;
        if(m_relations.find(userId) == m_relations.end())
            return news;
         
        unordered_set<int>& friends = m_relations[userId];   
        unordered_map<int, int> id_map_index;
        for(unordered_set<int>::iterator it = friends.begin(); it != friends.end(); ++it)
        {
            if(!m_posts[*it].empty())
                id_map_index[*it] = m_posts[*it].size() - 1;
        }

        for(int write = 0; write < 10 && !id_map_index.empty(); ++write)
        {
            unordered_map<int, int>::iterator it = id_map_index.begin();
            int latest = m_posts[it->first][it->second].second;
            for(unordered_map<int, int>::iterator it1 = id_map_index.begin(); it1 != id_map_index.end(); ++it1)
            {
                if(m_posts[it1->first][it1->second].second > latest)
                {
                    it = it1;
                    latest = m_posts[it1->first][it1->second].second;
                }
            }
            news.push_back(m_posts[it->first][it->second].first);
            if(--it->second < 0)
                id_map_index.erase(it->first);
        }
        

        return news;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {
        if(m_relations.find(followerId) == m_relations.end())
            m_relations[followerId] = unordered_set<int>();

        m_relations[followerId].insert(followerId);
        m_relations[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId && m_relations.find(followerId) != m_relations.end())
            m_relations[followerId].erase(followeeId);
    }
    
private:
    unordered_map<int, vector<pair<int, int>>> m_posts;
    unordered_map<int, unordered_set<int>> m_relations;
    long long current;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
