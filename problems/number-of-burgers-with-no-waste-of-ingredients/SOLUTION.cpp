


//////////////////////////////////////////////////////////////////////////
vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) 
{
    int ts = tomatoSlices;
    int cs = cheeseSlices;

    int a = (ts - cs * 2) / 2;
    int b = cs - a;
    if (a < 0 || b < 0 || (a * 4 + b * 2 != ts)) return {};
    return {a, b};
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int tomatoSlices, int cheeseSlices)
{
	return numOfBurgers(tomatoSlices,cheeseSlices);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
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
	return "../../problems/number-of-burgers-with-no-waste-of-ingredients/tests.txt";
}

