# `（中等）` [216.combination-sum-iii 组合总和 III](https://leetcode-cn.com/problems/combination-sum-iii/)

### 题目描述
<p>找出所有相加之和为&nbsp;<em><strong>n</strong> </em>的&nbsp;<strong><em>k&nbsp;</em></strong>个数的组合<strong><em>。</em></strong>组合中只允许含有 1 -&nbsp;9 的正整数，并且每种组合中不存在重复的数字。</p>

<p><strong>说明：</strong></p>

<ul>
	<li>所有数字都是正整数。</li>
	<li>解集不能包含重复的组合。&nbsp;</li>
</ul>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <em><strong>k</strong></em> = 3, <em><strong>n</strong></em> = 7
<strong>输出:</strong> [[1,2,4]]
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> <em><strong>k</strong></em> = 3, <em><strong>n</strong></em> = 9
<strong>输出:</strong> [[1,2,6], [1,3,5], [2,3,4]]
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/combination-sum-iii/solution/216-by-ikaruga-2/)

### 答题
``` C++
void dfs(int k, int sum, int idx, vector<int>& cur, vector<vector<int>>& ans)
{
    if (k == 0 && sum == 0)
    {
        //sort(cur.begin(), cur.end());
        ans.push_back(cur);
        return;
    }
    if (k == 0 || sum == 0) return;
        
    if (idx < 0) return;
    if (sum >= idx)
    {
        cur.push_back(idx);
        dfs(k - 1, sum - idx, idx - 1, cur, ans);
        cur.pop_back();
    }

    dfs(k, sum, idx - 1, cur, ans);
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> cur;
    dfs(k, n, 9, cur, ans);
    return ans;
}
```




