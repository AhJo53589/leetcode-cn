
//string decodeString(string s) {
//	int num = 0;
//	string cur = "";
//	stack<int> nums;
//	stack<string> str;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] >= '0' && s[i] <= '9') {
//			num = num * 10 + s[i] - '0';
//		}
//		else if (s[i] == '[') {
//			nums.push(num);
//			num = 0;
//			str.push(cur);
//			cur = "";
//		}
//		else if (s[i] == ']') {
//			int k = nums.top();
//			nums.pop();
//			for (int i = 0; i < k; i++) {
//				str.top() += cur;
//			}
//			cur = str.top();
//			str.pop();
//		}
//		else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
//			cur = cur + s[i];
//		}
//	}
//	return cur;
//}

//////////////////////////////////////////////////////////////////////////
string getNormal(string s)
{
	string str;
	for (char c : s)
	{
		if (c <= '9' && c >= '0') return str;
		str += c;
	}
	return str;
}

string getNum(string s)
{
	string str;
	for (char c : s)
	{
		if (c == '[') return str;
		str += c;
	}
	return str;
}

string getSub(string s)
{
	string str;
	stack<char> st;
	for (char c : s)
	{
		if (c == '[') st.push(c);
		if (c == ']') st.pop();
		str += c;
		if (st.empty()) return str;
	}
	return str;
}

string decodeString(string s)
{
	string strText;

	int i = 0;
	while (i < s.size())
	{
		string strTemp;
		strTemp = getNormal(s.substr(i, s.size()));
		i += strTemp.size();
		strText += strTemp;

		strTemp = getNum(s.substr(i, s.size()));
		i += strTemp.size();
		string strNum = strTemp;

		strTemp = getSub(s.substr(i, s.size()));
		i += strTemp.size();
		if (strTemp.size() > 2)
		{
			string strSubText = decodeString(strTemp.substr(1, strTemp.size() - 2));
			int iNum = stoi(strNum);
			while (iNum-- > 0) strText += strSubText;
		}
	}

	return strText;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
	return decodeString(s);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

