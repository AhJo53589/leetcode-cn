
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		int ans = 0;
		vector<int> left(heights.size(), 0);
		vector<int> right(heights.size(), 0);
		priority_queue<vector<int>> que;
		que.push({heights[0], 0});

		for (int i = 1; i < heights.size(); i++)
		{
			if (heights[i - 1] < heights[i])
			{
				left[i] = i;
			}
			else
			{
				int j = i;
				while (j != 0 && heights[j - 1] >= heights[j])
				{
					j = left[j - 1];
				}
				left[i] = j;
			}

			while (!que.empty())
			{
				auto q = que.top();
				if (q[0] <= heights[i]) break;
				right[q[1]] = i - 1;
				ans = max(ans, (right[q[1]] - left[q[1]] + 1) * q[0]);
				que.pop();
			}
			que.push({heights[i], i});

			if (i != heights.size() - 1) continue;
			while (!que.empty())
			{
				auto q = que.top();
				right[q[1]] = i;
				ans = max(ans, (right[q[1]] - left[q[1]] + 1) * q[0]);
				que.pop();
			}
		}

		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& heights)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.largestRectangleArea(heights);
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
