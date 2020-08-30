# `（简单）` [5499.detect-pattern-of-length-m-repeated-k-or-more-times 重复至少 K 次且长度为 M 的模式](https://leetcode-cn.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/)

[contest](https://leetcode-cn.com/contest/weekly-contest-204/problems/detect-pattern-of-length-m-repeated-k-or-more-times/)

### 题目描述
<p>给你一个正整数数组 <code>arr</code>，请你找出一个长度为 <code>m</code> 且在数组中至少重复 <code>k</code> 次的模式。</p>

<p><strong>模式</strong> 是由一个或多个值组成的子数组（连续的子序列），<strong>连续</strong> 重复多次但 <strong>不重叠</strong> 。 模式由其长度和重复次数定义。</p>

<p>如果数组中存在至少重复 <code>k</code> 次且长度为 <code>m</code> 的模式，则返回 <code>true</code> ，否则返回&nbsp; <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,4,4,4,4], m = 1, k = 3
<strong>输出：</strong>true
<strong>解释：</strong>模式 <strong>(4)</strong> 的长度为 1 ，且连续重复 4 次。注意，模式可以重复 k 次或更多次，但不能少于 k 次。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,1,2,1,1,1,3], m = 2, k = 2
<strong>输出：</strong>true
<strong>解释：</strong>模式 <strong>(1,2)</strong> 长度为 2 ，且连续重复 2 次。另一个符合题意的模式是 <strong>(2,1) </strong>，同样重复 2 次。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,1,2,1,3], m = 2, k = 3
<strong>输出：</strong>false
<strong>解释：</strong>模式 <strong>(1,2)</strong> 长度为 2 ，但是只连续重复 2 次。不存在长度为 2 且至少重复 3 次的模式。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,3,1,2], m = 2, k = 2
<strong>输出：</strong>false
<strong>解释：</strong>模式 <strong>(1,2)</strong> 出现 2 次但并不连续，所以不能算作连续重复 2 次。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [2,2,2,2], m = 2, k = 3
<strong>输出：</strong>false
<strong>解释：</strong>长度为 2 的模式只有 <strong>(2,2)</strong> ，但是只连续重复 2 次。注意，不能计算重叠的重复次数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= arr.length <= 100</code></li>
	<li><code>1 <= arr[i] <= 100</code></li>
	<li><code>1 <= m&nbsp;<= 100</code></li>
	<li><code>2 <= k&nbsp;<= 100</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/solution/detect-pattern-of-length-m-by-ikaruga/)

### 答题
``` C++
    bool containsPattern(vector<int>& arr, int m, int k) {
        for (int i = 0; i < arr.size(); i++) {
            bool f = true;
            for (int t = 0; t < m && f; t++) {
                for (int j = 0; j < k && f; j++) {
                    int nxt = i + j * m + t;
                    if (nxt >= arr.size() || arr[i + t] != arr[nxt]) {
                        f = false;
                    }
                }
            }
            if (f) return true;
        }
        return false;
    }
```




