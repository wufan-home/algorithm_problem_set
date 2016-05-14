#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string sample = "abcb";

  int max_len = 0;
  int local_max_len = 0;
  vector<int> valid_index(256, -1);
  int start = 0;
  for(int i = 0; i < sample.size(); ++i) {
    cout << valid_index[sample[0]] << ", ";
    cout << valid_index[sample[1]] << ", ";
    cout << valid_index[sample[2]] << endl;
    if(valid_index[sample[i]] >= start) {
      local_max_len -= valid_index[sample[i]] - start + 1;
      start = valid_index[sample[i]] + 1;
    }

    valid_index[sample[i]] = i;
    cout << local_max_len << endl;
    ++local_max_len;
    if(local_max_len > max_len)
      max_len = local_max_len;
  }

  cout << max_len << endl;
  return 1;
}
