# `（中等）` [5256.reconstruct-a-2-row-binary-matrix 重构 2 行二进制矩阵](https://leetcode-cn.com/problems/reconstruct-a-2-row-binary-matrix/)

[contest](https://leetcode-cn.com/contest/weekly-contest-162/problems/reconstruct-a-2-row-binary-matrix/)

### 题目描述
<p>给你一个&nbsp;<code>2</code>&nbsp;行 <code>n</code> 列的二进制数组：</p>

<ul>
	<li>矩阵是一个二进制矩阵，这意味着矩阵中的每个元素不是&nbsp;<code>0</code>&nbsp;就是&nbsp;<code>1</code>。</li>
	<li>第 <code>0</code> 行的元素之和为&nbsp;<code>upper</code>。</li>
	<li>第 <code>1</code> 行的元素之和为 <code>lower</code>。</li>
	<li>第 <code>i</code> 列（从 <code>0</code> 开始编号）的元素之和为&nbsp;<code>colsum[i]</code>，<code>colsum</code>&nbsp;是一个长度为&nbsp;<code>n</code>&nbsp;的整数数组。</li>
</ul>

<p>你需要利用&nbsp;<code>upper</code>，<code>lower</code>&nbsp;和&nbsp;<code>colsum</code>&nbsp;来重构这个矩阵，并以二维整数数组的形式返回它。</p>

<p>如果有多个不同的答案，那么任意一个都可以通过本题。</p>

<p>如果不存在符合要求的答案，就请返回一个空的二维数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>upper = 2, lower = 1, colsum = [1,1,1]
<strong>输出：</strong>[[1,1,0],[0,0,1]]
<strong>解释：</strong>[[1,0,1],[0,1,0]] 和 [[0,1,1],[1,0,0]] 也是正确答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>upper = 2, lower = 3, colsum = [2,2,1,1]
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
<strong>输出：</strong>[[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= colsum.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= upper, lower &lt;= colsum.length</code></li>
	<li><code>0 &lt;= colsum[i] &lt;= 2</code></li>
</ul>

            

---
### 思路
```
```
[发布的题解](https://leetcode-cn.com/problems/reconstruct-a-2-row-binary-matrix/solution/5256-by-ikaruga/)


### 答题
``` C++
vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) 
{
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (auto &c : colsum)
    {
        cnt0 += (c == 0);
        cnt1 += (c == 1);
        cnt2 += (c == 2);
    }
    if (upper + lower != cnt1 + cnt2 * 2) return {};
    if (upper > colsum.size() - cnt0) return {};
    if (lower > colsum.size() - cnt0) return {};

    vector<vector<int>> ans(2, vector<int>());
    for (auto &c : colsum)
    {
        if (c == 0)
        {
            ans[0].push_back(0);
            ans[1].push_back(0);
        }
        else if (c == 2)
        {
            ans[0].push_back(1);
            ans[1].push_back(1);
            cnt2--;
            upper--;
            lower--;
        }
        else
        {
            if (upper > cnt2)
            {
                ans[0].push_back(1);
                ans[1].push_back(0);
                upper--;
            }
            else if (lower > cnt2)
            {
                ans[0].push_back(0);
                ans[1].push_back(1);
                lower--;
            }
            else 
            {
                return {};
            }
        }
    }
    return ans;
}
```




