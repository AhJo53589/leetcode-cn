// 394.decode-string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>

using namespace std;

string getNormal(string s)
{
	string str;
	for (char c : s)
	{
		if (c <= '9' && c >= '0') return str;
		str += c;
	}
	return str;
}

string getNum(string s)
{
	string str;
	for (char c : s)
	{
		if (c == '[') return str;
		str += c;
	}
	return str;
}

string getSub(string s)
{
	string str;
	stack<char> st;
	for (char c : s)
	{
		if (c == '[') st.push(c);
		if (c == ']') st.pop();
		str += c;
		if (st.empty()) return str;
	}
	return str;
}

string decodeString(string s)
{
	string strText;

	int i = 0;
	while (i < s.size())
	{
		string strTemp;
		strTemp = getNormal(s.substr(i, s.size()));
		i += strTemp.size();
		strText += strTemp;

		strTemp = getNum(s.substr(i, s.size()));
		i += strTemp.size();
		string strNum = strTemp;

		strTemp = getSub(s.substr(i, s.size()));
		i += strTemp.size();
		if (strTemp.size() > 2)
		{
			string strSubText = decodeString(strTemp.substr(1, strTemp.size() - 2));
			int iNum = stoi(strNum);
			while (iNum-- > 0) strText += strSubText;
		}
	}

	return strText;
}

//string decodeString(string s) {
//	int num = 0;
//	string cur = "";
//	stack<int> nums;
//	stack<string> str;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] >= '0' && s[i] <= '9') {
//			num = num * 10 + s[i] - '0';
//		}
//		else if (s[i] == '[') {
//			nums.push(num);
//			num = 0;
//			str.push(cur);
//			cur = "";
//		}
//		else if (s[i] == ']') {
//			int k = nums.top();
//			nums.pop();
//			for (int i = 0; i < k; i++) {
//				str.top() += cur;
//			}
//			cur = str.top();
//			str.pop();
//		}
//		else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
//			cur = cur + s[i];
//		}
//	}
//	return cur;
//}

int main()
{
	string s;
	s = "3[a]2[bc]";
	s = "3[a2[c]]";
	s = "2[abc]3[cd]ef";
	s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";

	cout << "origin: " << s << endl;
	cout << "decode: " << decodeString(s) << endl;
}
