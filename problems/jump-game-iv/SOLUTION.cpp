
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minJumps(vector<int>& arr) 
	{
		unordered_map<int, vector<int>> same;
		int pre_i = 0;
		int pre_val = arr[0];
		same[pre_val].push_back(pre_i);
		for (size_t i = 1; i < arr.size(); i++)
		{
			int val = arr[i];
			if (val == pre_val && i != arr.size() - 1)
			{
				pre_i = i;
				continue;
			}
			same[pre_val].push_back(pre_i);
			pre_i = i;
			pre_val = val;
			same[pre_val].push_back(pre_i);
		}

		vector<int> vi(arr.size(), 0);
		queue<int> que;
		que.push(0);
		vi[0] = 1;

		while (!que.empty())
		{
			auto q = que.front();
			que.pop();
			if (q == arr.size() - 1) break;

			if (q != 0 && vi[q - 1] == 0)
			{
				que.push(q - 1);
				vi[q - 1] = vi[q] + 1;
			}
			if (q != arr.size() - 1 && vi[q + 1] == 0)
			{
				que.push(q + 1);
				vi[q + 1] = vi[q] + 1;
			}
			auto s = same[arr[q]];
			for (size_t i = s.size() - 1; i < s.size(); i--)
			{
				if (vi[s[i]] != 0) continue;
				que.push(s[i]);
				vi[s[i]] = vi[q] + 1;
			}
		}

		return vi[arr.size() - 1] - 1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr)
{
	//int caseNo = 5;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minJumps(arr);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
