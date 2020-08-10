# `（中等）` [1509.minimum-difference-between-largest-and-smallest-value-in-three-moves 三次操作后最大值与最小值的最小差](https://leetcode-cn.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-30/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/)

### 题目描述
<p>给你一个数组&nbsp;<code>nums</code>&nbsp;，每次操作你可以选择&nbsp;<code>nums</code>&nbsp;中的任意一个数字并将它改成任意值。</p>

<p>请你返回三次操作后， <code>nums</code>&nbsp;中最大值与最小值的差的最小值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [5,3,2,4]
<strong>输出：</strong>0
<strong>解释：</strong>将数组 [5,3,2,4] 变成 [<strong>2</strong>,<strong>2</strong>,2,<strong>2</strong>].
最大值与最小值的差为 2-2 = 0 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,5,0,10,14]
<strong>输出：</strong>1
<strong>解释：</strong>将数组 [1,5,0,10,14] 变成 [1,<strong>1</strong>,0,<strong>1</strong>,<strong>1</strong>] 。
最大值与最小值的差为 1-0 = 1 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [6,6,0,1,1,4,6]
<strong>输出：</strong>2
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [1,5,6,14,15]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10^5</code></li>
	<li><code>-10^9 <= nums[i] <= 10^9</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/solution/minimum-difference-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() < 5) return 0;

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;
        for (int i = 0; i <= 3; i++) {
            ans = min(ans, nums[nums.size() - 1 - (3 - i)] - nums[i]);
        }
        return ans;
    }
};
```




