# `（简单）` [LCP 17.nGK0Fy 速算机器人](https://leetcode-cn.com/problems/nGK0Fy/)

### 题目描述
<p>小扣在秋日市集发现了一款速算机器人。店家对机器人说出两个数字（记作 <code>x</code> 和 <code>y</code>），请小扣说出计算指令：</p>
<ul>
<li><code>"A"</code> 运算：使 <code>x = 2 * x + y</code>；</li>
<li><code>"B"</code> 运算：使 <code>y = 2 * y + x</code>。</li>
</ul>
<p>在本次游戏中，店家说出的数字为 <code>x = 1</code> 和 <code>y = 0</code>，小扣说出的计算指令记作仅由大写字母 <code>A</code>、<code>B</code> 组成的字符串 <code>s</code>，字符串中字符的顺序表示计算顺序，请返回最终 <code>x</code> 与 <code>y</code> 的和为多少。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>s = "AB"</code></p>
<p>输出：<code>4</code></p>
<p>解释：<br>
经过一次 A 运算后，x = 2, y = 0。<br>
再经过一次 B 运算，x = 2, y = 2。<br>
最终 x 与 y 之和为 4。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>0 &lt;= s.length &lt;= 10</code></li>
<li><code>s</code> 由 <code>'A'</code> 和 <code>'B'</code> 组成</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int calculate(string s) {
        int x = 1;
        int y = 0;
        for (auto c : s) {
            if (c == 'A') {
                x = 2 * x + y;
            }
            else if (c == 'B') {
                y = 2 * y + x;
            }
        }
        return x + y;
    }
};
```




