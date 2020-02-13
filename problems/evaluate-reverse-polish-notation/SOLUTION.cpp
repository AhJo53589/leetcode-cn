


//////////////////////////////////////////////////////////////////////////
int evalRPN(vector<string>& tokens)
{
	if (tokens.empty()) return 0;
	stack<int> s;
	for (auto str : tokens)
	{
		if (str == "+" || str == "-" || str == "*" || str == "/")
		{
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			if (str == "+") s.push(b + a);
			if (str == "-") s.push(b - a);
			if (str == "*") s.push(b * a);
			if (str == "/") s.push(b / a);
		}
		else
		{
			s.push(stoi(str));
		}
	}
	return s.top();
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<string>& tokens)
{
	return evalRPN(tokens);
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

