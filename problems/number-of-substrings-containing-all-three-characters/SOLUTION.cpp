
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	bool getAll(vector<int>& vi)
	{
		//return all_of(vi.begin(), vi.end(), [](const int& a) { return a != 0; });
		for (auto n : vi)
		{
			if (n == 0) return false;
		}
		return true;
	}

	int numberOfSubstrings(string s) 
	{
		int ans = 0;
		int left = 0;
		vector<int> vi(3, 0);
		queue<int> que;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != 'a' && s[i] != 'b' && s[i] != 'c') continue;

			//cout << endl << "[" << i << "]\t" << s[i] << endl;
			vi[s[i] - 'a']++;
			que.push(i);

			while (getAll(vi))
			{
				int a = que.front() - left + 1;
				int b = s.size() - i;
				ans += a * b;
				//cout << "a = " << a << ", b = " << b << ", a * b = " << a * b << endl;

				vi[s[que.front()] - 'a']--;
				que.pop();
				left = que.front();
				//cout << "left -> " << left << endl;
			}
		}
		return ans;
	}
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	cout << s << endl;
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numberOfSubstrings(s);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
