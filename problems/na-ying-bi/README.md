# `（简单）` [LCP 06.na-ying-bi 拿硬币](https://leetcode-cn.com/problems/na-ying-bi/)

[contest](https://leetcode-cn.com/contest/season/2020-spring/problems/na-ying-bi-UGC/)

### 题目描述
<p>桌上有 <code>n</code> 堆力扣币，每堆的数量保存在数组 <code>coins</code> 中。我们每次可以选择任意一堆，拿走其中的一枚或者两枚，求拿完所有力扣币的最少次数。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>[4,2,1]</code></p>

<p>输出：<code>4</code></p>
<p>解释：第一堆力扣币最少需要拿 2 次，第二堆最少需要拿 1 次，第三堆最少需要拿 1 次，总共 4 次即可拿完。</p>
</blockquote>

<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>[2,3,10]</code></p>

<p>输出：<code>8</code></p>
</blockquote>

<p><strong>限制：</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 4</code></li>
	<li><code>1 &lt;= coins[i] &lt;= 10</code></li>
</ul>

---
### 思路
```

```



### 答题
``` C++
class Solution {
public:
    int minCount(vector<int>& coins) 
    {
        int ans = 0;
        for (auto n : coins)
        {
            ans += ((n + 1) / 2);
        }
        return ans;
    }
};
```




