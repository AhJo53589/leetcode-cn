// 9.palindrome-number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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



bool isPalindrome(int x)
{
	if (x < 0) return false;
	if (x < 10) return true;

	deque<int> d;
	while (x >= 1)
	{
		d.push_back(x % 10);
		x /= 10;
	}
	while (d.size() > 1)
	{
		int h = d.front();
		d.pop_front();
		int t = d.back();
		d.pop_back();
		if (h != t) return false;
	}
	return true;
}

//bool isPalindrome(int x) {
//	if (x < 0 || ((x % 10 == 0) && x != 0)) {
//		return false;
//	}
//	int reverse = 0;
//	while (x > reverse) {
//		reverse = reverse * 10 + x % 10;
//		x /= 10;
//	}
//	return x == reverse || x == reverse / 10;
//}

int main()
{
	vector<int> N;
	N.push_back(121);
	N.push_back(-121);
	N.push_back(10);
	N.push_back(9);
	N.push_back(123454321);
	N.push_back(123321);

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////////" << endl;
		cout << N[i] << endl;
		bool ans = isPalindrome(N[i]);
		cout << ans << endl;
	}
}