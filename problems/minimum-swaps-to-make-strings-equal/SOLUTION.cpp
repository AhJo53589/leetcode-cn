


//////////////////////////////////////////////////////////////////////////
    int minimumSwap(string s1, string s2) 
    {
        int cntx = 0;
        int cntxy = 0;
        int cntyx = 0;
        for (auto i = 0; i != s1.size(); i++) 
        {
            if (s1[i] == 'x') cntx++;
            if (s2[i] == 'x') cntx++;
            
            if (s1[i] == 'x' && s1[i] != s2[i]) cntxy++;
            if (s1[i] == 'y' && s1[i] != s2[i]) cntyx++;
        }
        if (cntx % 2) return -1;
        return cntxy / 2 + cntyx / 2 + (cntxy % 2) * 2;       
    }

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s1, string s2)
{
	return minimumSwap(s1,s2);
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
	return "../../problems/minimum-swaps-to-make-strings-equal/tests.txt";
}

