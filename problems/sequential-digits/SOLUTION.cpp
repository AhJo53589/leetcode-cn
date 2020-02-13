


//////////////////////////////////////////////////////////////////////////
vector<int> sequentialDigits(int low, int high)
{
    vector<int> ans;
    string sn = to_string(low);
    int d = sn.size();
    int b = 1;

    while (true)
    {
        string temp;
        for (int i = 0; i < d; i++)
        {
            temp += to_string(b + i);
        }
        int ti = stoi(temp);

        if (ti > high) break;
        if (ti >= low) 
        {
            ans.push_back(ti);
        }

        b++;
        if (b + d > 10)
        {
            b = 1;
            d++;
        }
        if (b + d > 10) break;
    }

    return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int low, int high)
{
	return sequentialDigits(low,high);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

