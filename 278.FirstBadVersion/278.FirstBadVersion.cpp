// 278.FirstBadVersion.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

bool isBadVersion(int version)
{
	if (version > 5)
	{
		return true;
	}
	return false;
}

int firstBadVersion(int n)
{
	int low = 1;
	int high = n;

	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (isBadVersion(mid))
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	return low;
}

int main()
{
	cout << firstBadVersion(9) << endl;
}
