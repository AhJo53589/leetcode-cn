# `（简单）` [5452.can-make-arithmetic-progression-from-sequence 判断能否形成等差数列](https://leetcode-cn.com/problems/can-make-arithmetic-progression-from-sequence/)

[contest](https://leetcode-cn.com/contest/weekly-contest-196/problems/can-make-arithmetic-progression-from-sequence/)

### 题目描述
<p>给你一个数字数组 <code>arr</code> 。</p>

<p>如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 <strong>等差数列</strong> 。</p>

<p>如果可以重新排列数组形成等差数列，请返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [3,5,1]
<strong>输出：</strong>true
<strong>解释：</strong>对数组重新排序得到 [1,3,5] 或者 [5,3,1] ，任意相邻两项的差分别为 2 或 -2 ，可以形成等差数列。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,4]
<strong>输出：</strong>false
<strong>解释：</strong>无法通过重新排序得到等差数列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= arr.length <= 1000</code></li>
	<li><code>-10^6 <= arr[i] <= 10^6</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		int ans = arr[1] - arr[0];
		for (int i = 2; i < arr.size(); i++) {
			if (ans != arr[i] - arr[i - 1]) return false;
		}
		return true;
    }
};
```




