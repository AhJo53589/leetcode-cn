
vector<string> restoreIpAddresses(string &s, int id, int iBegin)
{
	int len = s.length();
	vector<string> ret;
	for (int i = iBegin; i < iBegin + 3; i++)
	{
		if (id == 0 && i != len - 1) continue;
		if ((len - i - 1) > (id * 3)) continue;
		if ((len - i - 1) < (id * 1)) continue;

		string sub = s.substr(iBegin, i - iBegin + 1);
		int ip = stoi(sub);
		if (ip < 0 || ip > 255) continue;
		if (to_string(ip) != sub) break;

		if (id == 0)
		{
			ret.push_back(sub);
		}
		vector<string> vs = restoreIpAddresses(s, id - 1, i + 1);
		for (auto &v : vs)
		{
			ret.push_back(sub + "." + v);
		}
	}
	return ret;
}

//////////////////////////////////////////////////////////////////////////
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
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/restore-ip-addresses/tests.txt";
}

