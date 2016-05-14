#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;

vector<int> FindAllSubstring(const string& sample,
			     const string& pattern)
{
  vector<int> all_valid_starts;
  if(pattern.size() == sample.size()) {
    for(int i = 0; i < pattern.size(); ++i) {
      if(pattern[i] != sample[i])
	return all_valid_starts;
    }
    all_valid_starts.push_back(0);
  } else if(pattern.size() < sample.size()) {
    vector<bool> char_set(26, false);
    for(int i = 0; i < pattern.size(); ++i)
      char_set[pattern[i] - 'a'] = true;

    int valid_search_range = sample.size() - pattern.size();
    for(int i = 0; i <= valid_search_range;) {
      int tested_length = 0;
      for(; tested_length < pattern.size(); ++tested_length) {
	if(sample[i + tested_length] != pattern[tested_length]) {
	  if(!char_set[sample[i + tested_length]]) {
	    i += tested_length + 1;
	  } else {
	    for(int j = 1; j <= tested_length; ++j) {
	      if(sample[i + j] == pattern[0])
		i += j;
	    }
	  }
	}
      }

      if(tested_length == pattern.size())
	all_valid_starts.push_back(i++);
    }
  }

  return all_valid_starts;
}

bool wordBreakAux(const string& word,
		  const set<string>& dict,
		  map<string, int>& item_status)
{
  for(set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
    if(item_status[*it] != 0)
      continue;

    vector<int> valid_starts = FindAllSubstring(word, *it);
    if(valid_starts.empty())
      continue;

    for(int i = 0; i < valid_starts.size(); ++i) {
      if(valid_starts[i] == 0
	 && dict.begin()->size() == word.size())
	return true;
      
      if(wordBreakAux(word.substr(0, valid_starts[i]), dict, item_status)
	 && wordBreakAux(word.substr(valid_starts[i] + dict.begin()->size(),
				     word.size() - valid_starts[i] - dict.begin()->size() + 1),
			 dict, item_status))
	return true;
    }
  }
  
  return false;
}

bool wordBreak(const string& word, set<string>& dict)
{
  if(word.empty() || dict.empty())
    return false;

  map<string, int> item_status;
  for(set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
    vector<int> valid_starts = FindAllSubstring(word, *it);
    if(valid_starts.empty()) {
      item_status[*it] = -1;
      continue;
    } else
      item_status[*it] = 1;

    for(int i = 0; i < valid_starts.size(); ++i) {
      if(valid_starts[i] == 0 && dict.begin()->size() == word.size())
	return true;

      if(wordBreakAux(word.substr(0, valid_starts[i]), dict, item_status)
	 && wordBreakAux(word.substr(valid_starts[i] + dict.begin()->size(),
				     word.size() - valid_starts[i] - dict.begin()->size() + 1),
			 dict, item_status))
	return true;
    }
    
    item_status[*it] = 0;
  }

  return false;
}

int main()
{
  return 1;
}
