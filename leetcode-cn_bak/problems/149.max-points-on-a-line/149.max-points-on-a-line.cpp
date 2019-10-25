// 149.max-points-on-a-line.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
bool cmp(vector<int>& a, vector<int>& b)
{
	if (a[0] != b[0]) return a[0] < b[0];
	else return a[1] < b[1];
}

bool isLine(vector<int>& a, vector<int>& b, vector<int>& c)
{
	long long tmp1 = ((long long)a[0] - b[0]) * ((long long)a[1] - c[1]);
	long long tmp2 = ((long long)a[0] - c[0]) * ((long long)a[1] - b[1]);
	if (tmp1 == tmp2) return true;
	return false;
}

int maxPoints(vector<vector<int>>& points) 
{
	if (points.size() < 3) return points.size();
	sort(points.begin(), points.end(), cmp);

	int ans = 2, count1 = 1, count2 = 1;
	for (int i = 0; i < points.size() - 2; i++) 
	{
		count1 = 1;
		while (i < points.size() - 3 && points[i + 1][0] == points[i][0] && points[i + 1][1] == points[i][1]) 
		{
			count1++;
			i++;
		}
		for (int j = i + 1; j < points.size() - 1; j++) 
		{
			count2 = 1;
			while (j < points.size() - 2 && points[j + 1][0] == points[j][0] && points[j + 1][1] == points[j][1]) 
			{
				count2++;
				j++;
			}
			int tmp = count1 + count2;
			for (int k = j + 1; k < points.size(); k++) {
				if (isLine(points[i], points[j], points[k])) tmp++;
			}
			ans = ans > tmp ? ans : tmp;
		}
	}
	return ans;
}


//////////////////////////////////////////////////////////////////////////
//bool isLine(vector<int>& a, vector<int>& b, vector<int>& c)
//{
//	long long tmp1 = ((long long)a[0] - b[0]) * ((long long)a[1] - c[1]);
//	long long tmp2 = ((long long)a[0] - c[0]) * ((long long)a[1] - b[1]);
//	if (tmp1 == tmp2) return true;
//	return false;
//}
//
//int maxPoints(vector<vector<int>>& points)
//{
//	if (points.size() < 3) return points.size();
//	int res = 0;
//	for (int i = 0; i < points.size(); i++)
//	{
//		int cnt1 = 1;
//		for (int j = i + 1; j < points.size(); j++)
//		{
//			if (points[i] == points[j])
//			{
//				cnt1++;
//				res = max(res, cnt1);
//				continue;
//			}
//			int cnt2 = 1;
//			for (int k = j + 1; k < points.size(); k++)
//			{
//				if (points[i] == points[k] || points[j] == points[k]) cnt2++;
//				else if (isLine(points[i], points[j], points[k])) cnt2++;
//			}
//			res = max(res, cnt1 + cnt2);
//		}
//	}
//	return res;
//}


int main()
{
	vector<vector<vector<int>>> TESTS;
	//vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back({ { 0,0 }, { 1,1 }, { 0,0 } });
	ANSWERS.push_back(3);

	TESTS.push_back({ { 1,1 }, { 1,1 }, { 2,3 } });
	ANSWERS.push_back(3);

	TESTS.push_back({ { 1,1 }, { 1,1 }, { 1,1 } });
	ANSWERS.push_back(3);

	TESTS.push_back({ { 1,1 }, { 2,2 }, { 3,3 } });
	ANSWERS.push_back(3);

	TESTS.push_back({ {1,1},{3,2},{5,3},{4,1},{2,3},{1,4} });
	ANSWERS.push_back(4);

	TESTS.push_back(StringToVectorVectorInt("[[40,-23],[9,138],[429,115],[50,-17],[-3,80],[-10,33],[5,-21],[-3,80],[-6,-65],[-18,26],[-6,-65],[5,72],[0,77],[-9,86],[10,-2],[-8,85],[21,130],[18,-6],[-18,26],[-1,-15],[10,-2],[8,69],[-4,63],[0,3],[-4,40],[-7,84],[-8,7],[30,154],[16,-5],[6,90],[18,-6],[5,77],[-4,77],[7,-13],[-1,-45],[16,-5],[-9,86],[-16,11],[-7,84],[1,76],[3,77],[10,67],[1,-37],[-10,-81],[4,-11],[-20,13],[-10,77],[6,-17],[-27,2],[-10,-81],[10,-1],[-9,1],[-8,43],[2,2],[2,-21],[3,82],[8,-1],[10,-1],[-9,1],[-12,42],[16,-5],[-5,-61],[20,-7],[9,-35],[10,6],[12,106],[5,-21],[-5,82],[6,71],[-15,34],[-10,87],[-14,-12],[12,106],[-5,82],[-46,-45],[-4,63],[16,-5],[4,1],[-3,-53],[0,-17],[9,98],[-18,26],[-9,86],[2,77],[-2,-49],[1,76],[-3,-38],[-8,7],[-17,-37],[5,72],[10,-37],[-4,-57],[-3,-53],[3,74],[-3,-11],[-8,7],[1,88],[-12,42],[1,-37],[2,77],[-6,77],[5,72],[-4,-57],[-18,-33],[-12,42],[-9,86],[2,77],[-8,77],[-3,77],[9,-42],[16,41],[-29,-37],[0,-41],[-21,18],[-27,-34],[0,77],[3,74],[-7,-69],[-21,18],[27,146],[-20,13],[21,130],[-6,-65],[14,-4],[0,3],[9,-5],[6,-29],[-2,73],[-1,-15],[1,76],[-4,77],[6,-29]]"));
	ANSWERS.push_back(25);

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = maxPoints(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}