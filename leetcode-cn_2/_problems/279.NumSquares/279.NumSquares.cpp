// 279.NumSquares.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <random>

using namespace std;


//1:动态规划,完全背包问题
/*
(1)
时间复杂度O(nlogn)，空间复杂度O(n)。
定义一个函数f(n)表示我们要求的解。f(n)的求解过程为：
f(n) = 1 + min{f(n-1^2), f(n-2^2), f(n-3^2), f(n-4^2), ... , f(n-k^2) //(k为满足k^2<=n的最大的k)
}
//从f(n-1^2), f(n-2^2), f(n-3^2), f(n-4^2), ... , f(n-k^2)走一步到f(n)
*/
//执行用时 :140 ms, 在所有C++提交中击败了58.42%的用户
//内存消耗 :11.4 MB, 在所有C++提交中击败了38.63%的用户
/*
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1, 0);

		for(int i=1;i<=n;++i){
			int min_cnt = INT_MAX;
			for(int j=1;j*j<=i;++j){
				min_cnt = min(min_cnt, dp[i - j * j]);
			dp[i] = min_cnt + 1;//+1
			}
		}
		return dp[n];
	}
};
*/

/*
(2)
我们要知道12最少有多少个数构成，实际上如果我们走了一步的话，我们需要知道11、8、3对应的步数，如果我们不走，我们就需要知道12的步数，我们只要通过比较是走0步小，还是走1步哪个更小即可。通过一个式子表示就是

num[n] = min(num[n], num[n-i**2] + 1)

原文：https://blog.csdn.net/qq_17550379/article/details/80875782
*/

//（3）
//dp[i] = min(dp[i], dp[i - j * j] + 1)


//2:bfs,图的广度优先遍历
/*
例如对于上图中的5，我们要前往0，我们的第一步有两种走法，先走4和先走1。所以我们需要建立一个队列或者栈，然后将第一步的走法压入队列或者栈中。如下（使用队列， 我们同时记录走的步数）
q : (4, 1) (1, 1)
我们将4出队，然后看4的下一步怎么走，发现只能走3，所以我们将(3, 2)入队
q : (1, 1) (3, 2)
接着我们将(1, 1)弹出，我们看1的下一步怎么走，发现只能走0，这个时候我们发现已经到达了0，那么我们更新step+1，然后出循环即可。

//执行用时 :56 ms, 在所有C++提交中击败了82.72%的用户
//内存消耗 :12.1 MB, 在所有C++提交中击败了23.20%的用户
*/

/*
class Solution {
public:
	int numSquares(int n) {
		queue<pair<int, int>> q;

		q.push(make_pair(n, 0));

		vector<bool> vis(n + 1, false);//n + 1
		vis[n] = true;

		while(!q.empty()){
			int num = q.front().first;//pair用.first和.second
			int step = q.front().second;
			q.pop();//front() + pop()

			for(int i = 1;num - i * i >= 0;++i){
				int tnum = num - i * i;

				if(tnum < 0)
					break;
				if(tnum == 0)
					return step + 1;

				if(!vis[tnum])
					q.push(make_pair(tnum, step + 1));
				vis[tnum] = true;
			}
		}
		return 0;
	}
};
*/

//3:四平方和定理,任何一个正整数都可以表示成不超过四个整数的平方之和。(我们的结果只有1,2,3,4，四种可能。)
//推论：满足四数平方和定理的数n（四个整数的情况），必定满足 n=(4^a)*(8b+7)

//class Solution {
//public:
//	int numSquares(int n) {
//		while (n % 4 == 0)
//			n /= 4;
//		if (n % 8 == 7)
//			return 4;
//
//		for (int a = 0; a * a <= n; ++a) {
//			int b = sqrt(n - a * a);
//			if (a * a + b * b == n)
//				return (not not a) + (not not b);//a=1或b=1,返回1;a=1且b=1,返回2;a=0且b=0,返回0
//		}
//		return 3;
//	}
//};


int numSquares(int n)
{
	set<int> usedSet;
	queue<pair<int, int>> que;
	que.push({ n,0 });
	while (!que.empty())
	{
		auto iCheck = que.front();
		que.pop();
		for (int i = 1; i*i <= iCheck.first; i++)
		{
			int nLeftNum = iCheck.first - i * i;
			if (usedSet.count(nLeftNum)) continue;
			if (nLeftNum == 0) return iCheck.second + 1;
			que.push({ nLeftNum, iCheck.second + 1 });
			usedSet.insert(nLeftNum);
		}
	}
	return 0;
}

int main()
{
	int iNum = 13;
	cout << numSquares(iNum);
}
