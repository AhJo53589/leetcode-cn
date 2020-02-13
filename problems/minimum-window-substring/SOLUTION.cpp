
//////////////////////////////////////////////////////////////////////////
//string minWindow(string s, string t) {
//	int count[256] = { 0 };
//
//	for (auto c : t) {
//		++count[c];
//	}
//
//	int l = 0;
//	int r = 0;
//	int len = 0; // 当前窗口匹配 t 中字符的数目
//	int minLen = s.size();
//	string res;
//
//	for (; r < s.size(); r++) {
//		if (count[s[r]] > 0) {
//			len++;
//		}
//		count[s[r]]--;
//
//		while (len == t.size()) {
//			if (r - l + 1 <= minLen) {
//				minLen = r - l + 1;
//				res = s.substr(l, r - l + 1);
//			}
//			count[s[l]]++; // 移动窗口的左指针
//			if (count[s[l]] > 0) {
//				len--;
//			}
//			l++;
//		}
//	}
//
//	return res;
//}


//////////////////////////////////////////////////////////////////////////
string minWindow(string s, string t)
{
	if (s.size() < t.size()) return "";
	if (t.size() == 1 && s.find(t[0]) != string::npos) return t;

	queue<size_t> _window;
	unordered_map<char, int> _map;
	string ans;
	size_t ans_len = UINT_MAX;
	bool bMapFlag = false;

	for (auto c : t)
	{
		_map[c]--;
	}

	auto f_check_map = [&_map, &bMapFlag]()
	{
		if (bMapFlag) return true;
		for (auto m : _map)
		{
			if (m.second < 0) return false;
		}
		bMapFlag = true;
		return true;
	};

	for (size_t i = 0; i < s.size(); i++)
	{
		if (_map.count(s[i]) == 0) continue;
		_window.push(i);
		_map[s[i]]++;
		while (_map[s[_window.front()]] > 0)
		{
			auto j = _window.front();
			_window.pop();
			_map[s[j]]--;
		}
		if (f_check_map())
		{
			auto k = (_window.size() > 1) ? _window.back() - _window.front() + 1 : UINT_MAX;
			if (k < ans_len)
			{
				ans = s.substr(_window.front(), k);
				ans_len = k;
			}
		}
	}
	return ans;
}


//////////////////////////////////////////////////////////////////////////
string _solution_run(string s, string t)
{
	return minWindow(s,t);
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

