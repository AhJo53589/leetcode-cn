# `（简单）` [5238.find-positive-integer-solution-for-a-given-equation 找出给定方程的正整数解](https://leetcode-cn.com/problems/find-positive-integer-solution-for-a-given-equation/)

[contest](https://leetcode-cn.com/contest/weekly-contest-160/problems/find-positive-integer-solution-for-a-given-equation/)

### 题目描述

<p>给出一个函数&nbsp;&nbsp;<code>f(x, y)</code>&nbsp;和一个目标结果&nbsp;<code>z</code>，请你计算方程&nbsp;<code>f(x,y) == z</code>&nbsp;所有可能的正整数 <strong>数对</strong>&nbsp;<code>x</code> 和 <code>y</code>。</p>

<p>给定函数是严格单调的，也就是说：</p>

<ul>
	<li><code>f(x, y) &lt; f(x + 1, y)</code></li>
	<li><code>f(x, y) &lt; f(x, y + 1)</code></li>
</ul>

<p>函数接口定义如下：</p>

<pre>interface CustomFunction {
public:
&nbsp; // Returns positive integer f(x, y) for any given positive integer x and y.
&nbsp; int f(int x, int y);
};
</pre>

<p>如果你想自定义测试，你可以输入整数&nbsp;<code>function_id</code>&nbsp;和一个目标结果&nbsp;<code>z</code>&nbsp;作为输入，其中&nbsp;<code>function_id</code>&nbsp;表示一个隐藏函数列表中的一个函数编号，题目只会告诉你列表中的 <code>2</code> 个函数。 &nbsp;</p>

<p>你可以将满足条件的 <strong>结果数对</strong> 按任意顺序返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>function_id = 1, z = 5
<strong>输出：</strong>[[1,4],[2,3],[3,2],[4,1]]
<strong>解释：</strong>function_id = 1 表示 f(x, y) = x + y</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>function_id = 2, z = 5
<strong>输出：</strong>[[1,5],[5,1]]
<strong>解释：</strong>function_id = 2 表示 f(x, y) = x * y
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= function_id &lt;= 9</code></li>
	<li><code>1 &lt;= z &lt;= 100</code></li>
	<li>题目保证&nbsp;<code>f(x, y) == z</code>&nbsp;的解处于&nbsp;<code>1 &lt;= x, y &lt;= 1000</code>&nbsp;的范围内。</li>
	<li>在 <code>1 &lt;= x, y &lt;= 1000</code>&nbsp;的前提下，题目保证&nbsp;<code>f(x, y)</code>&nbsp;是一个&nbsp;32 位有符号整数。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
vector<vector<int>> findSolution(CustomFunction& customfunction, int z)
{
	vector<vector<int>> ans;
	for (int a = 1; a <= z; a++)
	{
		for (int b = 1; b <= z; b++)
		{
			if (customfunction.f(a, b) == z)
			{
				ans.push_back({ a, b });
			}
			else if (customfunction.f(a, b) > z)
			{
				break;
			}
		}
	}
	return ans;
}
```




