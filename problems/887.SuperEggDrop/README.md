# `（困难）`  [887.SuperEggDrop 鸡蛋掉落](https://leetcode-cn.com/problems/super-egg-drop/)

### 题目描述
<p>你将获得&nbsp;<code>K</code>&nbsp;个鸡蛋，并可以使用一栋从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>N</code>&nbsp;&nbsp;共有 <code>N</code>&nbsp;层楼的建筑。</p>

<p>每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。</p>

<p>你知道存在楼层&nbsp;<code>F</code> ，满足&nbsp;<code>0 &lt;= F &lt;= N</code> 任何从高于 <code>F</code>&nbsp;的楼层落下的鸡蛋都会碎，从&nbsp;<code>F</code>&nbsp;楼层或比它低的楼层落下的鸡蛋都不会破。</p>

<p>每次<em>移动</em>，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层&nbsp;<code>X</code>&nbsp;扔下（满足&nbsp;<code>1 &lt;= X &lt;= N</code>）。</p>

<p>你的目标是<strong>确切地</strong>知道 <code>F</code> 的值是多少。</p>

<p>无论 <code>F</code> 的初始值如何，你确定 <code>F</code> 的值的最小移动次数是多少？</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>K = 1, N = 2
<strong>输出：</strong>2
<strong>解释：</strong>
鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
如果它没碎，那么我们肯定知道 F = 2 。
因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>K = 2, N = 6
<strong>输出：</strong>3
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>K = 3, N = 14
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= K &lt;= 100</code></li>
	<li><code>1 &lt;= N &lt;= 10000</code></li>
</ol>



---
### 思路
```
从【已知N层楼，K个蛋，求最小必要行动次数T】  
变成【已知K个蛋，求T次行动可以判断的楼层数>N】
```
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/problems/887.SuperEggDrop/Solution.jpg)
> Solution2.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/problems/887.SuperEggDrop/Solution2.jpg)

### 答题
``` C++
int calcMaximumCoverage(int iTime, int K)
{
	// 有K个蛋，行动iTime次，计算能判断多少层

	// 如果只有1次行动了，无论有几个蛋，都只能判断出2层
	if (iTime == 1) return 2;	

	// 如果只有1个蛋了，蛋不能碎，只能一层一层判断，可以判断出iTime + 1层	
	if (K == 1) return iTime + 1;	

	// 行动一次，扔个蛋，计算蛋碎了的情况下能判断多少层
	// + 蛋没碎的情况能判断多少层
	return calcMaximumCoverage(iTime - 1, K - 1)
	 + calcMaximumCoverage(iTime - 1, K);
}

int superEggDrop(int K, int N)	// 8ms
{
	int iTime = 0;
	int iMaxCoverage = 0;
	do
	{
		++iTime;
		iMaxCoverage = calcMaximumCoverage(iTime, K);
	} while (iMaxCoverage < N + 1);
	return iTime;
}
``` 