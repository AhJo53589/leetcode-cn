// 3.longest-substring-without-repeating-characters.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

int lengthOfLongestSubstring(string s)
{
	int len = 0;
	unordered_set<char> set;
	for (int i = 0; i < s.size(); i++)
	{
		int len_temp = 0;
		set.clear();
		for (int j = i; j < s.size(); j++)
		{
			if (!set.count(s[j]))
			{
				set.insert(s[j]);
				len_temp++;
				continue;
			}
			break;
		}
		len = max(len, len_temp);
	}
	return len;
}

int main()
{
	string S = "pwwkewab";

	cout << lengthOfLongestSubstring(S) << endl;
}
