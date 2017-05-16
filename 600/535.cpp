/*
    Note: This is a companion problem to the System Design problem: Design TinyURL.
    TinyURL is a URL shortening service where you enter a URL 
    such as https://leetcode.com/problems/design-tinyurl 
    and it returns a short URL such as http://tinyurl.com/4e9iAk.

    Design the encode and decode methods for the TinyURL service. 
    There is no restriction on how your encode/decode algorithm should work. 
    You just need to ensure that a URL can be encoded to a tiny URL 
    and the tiny URL can be decoded to the original URL.
*/

class Solution {
public:
    Solution()
    {
        bound = 62;
        
        for(int i = 0; i < 10; ++i)
        {
            intToChar[i] = i + '0';
            charToInt[i + '0'] = i;
        }    
        
        for(int i = 10; i < 36; ++i)
        {
            intToChar[i] = i - 10 + 'a';
            charToInt[i - 10 + 'a'] = i;
        }
        
        for(int i = 36; i < 62; ++i)
        {
            intToChar[i] = i - 36 + 'A';
            charToInt[i - 36 + 'A'] = i;
        }    
        
        prefix = "http://tinyurl.com/";
        cachedUrl.push_back("http://tinyurl.com/");
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        cachedUrl.push_back(longUrl);
        int index = cachedUrl.size() - 1;
        
        string tempUrl;
        while(index)
        {
            int reminder = index % bound;
            index /= bound;
            tempUrl.push_back(intToChar[reminder]);
        }
        
        for(int l = 0, r = tempUrl.size() - 1; l < r; ++l, --r)
            swap(tempUrl[l], tempUrl[r]);

        string shortUrl = prefix;
        shortUrl.append(tempUrl);
        
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(shortUrl.size() <= cachedUrl[0].size())
            return "";
            
        string stringIndex = shortUrl.substr(cachedUrl[0].size(), shortUrl.size() - cachedUrl[0].size());
        if(stringIndex == "0")
            return "";
        
        int index = 0;
        for(int i = 0; i < stringIndex.size(); ++i)
            index = 10 * index + charToInt[stringIndex[i]];
            
        return index >= cachedUrl.size() ? "" : cachedUrl[index];
    }
    
private:
    unordered_map<int, char> intToChar;
    unordered_map<char, int> charToInt;
    vector<string> cachedUrl;
    
    int bound;
    
    string prefix;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
