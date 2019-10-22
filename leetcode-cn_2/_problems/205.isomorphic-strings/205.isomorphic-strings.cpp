// 205.isomorphic-strings.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

//#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;


unordered_map<char, char> m;
unordered_set<char> c;
bool isIsomorphic(string s, string t)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (m.count(s[i]))
		{
			if (m[s[i]] != t[i]) return false;
		}
		else
		{
			if (c.count(t[i])) return false;
			m[s[i]] = t[i];
			c.insert(t[i]);
		}
	}
	return true;
}

int main()
{
	//string s1 = "ab";
	//string s2 = "aa";
	string s1 = "paper";
	string s2 = "title";
	cout << isIsomorphic(s1, s2) << endl;
}
