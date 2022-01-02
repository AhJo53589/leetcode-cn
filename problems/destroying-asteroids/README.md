# `（中等）` [5969.destroying-asteroids 摧毁小行星](https://leetcode-cn.com/problems/destroying-asteroids/)

[contest](https://leetcode-cn.com/contest/weekly-contest-274/problems/destroying-asteroids/)

### 题目描述
<div class="notranslate"><p>给你一个整数&nbsp;<code>mass</code>&nbsp;，它表示一颗行星的初始质量。再给你一个整数数组&nbsp;<code>asteroids</code>&nbsp;，其中&nbsp;<code>asteroids[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;颗小行星的质量。</p>

<p>你可以按 <strong>任意顺序</strong>&nbsp;重新安排小行星的顺序，然后让行星跟它们发生碰撞。如果行星碰撞时的质量 <strong>大于等于</strong>&nbsp;小行星的质量，那么小行星被 <strong>摧毁</strong>&nbsp;，并且行星会 <strong>获得</strong>&nbsp;这颗小行星的质量。否则，行星将被摧毁。</p>

<p>如果所有小行星 <strong>都</strong>&nbsp;能被摧毁，请返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>mass = 10, asteroids = [3,9,19,5,21]
<b>输出：</b>true
<b>解释：</b>一种安排小行星的方式为 [9,19,5,3,21] ：
- 行星与质量为 9 的小行星碰撞。新的行星质量为：10 + 9 = 19
- 行星与质量为 19 的小行星碰撞。新的行星质量为：19 + 19 = 38
- 行星与质量为 5 的小行星碰撞。新的行星质量为：38 + 5 = 43
- 行星与质量为 3 的小行星碰撞。新的行星质量为：43 + 3 = 46
- 行星与质量为 21 的小行星碰撞。新的行星质量为：46 + 21 = 67
所有小行星都被摧毁。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>mass = 5, asteroids = [4,9,23,4]
<b>输出：</b>false
<b>解释：</b>
行星无论如何没法获得足够质量去摧毁质量为 23 的小行星。
行星把别的小行星摧毁后，质量为 5 + 4 + 9 + 4 = 22 。
它比 23 小，所以无法摧毁最后一颗小行星。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= mass &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= asteroids.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= asteroids[i] &lt;= 10<sup>5</sup></code></li>
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
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        for (auto& a : asteroids) {
            if (m < a) return false;
            m += 1LL * a;
        }
        return true;
    }
};
```




