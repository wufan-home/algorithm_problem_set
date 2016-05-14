/*
  Given two numbers represented as strings, return multiplication of the numbers as a string.
 */

#include <string>
#include <iostream>

using namespace std;

string multiply(string num1, string num2) {
	if(num1.empty() || num2.empty())
		return "";
	
	if(num1 == "0" || num2 == "0")
		return "0";

	if(num1 == "1")
		return num2;
	else if(num2 == "1")
		return num1;

	int size1 = num1.size();
	int size2 = num2.size();
        string product(size1 + size2, '0');
	for(int i = size2 - 1, start_index = product.size() - 1; i >= 0; --i, --start_index)
	{
		if(num2[i] == '0')
			continue;

		int overflow_last = 0;
		int j = 0;
		for(; j < size1; ++j)
		{
			int prod = (num1[size1 - 1 - j] - '0') * (num2[i] - '0')
				+ overflow_last + product[start_index - j] - '0';
			overflow_last = prod / 10;
			product[start_index - j] = prod % 10 + '0';
		}

		product[start_index - j] = product[start_index - j] + overflow_last;			
	}

	int start = 0;
	for(;start < product.size() && product[start] == '0'; ++start) {}
	return product.substr(start);
}


int main()
{
	//cout << multiply("0", "0") << endl;
	//cout << multiply("0", "1") << endl;
	//cout << multiply("1", "2") << endl;
	cout << multiply("11", "11") << endl;

	return 1;
}
