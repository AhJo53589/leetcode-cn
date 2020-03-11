# `（中等）` [40.combination-sum-ii 组合总和 II](https://leetcode-cn.com/problems/combination-sum-ii/)

### 题目描述
<p>给定一个数组&nbsp;<code>candidates</code>&nbsp;和一个目标数&nbsp;<code>target</code>&nbsp;，找出&nbsp;<code>candidates</code>&nbsp;中所有可以使数字和为&nbsp;<code>target</code>&nbsp;的组合。</p>

<p><code>candidates</code>&nbsp;中的每个数字在每个组合中只能使用一次。</p>

<p><strong>说明：</strong></p>

<ul>
	<li>所有数字（包括目标数）都是正整数。</li>
	<li>解集不能包含重复的组合。&nbsp;</li>
</ul>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> candidates =&nbsp;<code>[10,1,2,7,6,1,5]</code>, target =&nbsp;<code>8</code>,
<strong>所求解集为:</strong>
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> candidates =&nbsp;[2,5,2,1,2], target =&nbsp;5,
<strong>所求解集为:</strong>
[
&nbsp; [1,2,2],
&nbsp; [5]
]</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/combination-sum/solution/39-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    void dfs(int start, int target) 
    {
        if (target == 0) 
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) 
        {
            if (i > start&& candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            // 元素不可重复利用，使用下一个即i+1
            dfs(i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        dfs(0, target);
        return res;
    }

private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
};
```




