# `（困难）` [1420.build-array-where-you-can-find-the-maximum-exactly-k-comparisons 生成数组](https://leetcode-cn.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/)

[contest](https://leetcode-cn.com/contest/weekly-contest-185/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/)

### 题目描述
<p>给你三个整数 <code>n</code>、<code>m</code> 和 <code>k</code> 。下图描述的算法用于找出正整数数组中最大的元素。</p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/19/e.png" style="height: 372px; width: 424px;"></p>

<p>请你生成一个具有下述属性的数组 <code>arr</code> ：</p>

<ul>
	<li><code>arr</code> 中有 <code>n</code> 个整数。</li>
	<li><code>1 &lt;= arr[i] &lt;= m</code> 其中 <code>(0 &lt;= i &lt; n)</code> 。</li>
	<li>将上面提到的算法应用于 <code>arr</code> ，<code>search_cost</code> 的值等于 <code>k</code> 。</li>
</ul>

<p>返回上述条件下生成数组 <code>arr</code> 的 <strong>方法数</strong> ，由于答案可能会很大，所以 <strong>必须</strong> 对 <code>10^9 + 7</code> 取余。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2, m = 3, k = 1
<strong>输出：</strong>6
<strong>解释：</strong>可能的数组分别为 [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 5, m = 2, k = 3
<strong>输出：</strong>0
<strong>解释：</strong>没有数组可以满足上述条件
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 9, m = 1, k = 1
<strong>输出：</strong>1
<strong>解释：</strong>可能的数组只有 [1, 1, 1, 1, 1, 1, 1, 1, 1]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 50, m = 100, k = 25
<strong>输出：</strong>34549172
<strong>解释：</strong>不要忘了对 1000000007 取余
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>n = 37, m = 17, k = 7
<strong>输出：</strong>418930126
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= m &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= n</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    const int mod = 1e9 + 7;

    void add(int& x, int y) {
        x += y;
        if (x >= mod) x -= mod;
    }

    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(51, vector<vector<int>>(101, vector<int>(51, 0)));
        dp[0][0][0] = 1;
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j <= m; j += 1)
                for (int k = 0; k <= i; k += 1)
                    for (int x = 1; x <= m; x += 1)
                        add(dp[i + 1][max(x, j)][k + (x > j)], dp[i][j][k]);
        int ans = 0;
        for (int i = 1; i <= m; i += 1) add(ans, dp[n][i][k]);
        return ans;
    }
};
```




