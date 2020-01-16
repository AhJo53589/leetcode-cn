# `（中等）` [96.unique-binary-search-trees 不同的二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)

### 题目描述
<p>给定一个整数 <em>n</em>，求以&nbsp;1 ...&nbsp;<em>n</em>&nbsp;为节点组成的二叉搜索树有多少种？</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 3
<strong>输出:</strong> 5
<strong>解释:
</strong>给定 <em>n</em> = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3</pre>


---
### 思路
```
```



### 答题
``` C++
int numTrees(int n) 
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}
```




