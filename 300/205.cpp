#include <iostream>
#include <string>
#include <unordered_map>
#include <stdio.h>
#include <string.h>

using namespace std;

bool isIsomorphic(string s, string t)
{
	if(s.size() != t.size())
		return false;

	int image[256];
	memset(image, -1, 256 * sizeof(int));
	int preimage[256];
	memset(preimage, -1, 256 * sizeof(int));
	for(int i = 0; i < s.size(); ++i)
	{
		int i_index = t[i];
		int pi_index = s[i];
		cout << pi_index << ", " << i_index << endl;
		cout << image[pi_index] << ", " << preimage[i_index] << endl;
		if(image[pi_index] == -1 && preimage[i_index] == -1)
		{
			image[pi_index] = i_index;
			preimage[i_index] = pi_index;
		}
		else if(preimage[i_index] != pi_index)
			return false;
	}

	return true;
}

int main()
{
	cout << isIsomorphic("foo", "app") << endl;
	cout << isIsomorphic("13", "24") << endl;
	return 1;
}
