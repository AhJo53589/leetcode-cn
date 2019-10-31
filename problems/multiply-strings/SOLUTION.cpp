
//string addStrings(string num1, string num2)
//{
//	while (num1.size() < num2.size()) num1.insert(num1.begin(), '0');
//	while (num2.size() < num1.size()) num2.insert(num2.begin(), '0');
//
//	string sum;
//	int iCarry = 0;
//	for (int i = num1.size() - 1; i >= 0; i--)
//	{
//		int val = (int)(num1[i] - '0') + (int)(num2[i] - '0') + iCarry;
//		iCarry = val / 10;
//		val %= 10;
//		char c = (char)(val) + '0';
//		sum.push_back(c);
//	}
//	if (iCarry != 0) sum.push_back((char)(iCarry) + '0');
//
//	reverse(sum.begin(), sum.end());
//
//	return sum;
//}
//
//string multiply(string num1, string num2)
//{
//	if (num1 == "0" || num2 == "0") return "0";
//
//	string sum;
//	int len1 = num1.size();
//	int len2 = num2.size();
//	for (int i = 0; i < len1; i++)
//	{
//		for (int j = 0; j < len2; j++)
//		{
//			int val = (int)(num1[i] - '0') * (int)(num2[j] - '0');
//			int zero = (len1 - i - 1) + (len2 - j - 1);
//			string t = to_string(val);
//			while (zero-- > 0) t += "0";
//			sum = addStrings(sum, t);
//		}
//	}
//	return sum;
//}


//////////////////////////////////////////////////////////////////////////
string multiply(string num1, string num2)
{
	string ret(num1.size() + num2.size(), '0');
	for (int i = num1.size() - 1; i >= 0; i--)
	{
		int val1 = num1[i] - '0';
		for (int j = num2.size() - 1; j >= 0; j--)
		{
			int val2 = num2[j] - '0';
			int sum = (ret[i + j + 1] - '0') + val1 * val2;
			ret[i + j + 1] = (char)(sum % 10 + '0');
			ret[i + j] += sum / 10;
		}
	}

	for (int i = 0; i < ret.size(); i++)
	{
		if (ret[i] != '0' || i == ret.size() - 1) return ret.substr(i, ret.size() - i);
	}
	return "0";
}


//////////////////////////////////////////////////////////////////////////
string _solution_run(string num1, string num2)
{
	return multiply(num1,num2);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/multiply-strings/tests.txt";
}

