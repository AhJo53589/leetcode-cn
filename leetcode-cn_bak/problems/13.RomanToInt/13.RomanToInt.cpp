﻿// 13.RomanToInt.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <random>

using namespace std;

//string intToRoman(int num)
//{
//	char* c[4][10] = {
//		{"","I","II","III","IV","V","VI","VII","VIII","IX"},
//		{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
//		{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
//		{"","M","MM","MMM"}
//	};
//	string roman;
//	roman.append(c[3][num / 1000 % 10]);
//	roman.append(c[2][num / 100 % 10]);
//	roman.append(c[1][num / 10 % 10]);
//	roman.append(c[0][num % 10]);
//
//	return roman;
//}

int romanToInt(string s)
{
	int result = 0;
	map<char, int> luomab;
	luomab.insert(map<char, int>::value_type('I', 1));
	luomab.insert(map<char, int>::value_type('V', 5));
	luomab.insert(map<char, int>::value_type('X', 10));
	luomab.insert(map<char, int>::value_type('L', 50));
	luomab.insert(map<char, int>::value_type('C', 100));
	luomab.insert(map<char, int>::value_type('D', 500));
	luomab.insert(map<char, int>::value_type('M', 1000));

	for (int i = 0; i < s.length(); i++)
	{
		if (luomab[s[i]] >= luomab[s[i + 1]])
		{
			result += luomab[s[i]];
		}
		else
		{
			result += (luomab[s[i + 1]] - luomab[s[i]]);
			i++;
		}
	}
	return result;
}

int main()
{

}