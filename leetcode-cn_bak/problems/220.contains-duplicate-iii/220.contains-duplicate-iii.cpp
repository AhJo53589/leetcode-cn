// 220.contains-duplicate-iii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	set<double> _set;
	for (int i = 0; i < nums.size(); ++i)
	{
		auto s = _set.lower_bound((double)nums[i] - (double)t);
		if (s != _set.end() && *s <= (double)nums[i] + (double)t) return true;

		_set.insert(nums[i]);
		if (_set.size() > k) _set.erase(nums[i - k]);
	}
	return false;
}

int main()
{
	vector<vector<int>> N;
	vector<int> K;
	vector<int> T;
	vector<bool> A;

	N.push_back({ 1,2,3,1 });
	K.push_back(3);
	T.push_back(0);
	A.push_back(true);

	N.push_back({ 1,0,1,1 });
	K.push_back(1);
	T.push_back(2);
	A.push_back(true);

	N.push_back({ 1,5,9,1,5,9 });
	K.push_back(2);
	T.push_back(3);
	A.push_back(false);

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		for (int j = 0; j < N.size(); j++)
		{
			int ans = containsNearbyAlmostDuplicate(N[i], K[i], T[i]);
			//cout << checkAnswer<bool>(ans, A[i]) << endl;
			string check = (ans == A[i]) ? "" : "\t\tWRONG!";
			cout << ans << "\t <== " << A[i] << check << endl;
		}
	}
}