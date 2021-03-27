// 290.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <map>
#include <string>

using namespace std;

bool wordPattern(string pattern, string str) {
	map<string, char> content_pattern;
	bool used_pattern[256] = { false };

	int i = 0, j = 0;
	for (; i < str.size() && j < pattern.size();) {
		string current("");

		for (; i < str.size() && str[i] != ' '; ++i) {
			current.push_back(str[i]);
		}
		++i;

		if (content_pattern.find(current) != content_pattern.end()) {
			if (content_pattern[current] != pattern[j])
				return false;
			++j;
		}
		else if (used_pattern[pattern[j]] == true) {
			return false;
		}
		else {
			content_pattern[current] = pattern[j];
			used_pattern[pattern[j++]] = true;
		}
	}

	return (i == str.size() && j == pattern.size());
};

int main()
{
	cout << wordPattern("abba", "dog cat cat dog") << endl;
    return 0;
}

