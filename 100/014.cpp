#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  string prefix("");

  if(strs.empty())
    return prefix;

  prefix = strs[0];
  for(int i = 0; i < strs.size(); ++i)
  {
	  for(int j = 0; prefix[j] != '\0'; ++j)
	  {
		  if(prefix[j] != strs[i][j])
		  {
			  prefix = prefix.substr(0, j);
			  break;
		  }
	  }
  }

  return result;
}

int main()
{
  return 1;
}
