# `（中等）` [1014.best-sightseeing-pair 最佳观光组合](https://leetcode-cn.com/problems/best-sightseeing-pair/)

### 题目描述
<p>给定正整数数组&nbsp;<code>A</code>，<code>A[i]</code>&nbsp;表示第 <code>i</code> 个观光景点的评分，并且两个景点&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;之间的距离为&nbsp;<code>j - i</code>。</p>

<p>一对景点（<code>i < j</code>）组成的观光组合的得分为（<code>A[i] + A[j] + i&nbsp;- j</code>）：景点的评分之和<strong>减去</strong>它们两者之间的距离。</p>

<p>返回一对观光景点能取得的最高分。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>[8,1,5,2,6]
<strong>输出：</strong>11
<strong>解释：</strong>i = 0, j = 2, <code>A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>2 <= A.length <= 50000</code></li>
	<li><code>1 <= A[i] <= 1000</code></li>
</ol>


---
### 思路
```
```



### 答题
``` C++
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = 0;
        int maxIndex = 0;
        for (int i = 1; i < A.size(); i++) {
            ans = max(ans, A[i] + A[maxIndex] - i + maxIndex);
            maxIndex = (A[maxIndex] + maxIndex <= A[i] + i) ? i : maxIndex;
        }
        return ans;
    }
```




