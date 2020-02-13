

//////////////////////////////////////////////////////////////////////////
//bool circularArrayLoop(vector<int>& nums) {
//	vector<int> visit(nums.size(), 0);
//	int color = 1;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		int j = i;
//		while (visit[j] == 0 && nums[i] * nums[j] > 0)
//		{
//			visit[j] = color;
//			j = j + nums[j] + nums.size();
//			j = j % nums.size();
//		}
//		if (visit[j] == color && (j + nums[j] + nums.size()) % nums.size() != j)
//			return true;
//		color++;
//	}
//	return false;
//}


//////////////////////////////////////////////////////////////////////////
bool circularArrayLoop(vector<int>& nums)
{
    for (size_t i = 0; i < nums.size(); i++)
    {
        bool flag = nums[i] < 0;
        size_t cur = i;
        unordered_set<size_t> us;
        while (true)
        {
            size_t next = (cur + nums[cur] + nums.size()) % nums.size();
			if (cur == next) break;
            if (flag != (nums[next] < 0)) break;
			if (us.count(next) != 0) return true;
            us.insert(cur);
            cur = next;
        }
    }
    return false;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums)
{
	return circularArrayLoop(nums);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

