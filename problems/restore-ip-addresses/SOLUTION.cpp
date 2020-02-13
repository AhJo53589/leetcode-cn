
//////////////////////////////////////////////////////////////////////////
vector<string> restoreIpAddresses(string& s, int remaining, int iBegin)
{
	int len = s.length();
	vector<string> ret;
	for (int i = iBegin; i < iBegin + 3; i++)
	{
		if (remaining == 0 && i != len - 1) continue;	// ��������һλ������ƥ�䵽�ַ�����β
		if ((len - i - 1) > (remaining * 3)) continue;	// �����ǵڼ�λ��ȷ�����ַ����еĿ���λ��
		if ((len - i - 1) < (remaining * 1)) continue;

		string sub = s.substr(iBegin, i - iBegin + 1);
		int ip = stoi(sub);
		if (ip < 0 || ip > 255) continue;	// ������ ip ��ʽ
		if (to_string(ip) != sub) break;	// ���� stoi(��01��) => 1 ���������

		if (remaining == 0)
		{
			// ���һλ�õ��Ϸ����֣����ش�
			ret.push_back(sub);
		}
		else
		{
			// ���յ�ǰ״̬����һ��Ѱ����һλ����
			vector<string> vs = restoreIpAddresses(s, remaining - 1, i + 1);
			for (auto& v : vs)
			{
				// ֻ�к������ֺϷ���vs ��Ϊ�գ��˴��� sub ���ܼ����
				// ��˹����˲����ϵĴ�
				ret.push_back(sub + "." + v);
			}
		}
	}
	return ret;
}

vector<string> restoreIpAddresses(string s)
{
	return restoreIpAddresses(s, 3, 0);
}

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(string s)
{
	return restoreIpAddresses(s);
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

