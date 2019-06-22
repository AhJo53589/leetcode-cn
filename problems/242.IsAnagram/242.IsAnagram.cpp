// 242.IsAnagram.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

bool isAnagram(string s, string t)
{
	if (s.size() != t.size()) return false;

	vector<int> charCount_s(26, 0);
	vector<int> charCount_t(26, 0);
	for (int i = 0; i < s.size(); i++)
	{
		charCount_s[s[i] - 'a'] ++;
		charCount_t[t[i] - 'a'] ++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (charCount_s[i] != charCount_t[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string s = "loveleetcode";
	string t = "leetcodelove";
	cout << isAnagram(s, t) << endl;
}
