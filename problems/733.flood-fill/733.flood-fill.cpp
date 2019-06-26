// 733.flood-fill.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>

#include "..\Common\Common.h"
using namespace std;

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

int main()
{
	int sr = 1;
	int sc = 1;
	int newColor = 2;
	string strInit = "[[1,1,1],[1,1,0],[1,0,1]]";

	vector<vector<int>> m = StringToVectorVectorInt(strInit);
	cout << VectorVectorIntToString(m) << endl;

	floodFill(m, sr, sc, newColor);
	cout << VectorVectorIntToString(m) << endl;

}
