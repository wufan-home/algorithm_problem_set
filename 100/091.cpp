/*
   A message containing letters from A-Z is being encoded to numbers using the following mapping:

   'A' -> 1
   'B' -> 2
   ...
   'Z' -> 26

   Given an encoded message containing digits, determine the total number of ways to decode it.
   
   For example,
   Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
   
   The number of ways decoding "12" is 2. 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDecodings(string s) {
	if(s.empty() || s[0] == '0')
		return 0;
	vector<int> aux(s.size() + 1, 1);
	aux[1] = s[0] != '0' ? 1 : 0;
	for(int i = 2; i <= s.size(); ++i)
	{
		aux[i] = (s[i - 1] != '0' ? aux[i - 1] : 0) +
			((s[i - 2] != '0') && (s[i - 2] < '2' || (s[i - 2] == '2' && s[i - 1] < '7')) ? aux[i - 2] : 0);
	}
	return aux[s.size()];
}

int main()
{
	cout << numDecodings("100") << endl;
	return 1;
}
