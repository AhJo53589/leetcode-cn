
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int totalNQueens(int n) 
    {
        dfs(n, 0, 0, 0, 0);

        return ans;
    }

    void dfs(int n, int row, int col, int ld, int rd) 
    {
        //cout << "col:\t\t" << bitset<8>(col) << endl;
        //cout << "ld:\t\t" << bitset<8>(ld) << endl;
        //cout << "rd:\t\t" << bitset<8>(rd) << endl;
        if (row >= n)
        { 
            ans++;
            return;
        }

        // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历
        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0) 
        {
            int pick = bits & -bits; // 注: x & -x
            //cout << "bits:\t\t\t" << bitset<8>(bits) << endl;
            //cout << "-bits:\t\t\t" << bitset<8>(-bits) << endl;
            //cout << "pick = bits & -bits:\t" << bitset<8>(pick) << endl;
            //cout << "col | pick:\t\t" << bitset<8>(col | pick) << endl;
            //cout << "(ld | pick) << 1:\t" << bitset<8>((ld | pick) << 1) << endl;
            //cout << "(rd | pick) >> 1:\t" << bitset<8>((rd | pick) >> 1) << endl;
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= bits - 1; // 注: x & (x - 1)
            //cout << "bits:\t" << bitset<8>(bits) << endl;
        }
    }

private:
    int ans = 0;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.totalNQueens(n);
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
