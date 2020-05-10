# `（困难）` [5407.number-of-ways-of-cutting-a-pizza 切披萨的方案数](https://leetcode-cn.com/problems/number-of-ways-of-cutting-a-pizza/)

[contest](https://leetcode-cn.com/contest/weekly-contest-188/problems/number-of-ways-of-cutting-a-pizza/)

### 题目描述
<p>给你一个&nbsp;<code>rows x cols</code>&nbsp;大小的矩形披萨和一个整数 <code>k</code>&nbsp;，矩形包含两种字符：&nbsp;<code>'A'</code> （表示苹果）和&nbsp;<code>'.'</code>&nbsp;（表示空白格子）。你需要切披萨 <code>k-1</code> 次，得到&nbsp;<code>k</code>&nbsp;块披萨并送给别人。</p>

<p>切披萨的每一刀，先要选择是向垂直还是水平方向切，再在矩形的边界上选一个切的位置，将披萨一分为二。如果垂直地切披萨，那么需要把左边的部分送给一个人，如果水平地切，那么需要把上面的部分送给一个人。在切完最后一刀后，需要把剩下来的一块送给最后一个人。</p>

<p>请你返回确保每一块披萨包含&nbsp;<strong>至少</strong>&nbsp;一个苹果的切披萨方案数。由于答案可能是个很大的数字，请你返回它对 10^9 + 7 取余的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="height: 378px; width: 500px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/10/ways_to_cut_apple_1.png" alt=""></strong></p>

<pre><strong>输入：</strong>pizza = ["A..","AAA","..."], k = 3
<strong>输出：</strong>3 
<strong>解释：</strong>上图展示了三种切披萨的方案。注意每一块披萨都至少包含一个苹果。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>pizza = ["A..","AA.","..."], k = 3
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>pizza = ["A..","A..","..."], k = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= rows, cols <= 50</code></li>
	<li><code>rows ==&nbsp;pizza.length</code></li>
	<li><code>cols ==&nbsp;pizza[i].length</code></li>
	<li><code>1 <= k <= 10</code></li>
	<li><code>pizza</code>&nbsp;只包含字符&nbsp;<code>'A'</code>&nbsp;和&nbsp;<code>'.'</code>&nbsp;。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int ways(vector<string>& pizza, int k) {

    }
};
```




