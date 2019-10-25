# `（中等）`  [279.NumSquares 完全平方数](https://leetcode-cn.com/problems/perfect-squares/)

### 题目描述
<p>给定正整数&nbsp;<em>n</em>，找到若干个完全平方数（比如&nbsp;<code>1, 4, 9, 16, ...</code>）使得它们的和等于<em> n</em>。你需要让组成和的完全平方数的个数最少。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> <em>n</em> = <code>12</code>
<strong>输出:</strong> 3 
<strong>解释: </strong><code>12 = 4 + 4 + 4.</code></pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> <em>n</em> = <code>13</code>
<strong>输出:</strong> 2
<strong>解释: </strong><code>13 = 4 + 9.</code></pre>




---
### 思路
``` 
这道题有3种解法，详情看cpp。  
```


### 答题
``` C++
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
``` 