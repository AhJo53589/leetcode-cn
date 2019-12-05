# `（困难）` [1274.number-of-ships-in-a-rectangle 矩形内船只的数目](https://leetcode-cn.com/problems/number-of-ships-in-a-rectangle/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-14/problems/number-of-ships-in-a-rectangle/)

### 题目描述
<p><em>(此题是 <strong>交互式问题&nbsp;</strong>)</em></p>

<p>在用笛卡尔坐标系表示的二维海平面上，有一些船。每一艘船都在一个整数点上，且每一个整数点最多只有 1 艘船。</p>

<p>有一个函数&nbsp;<code>Sea.hasShips(topRight, bottomLeft)</code>&nbsp;，输入参数为右上角和左下角两个点的坐标，当且仅当这两个点所表示的矩形区域（包含边界）内至少有一艘船时，这个函数才返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code> 。</p>

<p>给你矩形的右上角&nbsp;<code>topRight</code> 和左下角&nbsp;<code>bottomLeft</code> 的坐标，请你返回此矩形内船只的数目。题目保证矩形内&nbsp;<strong>至多只有 10 艘船</strong>。</p>

<p>调用函数&nbsp;<code>hasShips</code>&nbsp;<strong>超过400次&nbsp;</strong>的提交将被判为&nbsp;<em>错误答案（Wrong Answer）</em>&nbsp;。同时，任何尝试绕过评测系统的行为都将被取消比赛资格。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<p><img alt="" src="./1445_example_1.png" style="height: 404px; width: 400px;"></p>

<pre><strong>输入：</strong>
ships = [[1,1],[2,2],[3,3],[5,5]], topRight = [4,4], bottomLeft = [0,0]
<strong>输出：</strong>3
<strong>解释：</strong>在 [0,0] 到 [4,4] 的范围内总共有 3 艘船。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>ships</code>&nbsp;数组只用于评测系统内部初始化。你无法得知&nbsp;<code>ships</code>&nbsp;的信息，所以只能通过调用&nbsp;<code>hasShips</code>&nbsp;接口来求解。</li>
	<li><code>0 &lt;=&nbsp;bottomLeft[0]&nbsp;&lt;= topRight[0]&nbsp;&lt;= 1000</code></li>
	<li><code>0 &lt;=&nbsp;bottomLeft[1]&nbsp;&lt;= topRight[1]&nbsp;&lt;= 1000</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft)
{
	int x = topRight[0], y = topRight[1], a = bottomLeft[0], b = bottomLeft[1];
	if (a > x || b > y) return 0;
	if (a == x && b == y) return sea.hasShips(topRight, bottomLeft);

	if (sea.hasShips(topRight, bottomLeft))
	{
		int m = (a + x) >> 1, n = (b + y) >> 1;
		return countShips(sea, { m, n }, { a, b }) +
			countShips(sea, { x, y }, { m + 1, n + 1 }) +
			countShips(sea, { m, y }, { a, n + 1 }) +
			countShips(sea, { x, n }, { m + 1, b });
	}
	return 0;
}
```




