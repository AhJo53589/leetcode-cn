
// 有两个数，A和B，六种操作分别是 + 12， - 12， + 7， - 7， + 5， - 5。
// A经过若干次操作，变成B 是输入任意2个数A和B，要给出变换过程，这其中的操作序列就是一个路径，也就是最少的操作次数 。
// 给出思路和代码

//////////////////////////////////////////////////////////////////////////
// 返回的 vector<int> 为六种操作的操作次数，[0] = +12，[1] = -12，[2] = +7，[3] = -7，[4] = +5，[5] = -5
// 如 {0,0,1,0,0,1} 表示，1 次 +7 和 1 次 -5
class Solution {
public:
	vector<int> minMove(int A, int B) {

    }

private:
	vector<int> op = { 12,-12,7,-7,5,-5 };
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int> nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minMove(nums[0], nums[1]);
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
