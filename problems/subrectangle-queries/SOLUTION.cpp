
//////////////////////////////////////////////////////////////////////////
class SubrectangleQueries {
public:
	SubrectangleQueries(vector<vector<int>>& rectangle) : rect(rectangle) {

	}

	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        if (row1 < 0 || row1 >= rect.size()) return;
        if (col1 < 0 || col1 >= rect[0].size()) return;
        if (row2 < 0 || row2 >= rect.size()) return;
        if (col2 < 0 || col2 >= rect[0].size()) return;
		for (int i = row1; i <= row2; i++) {
			for (int j = col1; j <= col2; j++) {
				rect[i][j] = newValue;
			}
		}
	}

	int getValue(int row, int col) {
		if (row < 0 || row >= rect.size()) return -1; 
		if (col < 0 || col >= rect[0].size()) return -1;
		return rect[row][col];
	}

private:
	vector<vector<int>> rect;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */

 //////////////////////////////////////////////////////////////////////////
 //int _solution_run(int)
 //{
 //}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<string> sp = tc.get<vector<string>>();
	vector<string> ans;

	SubrectangleQueries* obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "SubrectangleQueries")
		{
			TestCases stc(sp[i]);
			vector<vector<int>> rectangle = stc.get<vector<vector<int>>>();
			obj = new SubrectangleQueries(rectangle);
			ans.push_back("null");
		}
		else if (sf[i] == "updateSubrectangle")
		{
			TestCases stc(sp[i]);
			int row1 = stc.get<int>();
			int col1 = stc.get<int>();
			int row2 = stc.get<int>();
			int col2 = stc.get<int>();
			int newValue = stc.get<int>();
			obj->updateSubrectangle(row1, col1, row2, col2, newValue);
			ans.push_back("null");
		}
		else if (sf[i] == "getValue")
		{
			TestCases stc(sp[i]);
			int row = stc.get<int>();
			int col = stc.get<int>();
			int r = obj->getValue(row, col);
			ans.push_back(convert<string>(r));
		}
	}
	delete obj;

	return convert<string>(ans);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
