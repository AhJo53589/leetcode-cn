// 344.ReverseString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) 
{
	int iLen = s.size();
	for (int i = 0; i < iLen / 2; i++)
	{
		swap(s[i], s[iLen - i - 1]);
	}
}

int main()
{
    std::cout << "Hello World!\n"; 
}

