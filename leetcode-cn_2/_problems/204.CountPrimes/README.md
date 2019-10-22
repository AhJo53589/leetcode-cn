# `（简单）`  [204.CountPrimes 计数质数](https://leetcode-cn.com/problems/count-primes/)

### 题目描述
<p>统计所有小于非负整数&nbsp;<em>n&nbsp;</em>的质数的数量。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 10
<strong>输出:</strong> 4
<strong>解释:</strong> 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
</pre>




---
### 思路
``` 
```


### 答题
``` C++
int countPrimes(int n) 
{
	if (n < 3) return 0;

	vector<bool> primeFlag(n);
	primeFlag[2] = true;
	for (long long i = 3; i < n; i += 2)
	{
		primeFlag[i] = true; // 所有奇数标为true，偶数为false
	}
	for (long long i = 3; i < n; i++)
	{
		if (primeFlag[i])
		{
			int cnt = 2;
			while (cnt * i < n)
			{
				// 把i的倍数标为false（因为它们是合数）
				primeFlag[cnt * i] = false;
				cnt++;
			}
		}
	}

	int cnt = 1;
	for (long long i = 3; i < n; i += 2)
	{
		if (primeFlag[i])
		{
			//cout << cnt << ' ' << i << endl;
			cnt++;
		}
	}
	return cnt;
}
``` 