# `（中等）` [1696.jump-game-vi 跳跃游戏 VI](https://leetcode-cn.com/problems/jump-game-vi/)

[contest](https://leetcode-cn.com/contest/weekly-contest-220/problems/jump-game-vi/)

### 题目描述
<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code>&nbsp;和一个整数 <code>k</code>&nbsp;。</p>

<p>一开始你在下标&nbsp;<code>0</code>&nbsp;处。每一步，你最多可以往前跳&nbsp;<code>k</code>&nbsp;步，但你不能跳出数组的边界。也就是说，你可以从下标&nbsp;<code>i</code>&nbsp;跳到&nbsp;<code>[i + 1， min(n - 1, i + k)]</code>&nbsp;<strong>包含</strong> 两个端点的任意位置。</p>

<p>你的目标是到达数组最后一个位置（下标为 <code>n - 1</code>&nbsp;），你的 <strong>得分</strong>&nbsp;为经过的所有数字之和。</p>

<p>请你返回你能得到的 <strong>最大得分</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [<strong>1</strong>,<strong>-1</strong>,-2,<strong>4</strong>,-7,<strong>3</strong>], k = 2
<b>输出：</b>7
<b>解释：</b>你可以选择子序列 [1,-1,4,3] （上面加粗的数字），和为 7 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [<strong>10</strong>,-5,-2,<strong>4</strong>,0,<strong>3</strong>], k = 3
<b>输出：</b>17
<b>解释：</b>你可以选择子序列 [10,4,3] （上面加粗数字），和为 17 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
<b>输出：</b>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>&nbsp;<code>1 &lt;= nums.length, k &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= nums[i]&nbsp;&lt;= 10<sup>4</sup></code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/jump-game-vi/solution/jump-game-vi-by-ikaruga-fz5c/)

### 答题
``` C++
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        dq.push_back({nums[0], 0});

        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            while (!dq.empty() && i - dq.front().second > k) {
                dq.pop_front();
            }
            ans = dq.front().first + nums[i];
            while (!dq.empty() && dq.back().first <= ans) {
                dq.pop_back();
            }
            dq.push_back({ans, i});
        }
        return ans;
    }
};
```




