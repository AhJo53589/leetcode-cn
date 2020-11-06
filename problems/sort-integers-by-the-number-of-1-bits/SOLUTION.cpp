
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int wa = Solution::hammingWeight(a);
            int wb = Solution::hammingWeight(b);
            return (wa == wb) ? a < b : wa < wb;
        });
		return arr;
    }

    static int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n != 0) {
            n &= (n - 1);
            sum++;
        }
        return sum;
    }
};


//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    vector<int> sortByBits(vector<int>& arr) 
	{
		map<int, vector<int>> _map;
		for (auto& n : arr)
		{
			int c = hammingWeight(n);
			_map[c].push_back(n);
		}
		vector<int> ans;
		for (auto& m : _map)
		{
			sort(m.second.begin(), m.second.end());
			for (auto& n : m.second)
			{
				ans.push_back(n);
			}
		}
		return ans;
    }

	int hammingWeight(uint32_t n)
	{
		int sum = 0;
		while (n != 0)
		{
			n &= (n - 1);
			sum++;
		}
		return sum;
	}
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& arr)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.sortByBits(arr);
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
