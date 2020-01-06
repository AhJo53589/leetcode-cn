
//////////////////////////////////////////////////////////////////////////
bool valid(string& s, vector<int>& use) // 根据use标志位，验证括号是否合法
{
	int st = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!use[i]) continue;
		st += (s[i] == '(');
		st -= (s[i] == ')');
		if (st < 0) return false;
	}
	return (st == 0);
}

vector<string> removeInvalidParentheses(string s)
{
	set<string> ans;
	vector<int> use(s.size(), 1);

	for (int k = 0; k < s.size(); k++)
	{
		for (int i = 0; i < s.size(); i++)  // 第k次寻找，初始化标志位，使前k个字符无效
		{
			use[i] = (i >= k);
		}

		do
		{
			if (valid(s, use))
			{
				string a;   // 拷贝符合要求的字符串
				for (size_t i = 0; i < s.size(); i++)
				{
					if (!use[i]) continue;
					a += s[i];
				}
				ans.insert(a);

				k = s.size();   // 在下一次循环时结束k层的循环，本次循环内的do-while循环继续执行
			}
		} while (next_permutation(use.begin(), use.end())); // 得到标志位的下一个排列
	}
	if (ans.empty()) return { "" };
	return vector<string>(ans.begin(), ans.end());
}

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(string s)
{
	return removeInvalidParentheses(s);
}

//#define USE_SOLUTION_CUSTOM
//vector<string> _solution_custom(TestCases &tc)
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
	return "../../problems/_test_0/tests.txt";
}

