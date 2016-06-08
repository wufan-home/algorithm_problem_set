/*
  Given two binary strings, return their sum (also a binary string).
  For example,
  a = "11"
  b = "1"
  Return "100". 
  
  Solution:
  1. The solution is equivelant to merging a shorter array to another one.
  2. First, find out which one is longer. Use references to solve the problem.
  3. Use two pointers (one for each array) to merge.
*/

string addBinary(string a, string b) {
        if(a.empty() || b.empty())
		return a.empty() ? b : a;

	string& l_str = a.size() >= b.size() ? a : b;
	string& s_str = a.size() >= b.size() ? b : a;
	int size = l_str.size();
	int overflow = 0;
	for(int l = l_str.size() - 1, s = s_str.size() - 1; l >= 0; --l, --s)
	{
		int sum = l_str[l] - '0' + (s >= 0 ? s_str[s] - '0' : 0) + overflow;
		overflow = sum / 2;
		sum %= 2;
		l_str[l] = sum + '0';
	}

	if(overflow)
		l_str.insert(l_str.begin(), '1');

	return l_str;
}
