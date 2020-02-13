
//////////////////////////////////////////////////////////////////////////
bool valid(string& s, vector<int>& use) // ����use��־λ����֤�����Ƿ�Ϸ�
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
		for (int i = 0; i < s.size(); i++)  // ��k��Ѱ�ң���ʼ����־λ��ʹǰk���ַ���Ч
		{
			use[i] = (i >= k);
		}

		do
		{
			if (valid(s, use))
			{
				string a;   // ��������Ҫ����ַ���
				for (size_t i = 0; i < s.size(); i++)
				{
					if (!use[i]) continue;
					a += s[i];
				}
				ans.insert(a);

				k = s.size();   // ����һ��ѭ��ʱ����k���ѭ��������ѭ���ڵ�do-whileѭ������ִ��
			}
		} while (next_permutation(use.begin(), use.end())); // �õ���־λ����һ������
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
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

