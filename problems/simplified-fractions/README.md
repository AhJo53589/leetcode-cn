# `（中等）` [1447.simplified-fractions 最简分数](https://leetcode-cn.com/problems/simplified-fractions/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-26/problems/simplified-fractions/)

### 题目描述
<p>给你一个整数&nbsp;<code>n</code>&nbsp;，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于&nbsp;&nbsp;<code>n</code>&nbsp;的 <strong>最简&nbsp;</strong>分数&nbsp;。分数可以以 <strong>任意&nbsp;</strong>顺序返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>["1/2"]
<strong>解释：</strong>"1/2" 是唯一一个分母小于等于 2 的最简分数。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 3
<strong>输出：</strong>["1/2","1/3","2/3"]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 4
<strong>输出：</strong>["1/2","1/3","1/4","2/3","3/4"]
<strong>解释：</strong>"2/4" 不是最简分数，因为它可以化简为 "1/2" 。</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 1
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (gcd(i, j) != 1) continue;
                ans.push_back(to_string(j) + "/" + to_string(i));
            }
        }
        return ans;
    }
};
```




