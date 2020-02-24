
//////////////////////////////////////////////////////////////////////////
class Solution3 {
public:
	void getLeft(vector<int>& heights, int i)
	{
		if (heights[i - 1] < heights[i])
		{
			left[i] = i;
			return;
		}
		int j = i;
		while (j != 0 && heights[j - 1] >= heights[i])
		{
			j = left[j - 1];
		}
		left[i] = j;
	}

	void getRight(int i, int h)
	{
		while (!que.empty() && que.top()[0] > h)
		{
			auto q = que.top();
			right[q[1]] = i - 1;
			ans = max(ans, (right[q[1]] - left[q[1]] + 1) * q[0]);
			que.pop();
		}
	}

    int largestRectangleArea(vector<int>& heights)
	{
		if (heights.empty()) return 0;
		if (heights.size() == 1) return heights.back();

		left = vector<int>(heights.size(), 0);
		right = vector<int>(heights.size(), 0);
		que.push({heights[0], 0});
		ans = 0;

		for (int i = 1; i < heights.size(); i++)
		{
			getLeft(heights, i);
			getRight(i, heights[i]);
			que.push({heights[i], i});
		}
		getRight(heights.size(), -1);

		return ans;
    }

private:
	vector<int> left;
	vector<int> right;
	priority_queue<vector<int>> que;
	int ans;
};

//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
	vector<int> getBoundary(vector<int>& heights, bool left)
	{
		vector<int> ans(heights.size(), 0);
		vector<int> st;
		for (int ii = 0; ii < heights.size(); ii++)
		{
			int i = left ? heights.size() - 1 - ii : ii;
			while (!st.empty() && heights[st.back()] > heights[i])
			{
				ans[st.back()] = left ? i + 1 : i - 1;
				st.pop_back();
			}
			st.push_back(i);
		}
		return ans;
	}

	int largestRectangleArea(vector<int>& heights)
	{
		heights.push_back(0);
		vector<int> left = getBoundary(heights, true);
		vector<int> right = getBoundary(heights, false);

		int ans = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			ans = max(ans, (right[i] - left[i] + 1) * heights[i]);
		}
		return ans;
	}
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	int largestRectangleArea(vector<int>& heights)
	{
		int ans = 0;
		vector<int> st;
		heights.insert(heights.begin(), 0);
		heights.push_back(0);
		for (int i = 0; i < heights.size(); i++)
		{
			while (!st.empty() && heights[st.back()] > heights[i])
			{
				int cur = st.back();
				st.pop_back();
				int left = st.back() + 1;
				int right = i - 1;
				ans = max(ans, (right - left + 1) * heights[cur]);
			}
			st.push_back(i);
		}
		return ans;
	}
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& heights)
{
	//int caseNo = 7;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	cout << convert<string>(heights) << endl;

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
