// 88.Merge.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	int k = m + n;

	while (k > 0)
	{
		k -= 1;
		if (m > 0 && n > 0)
		{
			if (nums1[m - 1] < nums2[n - 1])
			{
				nums1[k] = nums2[n - 1];
				n -= 1;
			}
			else
			{
				nums1[k] = nums1[m - 1];
				m -= 1;
			}
		}
		else if (m == 0 && n != 0)
		{
			nums1[k] = nums2[n - 1];
			n -= 1;
		}
		else if (m != 0 && n == 0)
		{
			break;
			//nums1[k] = nums1[m - 1];
			//m -= 1;
		}
	}
}

int main()
{
    std::cout << "Hello World!\n"; 
}

