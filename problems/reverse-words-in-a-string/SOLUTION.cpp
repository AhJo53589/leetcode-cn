
string reverseWords(string s)
{
	stack<string> st;
	string sub;
	s += " ";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			sub += s[i];
		}
		else
		{
			if (!sub.empty())
			{
				st.push(sub);
				sub.clear();
			}
		}
	}
	string str;
	while (!st.empty())
	{
		str += st.top();
		st.pop();
		str += " ";
	}
	if (!str.empty())
	{
		str = str.substr(0, str.size() - 1);
	}
	return str;
}

//string reverseWords(string s)
//{
//	string ret;
//	for (int i = s.size() - 1; i >= 0; i--)
//	{
//		if (s[i] == ' ')
//		{
//			ret += s.substr(i + 1, s.size() - i);
//			ret += " ";
//			s = s.substr(0, i);
//		}
//	}
//	ret += s;
//	return ret;
//}

//string reverseWords(string s)
//{
//	int start = 0, end = s.length() - 1;
//	while (start < s.length() && s[start] == ' ') ++start;
//	while (end >= 0 && s[end] == ' ') --end;
//	if (start > end)
//	{
//		s[end + 1] = '\0';
//		return string(s.c_str());
//	}
//	++end;
//
//	int offset = 0;
//	int subStart = start;
//
//	for (int idx = start; idx <= end; ++idx)
//	{
//		if (s[idx] == ' ' || idx == end)
//		{
//			if (s[idx - 1] != ' ' || idx == end)
//			{
//				int wordLen = idx - subStart;
//				int swapNum = (idx - offset) / 2;
//				for (int i = 0; i < wordLen; ++i, ++offset)
//				{
//					if (i < swapNum)
//					{
//						char temp = s[offset];
//						s[offset] = s[idx - 1 - i];
//						s[idx - 1 - i] = temp;
//
//						cout << s << endl;
//					}
//				}
//				if (idx != end)
//				{
//					s[offset++] = ' ';
//					cout << s << endl;
//				}
//			}
//			subStart = idx + 1;
//		}
//	}
//
//	s[offset] = '\0';
//	cout << s << endl;
//	for (int i = 0; i < (offset / 2); ++i)
//	{
//		char temp = s[i];
//		s[i] = s[offset - 1 - i];
//		s[offset - 1 - i] = temp;
//	}
//	cout << s << endl;
//
//	return string(s.c_str());;
//}


//////////////////////////////////////////////////////////////////////////
//string reverseWords(string s)
//{
//	string ret;
//	int ibeg = 0;			// 单词开始标志位
//	int iend = s.size();	// 单词结束标志位
//	for (int i = s.size() - 1; i >= 0; i--)	// 从后往前遍历
//	{
//		if (s[i] == ' ')	// 遇到空格，开始拷贝单词
//		{
//			ibeg = i + 1;	// 更新标志位
//			for (int j = ibeg; j < iend; j++)
//			{
//				ret += s[j];
//			}
//			ret += " ";		// 补空格
//			iend = i;		// 更新标志位
//		}
//	}
//	for (int j = 0; j < iend; j++)	// 原句第一个单词，因为最前面没空格
//	{
//		ret += s[j];
//	}
//	return ret;
//}


//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
	return reverseWords(s);
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
	return "../../problems/reverse-words-in-a-string/tests.txt";
}

