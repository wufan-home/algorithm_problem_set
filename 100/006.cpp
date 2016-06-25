/*
   The string "PAYPALISHIRING" is written in a 
   zigzag pattern on a given number of rows like this: 
   (you may want to display this pattern in a fixed font for better legibility)

   P   A   H   N
   A P L S I I G
   Y   I   R

   And then read line by line: "PAHNAPLSIIGYIR"
   Write the code that will take a string and make this conversion given a number of rows:
   string convert(string text, int nRows);
   convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

   Solution: 1. Put every characters of the string into the right position (right slot) in an array by the rule.
   Combine these strings into the result.
   2. Put the characters by the method: k * range + i, k * range + range - i (k = 0, 1, ...).
   Notice that: 1) When i == 0 || i = (range / 2 + 1), put only once each time.
   2) Need to check k * range + range - i seperately.
*/

string convert(string s, int numRows) {
        if(s.empty() || numRows <= 1)
		return s;

	vector<string> lines(numRows, string(s.size(), '\0'));
	vector<int> index(numRows, 0);
	int step = 1;
	int line = 0;
	for(int i = 0; i < s.size(); ++i, line += step)
	{
		lines[line][index[line]++] = s[i];
		if(i != 0 && i % (numRows - 1) == 0)
			step *= -1;
	}

	string result(s.size(), '\0');
	for(int i = 0, write = 0; i < numRows; ++i)
	{
		for(int j = 0; lines[i][j] != '\0'; ++j)
			result[write++] = lines[i][j];
	}

	return result;
}

string convert1(string s, int numRows) {
	if(s.empty() || numRows <= 1)
		return s;

	string result(s.size(), '\0');
	int range = 2 * numRows - 2;
	for(int i = 0, write = 0; i < numRows; ++i)
	{
		for(int j = 0; j + i < s.size(); j += range)
		{
			result[write++] = s[j + i];
			if(i != 0 && i != numRows - 1 && j + range - i < s.size())
				result[write++] = s[j + range - i];
		}
				
	}

	return result;
}
