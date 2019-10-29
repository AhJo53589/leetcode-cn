
//////////////////////////////////////////////////////////////////////////
//vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//	vector<pair<int, int>> h;
//	vector<vector<int>> res;
//	multiset<int> m;
//	int pre = 0, cur = 0;
//	for (auto &a : buildings) {
//		h.push_back({ a[0], -a[2] });
//		h.push_back({ a[1], a[2] });
//	}
//	sort(h.begin(), h.end());
//	m.insert(0);
//	for (auto &a : h) {
//		if (a.second < 0) m.insert(-a.second);
//		else m.erase(m.find(a.second));
//		cur = *m.rbegin();
//		if (cur != pre) {
//			res.push_back({ a.first, cur });
//			pre = cur;
//		}
//	}
//
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
//vector<vector<int>> ans;
//map<int, int> heights = { {INT_MIN, 0} };//左结点记录至下一个结点区间值。
//
//void update(int i, int j, int h) {
//
//	//安插等效关键结点。即将一个区间插入一个点，变成两个值相等子区间，以方便更新结点数据。
//	heights[i] = (--heights.upper_bound(i))->second;
//	heights[j] = (--heights.upper_bound(j))->second;
//
//	auto pI = heights.find(i), pJ = heights.find(j), pBefor = pI;
//	--pBefor;
//	//更新结点数据,同时处理去重
//	for (auto p = pI; p != pJ;) {
//		int newVal = max(p->second, h);
//		if (newVal == pBefor->second) {
//			p = heights.erase(p);
//		}
//		else {
//			p->second = newVal;
//			++p, ++pBefor;
//		}
//	}
//	if (pJ->second == pBefor->second) heights.erase(pJ);
//}
//
//vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//	for (auto building : buildings) {
//		update(building[0], building[1], building[2]);
//	}
//	for (auto p = ++heights.begin(); p != heights.end(); ++p) {
//		ans.push_back({ p->first, p->second });
//	}
//	return ans;
//}


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
{
	const size_t Li = 0;
	const size_t Ri = 1;
	const size_t Hi = 2;
	const size_t x = 0;
	const size_t y = 1;

	vector<vector<int>> ans;
	vector<vector<int>> vec;

	auto f_lower_bound = [&](const vector<int> &b)
	{
		int start = 0;
		int last = vec.size();
		while (start < last)
		{
			int mid = start + (last - start) / 2;
			if (vec[mid][Hi] < b[Hi])
			{
				start = mid + 1;
			}
			else
			{
				last = mid;
			}
		}
		return last;
	};

	auto f_insert = [&](const vector<int> &b)
	{
		if (vec.empty() || b[Hi] > vec.back()[Hi])
		{
			vec.push_back(b);
			return;
		}

		auto it = vec.begin() + f_lower_bound(b);

		if (b[Ri] <= (*it)[Ri]) return;
		if (b[Hi] == (*it)[Hi])
		{
			(*it) = b;
		}
		else
		{
			vec.insert(it, b);
		}
	};

	auto f_pop_back = [&]()
	{
		int _x = vec.back()[Ri];
		while (!vec.empty() && vec.back()[Ri] <= _x)
		{
			vec.pop_back();
		}
		int _y = vec.empty() ? 0 : vec.back()[Hi];
		ans.push_back({ _x, _y });
	};

	for (auto &b : buildings)
	{
		while (!vec.empty() && b[Li] > vec.back()[Ri])
		{
			f_pop_back();
		}

		if (vec.empty())
		{
			ans.push_back({ b[Li], b[Hi] });
		}
		else if (b[Hi] > vec.back()[Hi])
		{
			if (b[Li] == ans.back()[x])
			{
				ans.back()[y] = b[Hi];
			}
			else
			{
				ans.push_back({ b[Li], b[Hi] });
			}
		}

		f_insert(b);
	}

	while (!vec.empty())
	{
		f_pop_back();
	}

	return ans;
}


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& buildings)
{
	return getSkyline(buildings);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
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
	return "../../problems/the-skyline-problem/tests.txt";
}

