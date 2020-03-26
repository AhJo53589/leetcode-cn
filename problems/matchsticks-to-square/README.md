# `（中等）` [473.matchsticks-to-square 火柴拼正方形](https://leetcode-cn.com/problems/matchsticks-to-square/)

### 题目描述
<p>还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。</p>

<p>输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> [1,1,2,2,2]
<strong>输出:</strong> true

<strong>解释:</strong> 能拼成一个边长为2的正方形，每边两根火柴。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> [3,3,3,3,4]
<strong>输出:</strong> false

<strong>解释:</strong> 不能用所有火柴拼成一个正方形。
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li>给定的火柴长度和在&nbsp;<code>0</code>&nbsp;到&nbsp;<code>10^9</code>之间。</li>
	<li>火柴数组的长度不超过15。</li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/matchsticks-to-square/solution/matchsticks-to-square-by-ikaruga/)

### 答题
``` C++
bool dfs(vector<int>& nums, vector<bool>& vi, int idx, int sum)
{
    if (sum == 0) return true;
    if (idx < 0) return false;

    for (int i = idx; i >= 0; i--)
    {
        if (vi[i]) continue;
        if (sum < nums[i]) continue;

        vi[i] = true;
        if (dfs(nums, vi, i - 1, sum - nums[i])) return true;
        vi[i] = false;
    }
    return false;
}

bool makesquare(vector<int>& nums) 
{
    if (nums.size() < 4) return false;
    sort(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 4 != 0) return false;
    sum /= 4;
        
    vector<bool> vi(nums.size(), false);
    for (int i = 0; i < 4; i++)
    {
        if (!dfs(nums, vi, nums.size() - 1, sum)) return false;
    }
    return true;
}
```




