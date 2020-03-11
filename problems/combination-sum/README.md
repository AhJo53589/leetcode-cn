# `（中等）` [39.combination-sum 组合总和](https://leetcode-cn.com/problems/combination-sum/)

### 题目描述
<p>给定一个<strong>无重复元素</strong>的数组&nbsp;<code>candidates</code>&nbsp;和一个目标数&nbsp;<code>target</code>&nbsp;，找出&nbsp;<code>candidates</code>&nbsp;中所有可以使数字和为&nbsp;<code>target</code>&nbsp;的组合。</p>

<p><code>candidates</code>&nbsp;中的数字可以无限制重复被选取。</p>

<p><strong>说明：</strong></p>

<ul>
	<li>所有数字（包括&nbsp;<code>target</code>）都是正整数。</li>
	<li>解集不能包含重复的组合。&nbsp;</li>
</ul>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> candidates = <code>[2,3,6,7], </code>target = <code>7</code>,
<strong>所求解集为:</strong>
[
  [7],
  [2,2,3]
]
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> candidates = [2,3,5]<code>, </code>target = 8,
<strong>所求解集为:</strong>
[
&nbsp; [2,2,2,2],
&nbsp; [2,3,3],
&nbsp; [3,5]
]</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/combination-sum/solution/39-by-ikaruga/)

### 答题
``` C++
void dfs(vector<int>& candidates, int target, int idx, vector<int>& cur, vector<vector<int>>& ans)
{
    if (target == 0)
    {
        ans.push_back(cur);
        return;
    }
    if (idx >= candidates.size()) return;

    dfs(candidates, target, idx + 1, cur, ans); // k == 0
    for (int k = 1; k <= target / candidates[idx]; k++)
    {
        cur.push_back(candidates[idx]);
        dfs(candidates, target - k * candidates[idx], idx + 1, cur, ans);
    }
    for (int k = 1; k <= target / candidates[idx]; k++)
    {
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> cur;
    dfs(candidates, target, 0, cur, ans);
    return ans;
}
```




