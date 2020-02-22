
//////////////////////////////////////////////////////////////////////////
// �����ѡ����Ϊ A���Ѿ�վ�öӵĶ���Ϊ B.
//
// �� A ���������ߵ��� x ���������뵽 B.��Ϊ B ��ÿ���˵���߶��� x Ҫ�ߣ�
// ��� x �����λ�ã����ǿ� x ǰ��Ӧ���ж����˾����ˡ�
// ���� x ǰ���� 5 ���ˣ��� x �Ͳ��뵽���� B �ĵ� 5 ��λ�á�
class Solution2 {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		// ������
		// [7,0], [7,1], [6,1], [5,0], [5,2], [4,4]

		// ��һ��һ�����롣
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
