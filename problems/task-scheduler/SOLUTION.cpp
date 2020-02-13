
//////////////////////////////////////////////////////////////////////////
//int leastInterval(vector<char>& tasks, int n) {
//	int nums[26] = { 0 };
//	int len = tasks.size();
//	int max = 0;
//	for (int i = 0; i < len; i++) {
//		nums[tasks[i] - 'A']++;
//	}
//	for (int i = 0; i < 26; i++) {
//		if (max < nums[i])
//			max = nums[i];
//	}
//	int count = 0;
//	for (int i = 0; i < 26; i++) {
//		if (max == nums[i])
//			count++;
//	}
//	int res = (max - 1)*(n + 1) + count;
//	return res < len ? len : res;
//}


//////////////////////////////////////////////////////////////////////////
int leastInterval(vector<char>& tasks, int n)
{
	array<int, 26> task_count = {};
	vector<int> task_order;

	for (auto &c : tasks)
	{
		task_count[c - 'A']++;
	}
	for (int i = 0; i < task_count.size(); i++)
	{
		if (task_count[i] == 0) continue;
		task_order.push_back(task_count[i]);
	}
	sort(task_order.rbegin(), task_order.rend());

	int res = 0;
	while (!task_order.empty())
	{
		int count = 0;
		for (int i = 0; i < task_order.size(); i++)
		{
			task_order[i]--;
			count++;
			if (count == n + 1) break;
		}
		sort(task_order.rbegin(), task_order.rend());
		while (!task_order.empty() && task_order.back() == 0) task_order.pop_back();

		res += task_order.empty() ? count : n + 1;
	}

	return res;
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<char>& tasks, int n)
{
	return leastInterval(tasks,n);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

