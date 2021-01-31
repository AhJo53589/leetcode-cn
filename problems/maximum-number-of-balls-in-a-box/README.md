# `（简单）` [5654.maximum-number-of-balls-in-a-box 盒子中小球的最大数量](https://leetcode-cn.com/problems/maximum-number-of-balls-in-a-box/)

[contest](https://leetcode-cn.com/contest/weekly-contest-226/problems/maximum-number-of-balls-in-a-box/)

### 题目描述
<div class="notranslate"><p>你在一家生产小球的玩具厂工作，有 <code>n</code> 个小球，编号从 <code>lowLimit</code> 开始，到 <code>highLimit</code> 结束（包括 <code>lowLimit</code> 和&nbsp;<code>highLimit</code> ，即&nbsp;<code>n == highLimit - lowLimit + 1</code>）。另有无限数量的盒子，编号从 <code>1</code> 到 <code>infinity</code> 。</p>

<p>你的工作是将每个小球放入盒子中，其中盒子的编号应当等于小球编号上每位数字的和。例如，编号 <code>321</code> 的小球应当放入编号 <code>3 + 2 + 1 = 6</code> 的盒子，而编号 <code>10</code> 的小球应当放入编号 <code>1 + 0 = 1</code> 的盒子。</p>

<p>给你两个整数 <code>lowLimit</code> 和 <code>highLimit</code> ，返回放有最多小球的盒子中的小球数量<em>。</em>如果有多个盒子都满足放有最多小球，只需返回其中任一盒子的小球数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>lowLimit = 1, highLimit = 10
<strong>输出：</strong>2
<strong>解释：</strong>
盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
小球数量：2 1 1 1 1 1 1 1 1 0  0  ...
编号 1 的盒子放有最多小球，小球数量为 2 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>lowLimit = 5, highLimit = 15
<strong>输出：</strong>2
<strong>解释：</strong>
盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
小球数量：1 1 1 1 2 2 1 1 1 0  0  ...
编号 5 和 6 的盒子放有最多小球，每个盒子中的小球数量都是 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>lowLimit = 19, highLimit = 28
<strong>输出：</strong>2
<strong>解释：</strong>
盒子编号：1 2 3 4 5 6 7 8 9 10 11 12 ...
小球数量：0 1 1 1 1 1 1 1 1 2  0  0  ...
编号 10 的盒子放有最多小球，小球数量为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= lowLimit &lt;= highLimit &lt;= 10<sup>5</sup></code></li>
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
    int countBalls(int lowLimit, int highLimit) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int i = lowLimit; i <= highLimit; i++) {
            int t = i;
            int x = 0;
            while (t != 0) {
                x += t % 10;
                t /= 10;
            }
            cnt[x]++;
            ans = max(ans, cnt[x]);
        }
        return ans;
    }
};
```




