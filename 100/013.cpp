/*
  Given a roman numeral, convert it to an integer.
  Input is guaranteed to be within the range from 1 to 3999.
  Solution:
  Scan the string from the last char to the first, 
  if the mapped value of the current one is smaller than the previous one,
  minus the mapped value of the current char.
  Otherwise, add the value.

  Solutions:
  Run from the last char of the string: If the current value is smaller than its right one,
  use the total value to substract the value of the char; 
  otherwise, add the value to the total value.
*/

int romanToInt(string s) {
        if(s.empty())
		return 0;

	int rton[256] = {0};
        rton['I'] = 1;
        rton['V'] = 5;
        rton['X'] = 10;
        rton['L'] = 50;
        rton['C'] = 100;
        rton['D'] = 500;
        rton['M'] = 1000;
	int result = rton[s[s.size() - 1 ]];
	for(int i = s.size() - 2; i >= 0; --i)
		result += (rton[s[i]] < rton[s[i + 1]] ? -1 : 1) * rton[s[i]];

	return result;
}
