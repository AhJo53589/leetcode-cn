# `（困难）` [992.subarrays-with-k-different-integers K 个不同整数的子数组](https://leetcode-cn.com/problems/subarrays-with-k-different-integers/)

### 题目描述
<p>给定一个正整数数组 <code>A</code>，如果 <code>A</code>&nbsp;的某个子数组中不同整数的个数恰好为 <code>K</code>，则称 <code>A</code> 的这个连续、不一定独立的子数组为<em>好子数组</em>。</p>

<p>（例如，<code>[1,2,3,1,2]</code> 中有&nbsp;<code>3</code>&nbsp;个不同的整数：<code>1</code>，<code>2</code>，以及&nbsp;<code>3</code>。）</p>

<p>返回&nbsp;<code>A</code>&nbsp;中<em>好子数组</em>的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>A = [1,2,1,2,3], K = 2
<strong>输出：</strong>7
<strong>解释：</strong>恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>A = [1,2,1,3,4], K = 3
<strong>输出：</strong>3
<strong>解释：</strong>恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 20000</code></li>
	<li><code>1 &lt;= A[i] &lt;= A.length</code></li>
	<li><code>1 &lt;= K &lt;= A.length</code></li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return GetMostDistinct(A, K) - GetMostDistinct(A, K - 1);
    }

    int GetMostDistinct(vector<int>& A, int K) {
        unordered_map<int, int> mp;
        int left = 0, right = 0, ret = 0;
        while (right < A.size()) {
            ++mp[A[right++]];
            while (mp.size() > K) {
                --mp[A[left]];
                if (mp[A[left]] == 0) mp.erase(A[left]);
                ++left;
            }
            // 如果这里改成 ret = max(ret, right - left)，那么此函数就是 LeetCode 904 题的解。
            // 这里可以用动态规划的思想来理解 ret += right - left
            // right 增加一次，增加的数组个数可以用 right - left 来表示
            ret += right - left;
        }
        return ret;
    }
};
```




