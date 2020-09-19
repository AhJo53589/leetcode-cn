# `（简单）` [LCP 22.ccw6C7 黑白方格画](https://leetcode-cn.com/problems/ccw6C7/)

### 题目描述
<p>小扣注意到秋日市集上有一个创作黑白方格画的摊位。摊主给每个顾客提供一个固定在墙上的白色画板，画板不能转动。画板上有 <code>n * n</code> 的网格。绘画规则为，小扣可以选择任意多行以及任意多列的格子涂成黑色，所选行数、列数均可为 0。</p>
<p>小扣希望最终的成品上需要有 <code>k</code> 个黑色格子，请返回小扣共有多少种涂色方案。</p>
<p>注意：两个方案中任意一个相同位置的格子颜色不同，就视为不同的方案。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>n = 2, k = 2</code></p>
<p>输出：<code>4</code></p>
<p>解释：一共有四种不同的方案：<br>
第一种方案：涂第一列；<br>
第二种方案：涂第二列；<br>
第三种方案：涂第一行；<br>
第四种方案：涂第二行。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>n = 2, k = 1</code></p>
<p>输出：<code>0</code></p>
<p>解释：不可行，因为第一次涂色至少会涂两个黑格。</p>
</blockquote>
<p><strong>示例 3：</strong></p>
<blockquote>
<p>输入：<code>n = 2, k = 4</code></p>
<p>输出：<code>1</code></p>
<p>解释：共有 2*2=4 个格子，仅有一种涂色方案。</p>
</blockquote>
<p><strong>限制：</strong></p>
<ul>
<li><code>1 &lt;= n &lt;= 6</code></li>
<li><code>0 &lt;= k &lt;= n * n</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int paintingPlan(int n, int k) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (calc(n, i, j) == k) {
                    ans += cnm(n, i) * cnm(n, j);
                }
            }
        }
        ans += (calc(n, 0, n) == k);
        return ans;
    }

    int calc(int n, int i, int j) {
        return (i + j) * n - i * j;
    }

    int cnm(int n, int m) {
        if (m == 0) return 1;
        if (m == n) return 1;
        if (m > n / 2) return cnm(n, n - m);
        int a = 1;
        for (int i = 0; i < m; i++) a *= (n - i);
        int b = 1;
        for (int i = m; i > 0; i--) b *= i;
        return a / b;
    }
};
```




