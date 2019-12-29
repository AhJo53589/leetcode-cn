# `（简单）` [5295.find-n-unique-integers-sum-up-to-zero 和为零的N个唯一整数](https://leetcode-cn.com/problems/find-n-unique-integers-sum-up-to-zero/)

[contest](https://leetcode-cn.com/contest/weekly-contest-169/problems/find-n-unique-integers-sum-up-to-zero/)

### 题目描述
<p>给你一个整数&nbsp;<code>n</code>，请你返回 <strong>任意&nbsp;</strong>一个由 <code>n</code>&nbsp;个 <strong>各不相同&nbsp;</strong>的整数组成的数组，并且这 <code>n</code> 个数相加和为 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 5
<strong>输出：</strong>[-7,-1,1,3,4]
<strong>解释：</strong>这些数组也是正确的 [-5,-1,1,2,3]，[-3,-1,2,-2,4]。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 3
<strong>输出：</strong>[-1,0,1]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 1
<strong>输出：</strong>[0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
vector<int> sumZero(int n)
{
    vector<int> ans;
    for (int i = 0; i < n / 2; i++)
    {
        ans.push_back(i + 1);
        ans.push_back(- i - 1);
    }
    if (n % 2 == 1)
    {
        ans.push_back(0);
    }
    return ans;
}
```




