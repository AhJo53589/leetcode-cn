# `（中等）` [486.predict-the-winner 预测赢家](https://leetcode-cn.com/problems/predict-the-winner/)

### 题目描述
<p>给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。</p>

<p>给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[1, 5, 2]
<strong>输出：</strong>False
<strong>解释：</strong>一开始，玩家1可以从1和2中进行选择。
如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下 1（或者 2 ）可选。
所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。
因此，玩家 1 永远不会成为赢家，返回 False 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[1, 5, 233, 7]
<strong>输出：</strong>True
<strong>解释：</strong>玩家 1 一开始选择 1 。然后玩家 2 必须从 5 和 7 中进行选择。无论玩家 2 选择了哪个，玩家 1 都可以选择 233 。
     最终，玩家 1（234 分）比玩家 2（12 分）获得更多的分数，所以返回 True，表示玩家 1 可以成为赢家。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>1 &lt;= 给定的数组长度&nbsp;&lt;= 20.</li>
	<li>数组里所有分数都为非负数且不会大于 10000000 。</li>
	<li>如果最终两个玩家的分数相等，那么玩家 1 仍为赢家。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        dp = vector<vector<int>>(nums.size(), vector<int>(nums.size(), 0));
        vi = vector<vector<bool>>(nums.size(), vector<bool>(nums.size(), false));
        int ans = dfs(nums, 0, nums.size() - 1);
        return ans >= 0;
    }

    int dfs(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        if (vi[left][right]) return dp[left][right];
        int n = max(nums[left] - dfs(nums, left + 1, right), nums[right] - dfs(nums, left, right - 1));
        dp[left][right] = n;
        return n;
    }

private:
    vector<vector<int>> dp;
    vector<vector<bool>> vi;
};
```




