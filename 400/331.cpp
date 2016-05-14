/*
  One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #

For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isValidSerialization(string preorder) {
        if(preorder.empty() || preorder[0] == ',')
		return false;

	int size = preorder.size();
	int vi = 0;
	stack<string> st_value;
	while(vi < size || !st_value.empty())
	{
		string str("");
		for(; vi < size; ++vi)
		{
			if(preorder[vi] == ',')
			{
				++vi;
				break;
			}
			str.push_back(preorder[vi]);
		}

		if(str == "")  //only root of a subtree is provided.
			return st_value.empty();
		else if(str != "#")
			st_value.push(str);
		else
		{
			if(st_value.empty())
				break;
				
			st_value.pop();

			if(vi >= size)  // Only left child is provided.
				return false;

			// We do not move the index here,
			// since if the next value is a #, then it will pop out the local root in the next round.
		}
	}

	return vi == size;  // More values than real needed.
}

int main()
{
	cout << isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
	cout << isValidSerialization("1,#") << endl;
	cout << isValidSerialization("1") << endl;
	return 1;
}
