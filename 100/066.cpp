/*
  Given a non-negative number represented as an array of digits, plus one to the number.

  The digits are stored such that the most significant digit is at the head of the list.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
        if(digits.empty())
		return digits;

	++digits[digits.size() - 1];
	int overflow = digits[digits.size() - 1] / 10;
	digits[digits.size() - 1] %= 10;
	for(int i = digits.size() - 2; i >= 0 && overflow; --i)
	{
		overflow = (++digits[i]) / 10;
		digits[i] %= 10;
	}

	if(overflow)
		digits.insert(digits.begin(), 1);

	return digits;
}

int main()
{
	vector<int> d({9, 2, 9, 9 , 9});
	plusOne(d);
	for(int i = 0; i < d.size(); ++i)
		cout << d[i];
	cout << endl;
	return 1;
}
