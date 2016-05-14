#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

void Recover(map<string, int>& orig, map<string, int>& backup)
{
  for(map<string, int>::iterator it = orig.begin(); it != orig.end(); ++it) {
    map<string, int>::iterator itb = backup.find(it->first);
    if(itb != backup.end())
      it->second = itb->second;
  }
}

vector<int> findString(const string& s, vector<string> words)
{
  vector<int> results;
  if(s.empty() || words.empty())
    return results;

  map<string, int> word_frequency;
  map<string, int> word_frequency_backup;
  for(int i = 0; i < words.size(); ++i) {
    if(word_frequency.find(words[i]) == word_frequency.end()) {
      word_frequency[words[i]] = 1;
      word_frequency_backup[words[i]] = 1;
    } else {
      ++word_frequency[words[i]];
      ++word_frequency_backup[words[i]];
    }
  }
  
  int search_size = words[0].size();
  int total_search_size = search_size * words.size();
  int total_search_size_backup = total_search_size;
  for(int i = 0; i + total_search_size_backup <= s.size(); ++i) {
    Recover(word_frequency, word_frequency_backup);
    total_search_size = total_search_size_backup;
    for(int j = i; j + search_size <= s.size(); j += search_size) {
      string temp = s.substr(j, search_size);
      map<string, int>::iterator it = word_frequency.find(temp);
      if(it == word_frequency.end() || it->second == 0)
	break;
      else {
	total_search_size -= search_size;
	if(total_search_size == 0) {
	  results.push_back(i);
	  break;
	} else
	  --it->second;
      }
    }
  }
  
  return results;
}

int main()
{
  vector<string> words;
  /*words.push_back("foo");
  words.push_back("bar");
  vector<int> results = findString("barfoothefoobarman", words);
  for(int i = 0; i < results.size(); ++i)
    cout << i + 1 << " - " << results[i] << endl;

  results = findString("foobarfoobar", words);
  cout << results.size() << endl;
  for(int i = 0; i < results.size(); ++i)
    cout << i + 1 << " - " << results[i] << endl;
  */
  words.clear();
  words.push_back("word");
  words.push_back("good");
  words.push_back("best");
  words.push_back("good");
  vector<int> results = findString("wordgoodgoodgoodbestword", words);
  for(int i = 0; i < results.size(); ++i)
    cout << i + 1 << " - " << results[i] << endl;
  return 1;
}
