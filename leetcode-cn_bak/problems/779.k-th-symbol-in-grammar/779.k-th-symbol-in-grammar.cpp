// 779.k-th-symbol-in-grammar.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

using namespace std;

// 容易发现结果只取决于 K，与 N 无关。
// a[i] 由 a[i / 2] 生成，i为偶数时不变，奇数时取反。

// 举个例子：
// a[5]，奇数坐标，等于a[5 / 2] = a[2]取反，a[2]又等于a[1]，a[1]又等于a[0]取反。
// 终止条件就是a[0], 我们知道a[0] = 0;
// 只需要在折半的过程中根据奇偶进行取反即可。

//int kthGrammar(int N, int K)
//{
//	K--; //counting from 0 instead of 1
//	bool r = 0;
//	while (K)
//	{
//		r ^= (K & 1);
//		K /= 2;
//	}
//	return r;
//}

int kthGrammar(int N, int K)
{
	if (N == 1) return 0;
	return (kthGrammar(N - 1, (K - 1) / 2 + 1) == 0) ? ((K - 1) % 2) : 1 - ((K - 1) % 2);
}

int main()
{
	for (int i = 1; i < 5; i++)
	{
		cout << "[" << i << "] = " << endl;
		for (int j = 1; j < pow(2, i - 1) + 1; j++)
		{
			cout << kthGrammar(i, j) << " ";
		}
		cout << endl << endl;
	}
}
