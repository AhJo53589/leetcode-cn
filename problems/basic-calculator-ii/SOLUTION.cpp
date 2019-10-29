


//////////////////////////////////////////////////////////////////////////
int calculate(string s)
{
	stack<int> nums;
	stack<char> op;
	int val = 0;

	s.append("+");
	for (auto c : s)
	{
		if (isspace(c)) continue;
		if (isdigit(c))
		{
			val = val * 10 + (c - '0');
			continue;
		}

		if (!nums.empty() && !op.empty() && (op.top() == '*' || op.top() == '/'))
		{
			val = (op.top() == '*') ? nums.top() * val : nums.top() / val;
			nums.pop();
			op.pop();
		}
		if (nums.empty() || op.empty() || c == '*' || c == '/')
		{
			nums.push(val);
			op.push(c);
		}
		else
		{
			nums.top() = (op.top() == '+') ? nums.top() + val : nums.top() - val;
			op.top() = c;
		}
		val = 0;
	}

	return nums.top();
}


//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	return calculate(s);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
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
	return "../../problems/basic-calculator-ii/tests.txt";
}

