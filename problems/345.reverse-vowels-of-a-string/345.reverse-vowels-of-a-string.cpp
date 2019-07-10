// 345.reverse-vowels-of-a-string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

//bool isVowel(char c)
//{
//	unordered_set<char> list = { 'a', 'o', 'e', 'i', 'u' };
//	return list.count(c);
//}

string reverseVowels(string s)
{
	int low = 0;
	int high = s.size() - 1;
	while (low < high)
	{
		auto isVowel = [](char c) { unordered_set<char> list = { 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U' }; return list.count(c); };
		while (low < high && !isVowel(s[low])) low++;
		while (low < high && !isVowel(s[high])) high--;
		swap(s[low++], s[high--]);
	}
	return s;
}

int main()
{
	string s = "leetcode";
	cout << reverseVowels(s);
}
