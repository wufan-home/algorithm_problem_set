/*
  Given an integer, convert it to a roman numeral.
  Input is guaranteed to be within the range from 1 to 3999.
*/

string AddChar(int num, char single, char five, char ten) {
	string result("");
	switch (num) {
	case 1:
		result.push_back(single);
		break;
	case 2:
		result.push_back(single);
		result.push_back(single);
		break;
	case 3:
		result.push_back(single);
		result.push_back(single);
		result.push_back(single);
		break;
	case 4:
		result.push_back(single);
		result.push_back(five);
		break;
	case 5:
		result.push_back(five);
		break;
	case 6:
		result.push_back(five);
		result.push_back(single);
		break;
	case 7:
		result.push_back(five);
		result.push_back(single);
		result.push_back(single);
		break;
	case 8:
		result.push_back(five);
		result.push_back(single);
		result.push_back(single);
		result.push_back(single);
		break;
	case 9:
		result.push_back(single);
		result.push_back(ten);
		break;
	}

	return result;
}

string intToRoman(int num) {
	int digits[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < 4; ++i) {
		digits[3 - i] = num % 10;
		num /= 10;
	}

	string result("");
	for (int i = 0; i < 4; ++i) {
		switch (i) {
		case 0:
			for (int i = 0; i < digits[i]; ++i)
				result.push_back('M');
			break;
		case 1:
			result.append(AddChar(digits[i], 'C', 'D', 'M'));
			break;
		case 2:
			result.append(AddChar(digits[i], 'X', 'L', 'C'));
			break;
		case 3:
			result.append(AddChar(digits[i], 'I', 'V', 'X'));
			break;
		}
	}

	return result;
}
