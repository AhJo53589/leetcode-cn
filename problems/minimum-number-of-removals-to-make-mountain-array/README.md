# `（困难）` [5559.minimum-number-of-removals-to-make-mountain-array 得到山形数组的最少删除次数](https://leetcode-cn.com/problems/minimum-number-of-removals-to-make-mountain-array/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-40/problems/minimum-number-of-removals-to-make-mountain-array/)

### 题目描述
<div class="question-content default-content">
              <p>我们定义&nbsp;<code>arr</code>&nbsp;是 <b>山形数组</b>&nbsp;当且仅当它满足：</p>

<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>存在某个下标&nbsp;<code>i</code>&nbsp;（<strong>从 0 开始</strong>）&nbsp;满足&nbsp;<code>0 &lt; i &lt; arr.length - 1</code>&nbsp;且：
	<ul>
		<li><code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i]</code></li>
		<li><code>arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code></li>
	</ul>
	</li>
</ul>

<p>给你整数数组&nbsp;<code>nums</code>​ ，请你返回将 <code>nums</code>&nbsp;变成 <strong>山形状数组</strong>&nbsp;的​ <strong>最少</strong>&nbsp;删除次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,3,1]
<b>输出：</b>0
<b>解释：</b>数组本身就是山形数组，所以我们不需要删除任何元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,1,1,5,6,2,3,1]
<b>输出：</b>3
<b>解释：</b>一种方法是将下标为 0，1 和 5 的元素删除，剩余元素为 [1,5,6,3,1] ，是山形数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [4,3,2,1,1,2,3,1]
<b>输出：</b>4
</pre>

<p><strong>提示：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4,4,3,2,1]
<b>输出：</b>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>题目保证&nbsp;<code>nums</code> 删除一些元素后一定能得到山形数组。</li>
</ul>

            </div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(nums.size(), 0));
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[0][i] = max(dp[0][i], dp[0][j] + 1);

                }
            }
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            for (int j = nums.size() - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    dp[1][i] = max(dp[1][i], dp[1][j] + 1);
                }
            }
        }

        int t = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            t = max(t, dp[0][i] + dp[1][i] + 1);
        }
        return nums.size() - t;
    }
};
```




