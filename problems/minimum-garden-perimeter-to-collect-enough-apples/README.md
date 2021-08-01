# `（中等）` [5187.minimum-garden-perimeter-to-collect-enough-apples 收集足够苹果的最小花园周长](https://leetcode-cn.com/problems/minimum-garden-perimeter-to-collect-enough-apples/)

[contest](https://leetcode-cn.com/contest/weekly-contest-252/problems/minimum-garden-perimeter-to-collect-enough-apples/)

### 题目描述
<div class="notranslate"><p>给你一个用无限二维网格表示的花园，<strong>每一个</strong>&nbsp;整数坐标处都有一棵苹果树。整数坐标&nbsp;<code>(i, j)</code>&nbsp;处的苹果树有 <code>|i| + |j|</code>&nbsp;个苹果。</p>

<p>你将会买下正中心坐标是 <code>(0, 0)</code>&nbsp;的一块 <strong>正方形土地</strong>&nbsp;，且每条边都与两条坐标轴之一平行。</p>

<p>给你一个整数&nbsp;<code>neededApples</code>&nbsp;，请你返回土地的&nbsp;<strong>最小周长</strong>&nbsp;，使得&nbsp;<strong>至少</strong>&nbsp;有<strong>&nbsp;</strong><code>neededApples</code>&nbsp;个苹果在土地&nbsp;<strong>里面或者边缘上</strong>。</p>

<p><code>|x|</code>&nbsp;的值定义为：</p>

<ul>
	<li>如果&nbsp;<code>x &gt;= 0</code>&nbsp;，那么值为&nbsp;<code>x</code></li>
	<li>如果&nbsp;<code>x &lt;&nbsp;0</code>&nbsp;，那么值为&nbsp;<code>-x</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 442px; height: 449px;" src="https://pic.leetcode-cn.com/1627790803-qcBKFw-image.png" alt="">
<pre><b>输入：</b>neededApples = 1
<b>输出：</b>8
<b>解释：</b>边长长度为 1 的正方形不包含任何苹果。
但是边长为 2 的正方形包含 12 个苹果（如上图所示）。
周长为 2 * 4 = 8 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>neededApples = 13
<b>输出：</b>16
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>neededApples = 1000000000
<b>输出：</b>5040
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= neededApples &lt;= 10<sup>15</sup></code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-garden-perimeter-to-collect-enough-apples/solution/minimum-garden-perimeter-to-collect-enou-i8ax/)

### 答题
``` C++
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long apples = 0;
        for (int x = 0; x < INT_MAX; x++) {
            apples += calc(x);
            if (apples >= neededApples) {
                return x * 2 * 4;
            }
        }
        return 0;
    }

    long long calc(int x) {
        long long a = x + 1;
        long long b = 2 * x - 1;
        long long side = (a <= b) ? (a + b) * (b - a + 1) / 2 : 0;
        return 4LL * x + 4LL * 2 * x + side * 8;
    }
};
```




