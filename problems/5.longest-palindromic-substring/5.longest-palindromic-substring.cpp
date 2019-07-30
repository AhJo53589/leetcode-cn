// 5.longest-palindromic-substring.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
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

void findPalindrome(string s, int &low, int &high)
{
	while (s[low] == s[high])
	{
		low--;
		high++;
		if (low < 0 || high > s.size() - 1) break;
	}
	low++;
	high--;
}

string longestPalindrome(string s)
{
	if (s.size() == 1) return s;
	string res;
	res.push_back(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1])
		{
			int low = i - 1;
			int high = i;
			findPalindrome(s, low, high);
			if (high - low + 1 > res.size()) res = s.substr(low, high - low + 1);
		}
		if ((i + 1 < s.size()) && s[i - 1] == s[i + 1])
		{
			int low = i - 1;
			int high = i + 1;
			findPalindrome(s, low, high);
			if (high - low + 1 > res.size()) res = s.substr(low, high - low + 1);
		}
	}
	return res;
}

int main()
{
	vector<string> str;
	str.push_back("babad");
	str.push_back("babab");
	str.push_back("cbbd");
	str.push_back("ac");

	for (auto s : str)
	{
		cout << endl << "/////////////////////////////////" << endl;
		cout << s << endl;
		cout << longestPalindrome(s) << endl;
	}
}