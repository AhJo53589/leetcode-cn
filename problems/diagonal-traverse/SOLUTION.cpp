
//vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
//{
//	if (matrix.empty()) return vector<int>();
//	int rows = matrix.size();
//	int cols = matrix[0].size();
//	vector<int> output;
//	int i = 0, j = 0;
//	output.push_back(matrix[i][j]);
//	while (i != rows - 1 || j != cols - 1)
//	{
//		if (j + 1 < cols) j++;
//		else if (i + 1 < rows) i++;
//		output.push_back(matrix[i][j]);
//
//		while (i + 1 < rows && j - 1 >= 0)
//		{
//			i++;
//			j--;
//			output.push_back(matrix[i][j]);
//		}
//
//		if (i + 1 < rows) i++;
//		else if (j + 1 < cols) j++;
//		else return output;
//		output.push_back(matrix[i][j]);
//
//		while (i - 1 >= 0 && j + 1 < cols)
//		{
//			i--;
//			j++;
//			output.push_back(matrix[i][j]);
//		}
//	}
//	return output;
//}

//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) return {};
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        while (i < m + n - 1)
        {
            // 1,3,5...
            int x1 = i < m ? i : m - 1;
            int y1 = i - x1;
            while (x1 >= 0 && y1 < n)
            {
                ans.push_back(matrix[x1][y1]);
                x1--;
                y1++;
            }
            i++;
            // 2,4,6...
            int y2 = i < n ? i : n - 1;
            int x2 = i - y2;
            while (y2 >= 0 && x2 < m)
            {
                ans.push_back(matrix[x2][y2]);
                x2++;
                y2--;
            }
            i++;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        bool flag = true;
        for (int i = 0; i < m + n - 1; i++)
        {
            int pm = flag ? m : n;
            int pn = flag ? n : m;

            int px = (i < pm) ? i : pm - 1;
            int py = i - px;

            while (px >= 0 && py < pn)
            {
                ans.push_back(flag ? matrix[px][py] : matrix[py][px]);
                px--;
                py++;
            }

            flag = !flag;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& matrix)
{
    Solution sln;
	return sln.findDiagonalOrder(matrix);
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

