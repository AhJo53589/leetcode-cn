
//////////////////////////////////////////////////////////////////////////
// 假设候选队列为 A，已经站好队的队列为 B.
//
// 从 A 里挑身高最高的人 x 出来，插入到 B.因为 B 中每个人的身高都比 x 要高，
// 因此 x 插入的位置，就是看 x 前面应该有多少人就行了。
// 比如 x 前面有 5 个人，那 x 就插入到队列 B 的第 5 个位置。
class Solution2 {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		// 先排序
		// [7,0], [7,1], [6,1], [5,0], [5,2], [4,4]

		// 再一个一个插入。
		// [7,0]
		// [7,0], [7,1]
		// [7,0], [6,1], [7,1]
		// [5,0], [7,0], [6,1], [7,1]
		// [5,0], [7,0], [5,2], [6,1], [7,1]
		// [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]
		sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
			if (a[0] > b[0]) return true;
			if (a[0] == b[0] && a[1] < b[1]) return true;
			return false;
			});

		vector<vector<int>> res;
		for (auto& e : people) {
			res.insert(res.begin() + e[1], e);
		}
		return res;
	}
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end());
		vector<int> cnt(people.size(), 0);
		for (int i = 0; i < people.size(); i++)
		{
			cnt[i] = people[i][1];
		}

		vector<vector<int>> ans;
		size_t sz = 0;
		while (sz++ <= people.size())
		{
			int lastNum = -1;
			for (int i = 0; i < people.size(); i++)
			{
				if (lastNum != -1 && lastNum != people[i][0]) break;
				if (cnt[i] == -1) continue;
				cnt[i]--;
				if (cnt[i] != -1) continue;
				ans.push_back(people[i]);
				lastNum = people[i][0];
			}
		}

		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& people)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.reconstructQueue(people);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
