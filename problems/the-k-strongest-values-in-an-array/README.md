# `（中等）` [1471.the-k-strongest-values-in-an-array 数组中的 k 个最强值](https://leetcode-cn.com/problems/the-k-strongest-values-in-an-array/)

[contest](https://leetcode-cn.com/contest/weekly-contest-192/problems/the-k-strongest-values-in-an-array/)

### 题目描述
<p>给你一个整数数组 <code>arr</code> 和一个整数 <code>k</code> 。</p>

<p>设 <code>m</code> 为数组的中位数，只要满足下述两个前提之一，就可以判定 <code>arr[i]</code> 的值比 <code>arr[j]</code> 的值更强：</p>

<ul>
	<li>&nbsp;<code>|arr[i] - m| > |arr[j]&nbsp;- m|</code></li>
	<li>&nbsp;<code>|arr[i] - m| == |arr[j] - m|</code>，且 <code>arr[i] > arr[j]</code></li>
</ul>

<p>请返回由数组中最强的 <code>k</code> 个值组成的列表。答案可以以 <strong>任意顺序</strong> 返回。</p>

<p><strong>中位数</strong> 是一个有序整数列表中处于中间位置的值。形式上，如果列表的长度为 <code>n</code> ，那么中位数就是该有序列表（下标从 0 开始）中位于 <code>((n - 1) / 2)</code> 的元素。</p>

<ul>
	<li>例如 <code>arr =&nbsp;[6, -3, 7, 2, 11]</code>，<code>n = 5</code>：数组排序后得到 <code>arr = [-3, 2, 6, 7, 11]</code> ，数组的中间位置为 <code>m = ((5 - 1) / 2) = 2</code> ，中位数 <code>arr[m]</code> 的值为 <code>6</code> 。</li>
	<li>例如 <code>arr =&nbsp;[-7, 22, 17, 3]</code>，<code>n = 4</code>：数组排序后得到&nbsp;<code>arr = [-7, 3, 17, 22]</code> ，数组的中间位置为&nbsp;<code>m = ((4 - 1) / 2) = 1</code> ，中位数 <code>arr[m]</code> 的值为 <code>3</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,3,4,5], k = 2
<strong>输出：</strong>[5,1]
<strong>解释：</strong>中位数为 3，按从强到弱顺序排序后，数组变为 [5,1,4,2,3]。最强的两个元素是 [5, 1]。[1, 5] 也是正确答案。
注意，尽管 |5 - 3| == |1 - 3| ，但是 5 比 1 更强，因为 5 > 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,1,3,5,5], k = 2
<strong>输出：</strong>[5,5]
<strong>解释：</strong>中位数为 3, 按从强到弱顺序排序后，数组变为 [5,5,1,1,3]。最强的两个元素是 [5, 5]。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [6,7,11,7,6,8], k = 5
<strong>输出：</strong>[11,8,6,6,7]
<strong>解释：</strong>中位数为 7, 按从强到弱顺序排序后，数组变为 [11,8,6,6,7,7]。
[11,8,6,6,7] 的任何排列都是正确答案。</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [6,-3,7,2,11], k = 3
<strong>输出：</strong>[-3,11,2]
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [-7,22,17,3], k = 2
<strong>输出：</strong>[22,17]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 10^5</code></li>
	<li><code>-10^5 <= arr[i] <= 10^5</code></li>
	<li><code>1 <= k <= arr.length</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int m = arr[(arr.size() - 1) / 2];

        sort(arr.begin(), arr.end(), [m](const int& a, const int& b) {
            if (abs(a - m) == abs(b - m)) return a > b;
            return (abs(a - m) > abs(b - m));
        });

        vector<int> ans(k, 0);
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = arr[i];
        }
        return ans;
    }
```




