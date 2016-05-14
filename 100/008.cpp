#include <string>
#include <iostream>
#include <climits>

using namespace std;

int myAtoi(string str) {
        int start = 0;
    	for(; start < str.size() && str[start] == ' '; ++start) {}

	bool neg = false;
    	if(str[start] == '+' || str[start] == '-')
    	{
    		neg = (str[start] == '-');
    		++start;
    	}

	if(!isdigit(str[start]))
		return 0;

	long long rv = 0;
	for(int cur = start; cur < str.size(); ++cur)
	{
		if(!isdigit(str[cur]))
			break;

		rv = 10 * rv + str[cur] - '0';
    		if(neg && -rv <= INT_MIN)
    			return INT_MIN;
		else if(!neg && rv >= INT_MAX)
			return INT_MAX;
	}
    
    	return (neg ? -1 : 1) * static_cast<int>(rv);
}

int main()
{
	cout << myAtoi("-2147483647") << endl;
	return 1;
}
