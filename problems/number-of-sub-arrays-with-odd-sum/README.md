# `（中等）` [5457.number-of-sub-arrays-with-odd-sum 和为奇数的子数组数目](https://leetcode-cn.com/problems/number-of-sub-arrays-with-odd-sum/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-31/problems/number-of-sub-arrays-with-odd-sum/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>arr</code>&nbsp;。请你返回和为 <strong>奇数</strong>&nbsp;的子数组数目。</p>

<p>由于答案可能会很大，请你将结果对&nbsp;<code>10^9 + 7</code>&nbsp;取余后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [1,3,5]
<strong>输出：</strong>4
<strong>解释：</strong>所有的子数组为 [[1],[1,3],[1,3,5],[3],[3,5],[5]] 。
所有子数组的和为 [1,4,9,3,8,5].
奇数和包括 [1,9,3,5] ，所以答案为 4 。
</pre>

<p><strong>示例 2 ：</strong></p>

<pre><strong>输入：</strong>arr = [2,4,6]
<strong>输出：</strong>0
<strong>解释：</strong>所有子数组为 [[2],[2,4],[2,4,6],[4],[4,6],[6]] 。
所有子数组和为 [2,6,12,4,10,6] 。
所有子数组和都是偶数，所以答案为 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,3,4,5,6,7]
<strong>输出：</strong>16
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [100,100,99,99]
<strong>输出：</strong>4
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [7]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 100</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int> pre(arr.size(), 0);
        pre[0] = arr[0];
        int odd = 0;
        int even = 1;
        int ans = 0;
        if (pre[0] % 2 == 1) {
            ans = 1;
            odd = 1;
        }
        else {
            even++;
        }

        for (int i = 1; i < arr.size(); i++) {
            pre[i] = pre[i - 1] + arr[i];
            if (pre[i] % 2 == 1) {
                ans += even;
                odd++;
            }
            else {
                ans += odd;
                even++;
            }
            ans %= mod;
        }
        return ans;
    }
private:
    const int mod = 1e9 + 7;
};

```




