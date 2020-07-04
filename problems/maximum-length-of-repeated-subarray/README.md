# `（中等）` [718.maximum-length-of-repeated-subarray 最长重复子数组](https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/)

### 题目描述
<p>给两个整数数组&nbsp;<code>A</code>&nbsp;和&nbsp;<code>B</code>&nbsp;，返回两个数组中公共的、长度最长的子数组的长度。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>
A: [1,2,3,2,1]
B: [3,2,1,4,7]
<strong>输出：</strong>3
<strong>解释：</strong>
长度最长的公共子数组是 [3, 2, 1] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= len(A), len(B) <= 1000</code></li>
	<li><code>0 <= A[i], B[i] < 100</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[i][j] = A[i] == B[j] ? dp[i + 1][j + 1] + 1 : 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
```




