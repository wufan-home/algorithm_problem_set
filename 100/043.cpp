/*
  Given two numbers represented as strings, 
  return multiplication of the numbers as a string.

  Note:
  The numbers can be arbitrarily large and are non-negative.
  Converting the input string to integer is NOT allowed.
  You should NOT use internal library such as BigInteger.
*/

string multiply(string num1, string num2)
{
	while(num1[0] == '0')
		num1.erase(num1.begin());

	while(num2[0] == '0')
		num2.erase(num2.begin());

	if(num1.empty() || num2.empty())
		return "0";

	int len1 = num1.size();
	int len2 = num2.size();
	string result(len1 + len2, '0');
	for(int i = 1; i <= len2; ++i)
	{
		if(num2[len2 - i] == '0')
			continue;

		int start = len1 + len2 - i;
		int overflow = 0;
		for(int j = 1; j <= len1; ++j)
		{
			int product = (result[start] - '0') + (num2[len2 - i] - '0') * (num1[len1 - j] - '0') + overflow;
			overflow = product / 10;
			result[start--] = '0' + product % 10;
		}
		
		while(overflow)
		{
			int sum = (result[start] - '0') + overflow;
			overflow = sum / 10;
			result[start--] = '0' + sum % 10;
		}
	}

	while(result[0] == '0')
		result.erase(result.begin());

	return result;
}
