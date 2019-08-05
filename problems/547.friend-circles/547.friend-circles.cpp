// 547.friend-circles.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
vector<int> Tree;
int findRoot(int x) {
	if (Tree[x] == -1) return x;
	int tmp = findRoot(Tree[x]);
	Tree[x] = tmp;
	return tmp;
}

int findCircleNum(vector<vector<int>>& M) {
	Tree.resize(M.size(), -1);
	for (int i = 0; i < M.size(); i++) {
		for (int j = i + 1; j < M.size(); j++) {
			if (M[i][j] == 1) {
				int a = findRoot(i);
				int b = findRoot(j);
				if (a != b) Tree[a] = b;
			}
		}
	}
	int ans = 0;
	for (auto i : Tree) {
		if (i == -1) ans++;
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
//int findCircleNum(vector<vector<int>>& M)
//{
//	int iNum = 0;
//	unordered_set<int> visited;
//	queue<int> que;
//	for (int i = 0; i < M.size(); i++)
//	{
//		if (visited.count(i)) continue;
//		visited.insert(i);
//		iNum++;
//		for (int j = 0; j < M.size(); j++)
//		{
//			if (visited.count(j)) continue;
//			if (M[i][j] == 0) continue;
//			visited.insert(j);
//			que.push(j);
//		}
//		while (!que.empty())
//		{
//			int q = que.front();
//			que.pop();
//			for (int j = 0; j < M.size(); j++)
//			{
//				if (visited.count(j)) continue;
//				if (M[q][j] == 0) continue;
//				visited.insert(j);
//				que.push(j);
//			}
//		}
//		if (visited.size() == M.size()) return iNum;
//	}
//	return iNum;
//}

int main()
{
	vector<vector<vector<int>>> N;
	vector<int> A;

	N.push_back({ { 1,1,0 }, { 1,1,0 }, {0,0,1} });
	A.push_back(2);

	N.push_back({ { 1,1,0 }, { 1,1,1 }, {0,1,1} });
	A.push_back(1);

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////////" << endl;
		printVectorVectorInt(N[i]);
		int ans = findCircleNum(N[i]);
		cout << "Find Circle Num = " << A[i] << ", my answer = " << ans << endl;
	}
}