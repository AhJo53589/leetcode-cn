


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
	int sr_Size = image.size();
	if (sr_Size == 0) return image;
	int sc_Size = image[0].size();
	if (sc_Size == 0) return image;

	int oldColor = image[sr][sc];
	if (oldColor == newColor) return image;

	image[sr][sc] = newColor;
	if (sr + 1 < sr_Size && image[sr + 1][sc] == oldColor) floodFill(image, sr + 1, sc, newColor);
	if (sr - 1 >= 0 && image[sr - 1][sc] == oldColor) floodFill(image, sr - 1, sc, newColor);
	if (sc + 1 < sc_Size && image[sr][sc + 1] == oldColor) floodFill(image, sr, sc + 1, newColor);
	if (sc - 1 >= 0 && image[sr][sc - 1] == oldColor) floodFill(image, sr, sc - 1, newColor);

	return image;
}


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<vector<int>>& image, int sr, int sc, int newColor)
{
	return floodFill(image,sr,sc,newColor);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
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
	return "../../problems/flood-fill/tests.txt";
}

