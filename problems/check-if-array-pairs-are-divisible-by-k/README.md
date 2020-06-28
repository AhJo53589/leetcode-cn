# `（中等）` [5449.check-if-array-pairs-are-divisible-by-k 检查数组对是否可以被 k 整除](https://leetcode-cn.com/problems/check-if-array-pairs-are-divisible-by-k/)

[contest](https://leetcode-cn.com/contest/weekly-contest-195/problems/check-if-array-pairs-are-divisible-by-k/)

### 题目描述
<p>给你一个整数数组 <code>arr</code> 和一个整数 <code>k</code> ，其中数组长度是偶数，值为 <code>n</code> 。</p>

<p>现在需要把数组恰好分成 <code>n /&nbsp;2</code> 对，以使每对数字的和都能够被 <code>k</code> 整除。</p>

<p>如果存在这样的分法，请返回 <em>True</em> ；否则，返回 <em>False</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,3,4,5,10,6,7,8,9], k = 5
<strong>输出：</strong>true
<strong>解释：</strong>划分后的数字对为 (1,9),(2,8),(3,7),(4,6) 以及 (5,10) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,3,4,5,6], k = 7
<strong>输出：</strong>true
<strong>解释：</strong>划分后的数字对为 (1,6),(2,5) 以及 (3,4) 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,3,4,5,6], k = 10
<strong>输出：</strong>false
<strong>解释：</strong>无法在将数组中的数字分为三对的同时满足每对数字和能够被 10 整除的条件。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [-10,10], k = 2
<strong>输出：</strong>true
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [-1,1,-2,2,-3,3,-4,4], k = 3
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>arr.length == n</code></li>
	<li><code>1 <= n <= 10^5</code></li>
	<li><code>n</code> 为偶数</li>
	<li><code>-10^9 <= arr[i] <= 10^9</code></li>
	<li><code>1 <= k <= 10^5</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> a(k, 0);
        for (auto n : arr) {
            if (n < 0) {
                n *= -1;
                n %= k;
                n = k - n;
            }
            a[n % k]++;
        }

        if (a[0] % 2 != 0) return false;
        int i = 1;
        int j = a.size() - 1;
        while (i < j) {
            if (a[i] != a[j]) return false;
            i++;
            j--;
        }
        if (i == j && a[i] % 2 != 0) return false;
        return true;
    }
};
```




