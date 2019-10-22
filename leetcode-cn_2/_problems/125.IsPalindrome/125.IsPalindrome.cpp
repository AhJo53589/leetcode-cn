// 125.IsPalindrome.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

char getChar(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return c - 'A' + 'a';
	}
	else if (c >= 'a' && c <= 'z')
	{
		return c;
	}
	else if (c >= '0' && c <= '9')
	{
		return c;
	}
	return NULL;
}

string getCleanString(string s)
{
	string t;
	for (int i = 0; i < s.size(); i++)
	{
		char c = getChar(s[i]);
		if (c != NULL)
		{
			t.push_back(c);
		}
	}
	return t;
}

bool isPalindrome(string s)
{
	if (s.size() == 0) return true;

	string t = getCleanString(s);
	int len = t.size();
	for (int i = 0; i < len / 2; i++)
	{
		if (t[i] != t[len - i - 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	// 	string s = "A man, a plan, a canal: Panama";
	string s = "0P";
	cout << isPalindrome(s) << endl;
}
