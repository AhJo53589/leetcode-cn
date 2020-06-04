
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> nums;
        int m = matrix.size();
        if (m == 0) return nums;
        int n = matrix[0].size();
        if (n == 0) return nums;

        // 0 == ¡ú, 1 == ¡ý, 2 == ¡û, 3 == ¡ü
        int iDirection = 0;
        int iSize = m * n;

        int x = 0;
        int y = -1;
        while (nums.size() < iSize)
        {
            int iStepX = (iDirection % 2 == 0) ? 0 : (iDirection / 2 == 0) ? 1 : -1;
            int iStepY = (iDirection % 2 == 1) ? 0 : (iDirection / 2 == 0) ? 1 : -1;
            int iCount = 1;

            int iMaxCount = (iDirection % 2 == 0) ? n : m;
            while (iCount <= iMaxCount)
            {
                x = x + iStepX;
                y = y + iStepY;
                nums.push_back(matrix[x][y]);
                iCount++;
            }
            if (iDirection % 2 == 0) m--;
            else n--;

            iDirection = (iDirection + 1) % 4;
        }

        return nums;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& matrix)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.spiralOrder(matrix);
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
