# `（中等）` [978.longest-turbulent-subarray 最长湍流子数组](https://leetcode-cn.com/problems/longest-turbulent-subarray/)

### 题目描述
<p>当 <code>A</code>&nbsp;的子数组&nbsp;<code>A[i], A[i+1], ..., A[j]</code>&nbsp;满足下列条件时，我们称其为<em>湍流子数组</em>：</p>

<ul>
	<li>若&nbsp;<code>i &lt;= k &lt; j</code>，当 <code>k</code>&nbsp;为奇数时，&nbsp;<code>A[k] &gt; A[k+1]</code>，且当 <code>k</code> 为偶数时，<code>A[k] &lt; A[k+1]</code>；</li>
	<li><strong>或 </strong>若&nbsp;<code>i &lt;= k &lt; j</code>，当 <code>k</code> 为偶数时，<code>A[k] &gt; A[k+1]</code>&nbsp;，且当 <code>k</code>&nbsp;为奇数时，&nbsp;<code>A[k] &lt; A[k+1]</code>。</li>
</ul>

<p>也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。</p>

<p>返回 <code>A</code> 的最大湍流子数组的<strong>长度</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[9,4,2,10,7,8,8,1,9]
<strong>输出：</strong>5
<strong>解释：</strong>(A[1] &gt; A[2] &lt; A[3] &gt; A[4] &lt; A[5])
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[4,8,12,16]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>[100]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 40000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 10^9</code></li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/longest-turbulent-subarray/solution/longest-turbulent-subarray-by-ikaruga-xyi4/)

### 答题
``` C++
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        arr.push_back(arr.back());

        int ans = 1;
        int start = 0;
        int dir = 0; 
        
        for (int i = 1; i < arr.size(); i++) {
            int d = (arr[i] == arr[i - 1]) ? 0 : (arr[i] - arr[i - 1]) / abs(arr[i] - arr[i - 1]);
            
            ans = (d != 0) ? max(ans, 2) : ans;
            ans = (abs(dir - d) == 2) ? max(ans, i - start + 1) : ans;
            start = (dir == 0 || abs(dir - d) != 2) ? i - 1 : start;
            dir = d;
        }
        return ans;
    }
};
```




