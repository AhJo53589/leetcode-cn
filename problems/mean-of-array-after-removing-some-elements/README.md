# `（简单）` [1619.mean-of-array-after-removing-some-elements 删除某些元素后的数组均值](https://leetcode-cn.com/problems/mean-of-array-after-removing-some-elements/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-37/problems/mean-of-array-after-removing-some-elements/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>arr</code>&nbsp;，请你删除最小&nbsp;<code>5%</code>&nbsp;的数字和最大 <code>5%</code>&nbsp;的数字后，剩余数字的平均值。</p>

<p>与 <strong>标准答案</strong>&nbsp;误差在&nbsp;<code>10<sup>-5</sup></code>&nbsp;的结果都被视为正确结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
<b>输出：</b>2.00000
<b>解释：</b>删除数组中最大和最小的元素后，所有元素都等于 2，所以平均值为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>arr = [6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]
<b>输出：</b>4.00000
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>arr = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4]
<b>输出：</b>4.77778
</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>arr = [9,7,8,7,7,8,4,4,6,8,8,7,6,8,8,9,2,6,0,0,1,10,8,6,3,3,5,1,10,9,0,7,10,0,10,4,1,10,6,9,3,6,0,0,2,7,0,6,7,2,9,7,7,3,0,1,6,1,10,3]
<b>输出：</b>5.27778
</pre>

<p><strong>示例 5：</strong></p>

<pre><b>输入：</b>arr = [4,8,4,10,0,7,1,3,7,8,8,3,4,1,6,2,1,1,8,0,9,8,0,3,9,10,3,10,1,10,7,3,2,1,4,9,10,7,6,4,0,8,5,1,2,1,6,2,5,0,7,10,9,10,3,7,10,5,8,5,7,6,7,6,10,9,5,10,5,5,7,2,10,7,7,8,2,0,1,1]
<b>输出：</b>5.29167
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>20 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>arr.length</code><b>&nbsp;</b>是&nbsp;<code>20</code>&nbsp;的<strong>&nbsp;倍数</strong>&nbsp;</li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    double trimMean(vector<int>& arr) {
        int d = arr.size() / 20;
        sort(arr.begin(), arr.end());
        long long sum = 0;
        for (int i = d; i < arr.size() - d; i++) {
            sum += arr[i];
        }
        double ans = (double)sum / (double)(arr.size() - d - d);
        return ans;
    }
};
```




