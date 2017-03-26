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
        string result = s;
	    if(numRows == 1)
	        return s;

	    const int unit_length = 2 * numRows - 2;
	    int index = 0;
	    for(int i = 0; i < numRows; ++i)
	    {
	        for(int j = 0; j * unit_length + i < s.size(); ++j)
	        {
	            result[index++] = s[j * unit_length + i];
	            if(i != 0 && i != unit_length - i && j * unit_length + unit_length - i < s.size())
	                result[index++] = s[j * unit_length + unit_length - i];
	        }
	    }
	    return result;
    }
