


//////////////////////////////////////////////////////////////////////////
void trimR(string& input)
{
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

vector<string> printVertically(string s)
{
	stringstream ss(s);
	vector<string> aa;
	string temp;
	while (ss >> temp)
	{
		aa.push_back(temp);
	}
	vector<string> ans;

	bool flag = true;
	size_t i = 0;
	while (flag)
	{
		flag = false;
		temp = "";
		for (auto& a : aa)
		{
			if (i >= a.size())
			{
				temp += " ";
			}
			else
			{
				flag = true;
				temp += a[i];
			}
		}
		trimR(temp);
		ans.push_back(temp);
		i++;
	}
	ans.pop_back();
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(string s)
{
	return printVertically(s);
}

//#define USE_SOLUTION_CUSTOM
//vector<string> _solution_custom(TestCases &tc)
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
	return "../../problems/print-words-vertically/tests.txt";
}

