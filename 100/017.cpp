/*
  Given a digit string, return all possible letter combinations that the number could represent.

  A mapping of digit to letters (just like on the telephone buttons) is given below.

  Input:Digit string "23"
  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

  Note:
  Although the above answer is in lexicographical order, your answer could be in any order you want.

  Solution:
  Recursive method.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void GetCombinations(const string& str, int index, string& comb, vector<string>& result,
		     unordered_map<char, vector<char> >& num_map_char)
{
	vector<char>& cs = num_map_char[str[index]];
	for(int i = 0; i < cs.size(); ++i)
	{
		comb[index] = cs[i];
		if(index == str.size() - 1)
			result.push_back(comb);
		else
			GetCombinations(str, index + 1, comb, result, num_map_char);
	}
}

vector<string> letterCombinations(string digits)
{
        if(digits.empty())
		return vector<string>();

	unordered_map<char, vector<char> > num_map_char;
	num_map_char['0'] = vector<char>();
	num_map_char['1'] = vector<char>();
	int start = 0;
	for(char c = '2'; c <= '9'; ++c)
	{
		int end = start + 3;
		if(c == '7' || c == '9')
			++end;

		num_map_char[c] = vector<char>(end - start, 'a');
		for(int i = start; i < end; ++i)
			num_map_char[c][i - start] += i;
		start = end;
	}

	vector<string> result;
	string comb(digits.size(), 'a');
	GetCombinations(digits, 0, comb, result, num_map_char);

	return result;
}

int main()
{
	return 1;
}
