// 151.reverse-words-in-a-string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
using namespace std;

string reverseWords(string s)
{
	stack<string> st;
	string sub;
	s += " ";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			sub += s[i];
		}
		else
		{
			if (!sub.empty())
			{
				st.push(sub);
				sub.clear();
			}
		}
	}
	string str;
	while (!st.empty())
	{
		str += st.top();
		st.pop();
		str += " ";
	}
	if (!str.empty())
	{
		str = str.substr(0, str.size() - 1);
	}
	return str;
}


//string reverseWords(string s)
//{
//	int start = 0, end = s.length() - 1;
//	while (start < s.length() && s[start] == ' ') ++start;
//	while (end >= 0 && s[end] == ' ') --end;
//	if (start > end)
//	{
//		s[end + 1] = '\0';
//		return string(s.c_str());
//	}
//	++end;
//
//	int offset = 0;
//	int subStart = start;
//
//	for (int idx = start; idx <= end; ++idx)
//	{
//		if (s[idx] == ' ' || idx == end)
//		{
//			if (s[idx - 1] != ' ' || idx == end)
//			{
//				int wordLen = idx - subStart;
//				int swapNum = (idx - offset) / 2;
//				for (int i = 0; i < wordLen; ++i, ++offset)
//				{
//					if (i < swapNum)
//					{
//						char temp = s[offset];
//						s[offset] = s[idx - 1 - i];
//						s[idx - 1 - i] = temp;
//
//						cout << s << endl;
//					}
//				}
//				if (idx != end)
//				{
//					s[offset++] = ' ';
//					cout << s << endl;
//				}
//			}
//			subStart = idx + 1;
//		}
//	}
//
//	s[offset] = '\0';
//	cout << s << endl;
//	for (int i = 0; i < (offset / 2); ++i)
//	{
//		char temp = s[i];
//		s[i] = s[offset - 1 - i];
//		s[offset - 1 - i] = temp;
//	}
//	cout << s << endl;
//
//	return string(s.c_str());;
//}

int main()
{
	string str = "   the  sky    is blue    ";
	cout << str << endl;
	cout << reverseWords(str) << endl;
}