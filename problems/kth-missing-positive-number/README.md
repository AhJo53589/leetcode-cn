# `（简单）` [1539.kth-missing-positive-number 第 k 个缺失的正整数](https://leetcode-cn.com/problems/kth-missing-positive-number/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-32/problems/kth-missing-positive-number/)

### 题目描述
<p>给你一个 <strong>严格升序排列</strong>&nbsp;的正整数数组 <code>arr</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>请你找到这个数组里第&nbsp;<code>k</code>&nbsp;个缺失的正整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [2,3,4,7,11], k = 5
<strong>输出：</strong>9
<strong>解释：</strong>缺失的正整数包括 [1,5,6,8,9,10,12,13,...] 。第 5 个缺失的正整数为 9 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,3,4], k = 2
<strong>输出：</strong>6
<strong>解释：</strong>缺失的正整数包括 [5,6,7,...] 。第 2 个缺失的正整数为 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 1000</code></li>
	<li><code>1 <= arr[i] <= 1000</code></li>
	<li><code>1 <= k <= 1000</code></li>
	<li>对于所有&nbsp;<code>1 <= i < j <= arr.length</code>&nbsp;的 <code>i</code>&nbsp;和 <code>j</code> 满足&nbsp;<code>arr[i] < arr[j]</code>&nbsp;</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = 0;
        for (auto a : arr) {
            while (++n != a) {
                if (--k == 0) return n;
            }
        }
        while (k-- != 0) {
            ++n;
        }
        return n;
    }
};
```




