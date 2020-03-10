# `（中等）` [377.combination-sum-iv 组合总和 Ⅳ](https://leetcode-cn.com/problems/combination-sum-iv/)

### 题目描述
<p>给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。</p>

<p><strong>示例:</strong></p>

<pre><em><strong>nums</strong></em> = [1, 2, 3]
<em><strong>target</strong></em> = 4

所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

请注意，顺序不同的序列被视作不同的组合。

因此输出为 <strong>7</strong>。
</pre>

<p><strong>进阶：</strong><br>
如果给定的数组中含有负数会怎么样？<br>
问题会产生什么变化？<br>
我们需要在题目中添加什么限制来允许负数的出现？</p>

<p><strong>致谢：</strong><br>
特别感谢&nbsp;<a href="https://leetcode.com/pbrother/">@pbrother</a>&nbsp;添加此问题并创建所有测试用例。</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/combination-sum-iv/solution/377-by-ikaruga/)

### 答题
``` C++
int combinationSum4(vector<int>& nums, int target) 
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= target; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i < nums[j]) continue;
            dp[i] = (dp[i] >= INT_MAX - dp[i - nums[j]]) ? INT_MAX : dp[i] + dp[i - nums[j]];
        }
    }
    return dp[target];
}

```




