# `（中等）` [5868.number-of-pairs-of-interchangeable-rectangles 可互换矩形的组数](https://leetcode-cn.com/problems/number-of-pairs-of-interchangeable-rectangles/)

[contest](https://leetcode-cn.com/contest/weekly-contest-258/problems/number-of-pairs-of-interchangeable-rectangles/)

### 题目描述
<div class="notranslate"><p>用一个下标从 <strong>0</strong> 开始的二维整数数组&nbsp;<code>rectangles</code> 来表示 <code>n</code> 个矩形，其中 <code>rectangles[i] = [width<sub>i</sub>, height<sub>i</sub>]</code> 表示第 <code>i</code> 个矩形的宽度和高度。</p>

<p>如果两个矩形 <code>i</code> 和 <code>j</code>（<code>i &lt; j</code>）的宽高比相同，则认为这两个矩形 <strong>可互换</strong> 。更规范的说法是，两个矩形满足&nbsp;<code>width<sub>i</sub>/height<sub>i</sub> == width<sub>j</sub>/height<sub>j</sub></code>（使用实数除法而非整数除法），则认为这两个矩形 <strong>可互换</strong> 。</p>

<p>计算并返回&nbsp;<code>rectangles</code> 中有多少对 <strong>可互换 </strong>矩形。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>rectangles = [[4,8],[3,6],[10,20],[15,30]]
<strong>输出：</strong>6
<strong>解释：</strong>下面按下标（从 0 开始）列出可互换矩形的配对情况：
- 矩形 0 和矩形 1 ：4/8 == 3/6
- 矩形 0 和矩形 2 ：4/8 == 10/20
- 矩形 0 和矩形 3 ：4/8 == 15/30
- 矩形 1 和矩形 2 ：3/6 == 10/20
- 矩形 1 和矩形 3 ：3/6 == 15/30
- 矩形 2 和矩形 3 ：10/20 == 15/30
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>rectangles = [[4,5],[7,8]]
<strong>输出：</strong>0
<strong>解释：</strong>不存在成对的可互换矩形。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == rectangles.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>rectangles[i].length == 2</code></li>
	<li><code>1 &lt;= width<sub>i</sub>, height<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans = 0;

        unordered_map<string, long long> cnt;
        for (auto& rect : rectangles) {
            int g = gcd(rect[0], rect[1]);
            string t = to_string(rect[0] / g) + "/" + to_string(rect[1] / g);
            ans += cnt[t];
            cnt[t]++;
        }

        return ans;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
```




