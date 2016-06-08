// 71.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

string simplifyPath(string path)
{
	string abs_path("");
	if (path.empty())
		return "";

	stack<string> path_name;
	for (int i = 0; i < path.size();)
	{
		if (path[i] == '/')
			++i;
		else
		{
			int j = i;
			for (; j < path.size(); ++j)
			{
				if (path[j] == '/')
					break;
			}
			string current = path.substr(i, j - i);
			i = j;
			if (current == ".")
				continue;
			else if (current == "..")
			{
				if (!path_name.empty())
					path_name.pop();
			}
			else
				path_name.push(current);
		}
	}

	vector<string> paths;
	for (; !path_name.empty(); path_name.pop())
		paths.push_back(path_name.top());

	for (int i = paths.size() - 1; i >= 0; --i)
		abs_path += "/" + paths[i];

	return (abs_path.empty() ? "/" : abs_path);
}

int main()
{
	cout << simplifyPath("/..") << endl;
	cout << simplifyPath("/...") << endl;
	cout << simplifyPath("/.") << endl;
    return 0;
}

