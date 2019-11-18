


//////////////////////////////////////////////////////////////////////////
char nextGreatestLetter(vector<char>& letters, char target)
{
	auto getValue = [](char c) { return c - 'a'; };
	int low = 0;
	int high = letters.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (getValue(letters[mid]) < getValue(target) + 1) low = mid + 1;
		else high = mid;
	}
	return (low < letters.size()) ? letters[low] : letters[0];
}

//////////////////////////////////////////////////////////////////////////
char _solution_run(vector<char>& letters, char target)
{
	return nextGreatestLetter(letters,target);
}

//#define USE_SOLUTION_CUSTOM
//char _solution_custom(TestCases &tc)
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
	return "../../problems/find-smallest-letter-greater-than-target/tests.txt";
}

