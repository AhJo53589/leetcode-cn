


//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	int calculate(string s)
	{
		stack<int> nums;
		stack<char> op;

		s.append("+");
		int num = 0;
		for (auto c : s)
		{
			if (isspace(c)) continue;
			if (isdigit(c))
			{
				num = num * 10 + (c - '0');
				continue;
			}

			if (!op.empty() && (op.top() == '*' || op.top() == '/'))
			{
				num = (op.top() == '*') ? nums.top() * num : nums.top() / num;
				nums.pop();
				op.pop();
			}

			if (op.empty() || c == '*' || c == '/')
			{
				nums.push(num);
				op.push(c);
			}
			else
			{
				nums.top() += (op.top() == '+') ? num : -num;
				op.top() = c;
			}

			num = 0;
		}

		return nums.top();
	}
};


//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	Solution sln;
	return sln.calculate(s);
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

