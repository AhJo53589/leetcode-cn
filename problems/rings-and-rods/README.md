# `（简单）` [5952.rings-and-rods 环和杆](https://leetcode-cn.com/problems/rings-and-rods/)

[contest](https://leetcode-cn.com/contest/weekly-contest-271/problems/rings-and-rods/)

### 题目描述
<div class="notranslate"><p>总计有 <code>n</code> 个环，环的颜色可以是红、绿、蓝中的一种。这些环分布穿在 10 根编号为 <code>0</code> 到 <code>9</code> 的杆上。</p>

<p>给你一个长度为 <code>2n</code> 的字符串 <code>rings</code> ，表示这 <code>n</code> 个环在杆上的分布。<code>rings</code> 中每两个字符形成一个 <strong>颜色位置对</strong> ，用于描述每个环：</p>

<ul>
	<li>第 <code>i</code> 对中的 <strong>第一个</strong> 字符表示第 <code>i</code> 个环的 <strong>颜色</strong>（<code>'R'</code>、<code>'G'</code>、<code>'B'</code>）。</li>
	<li>第 <code>i</code> 对中的 <strong>第二个</strong> 字符表示第 <code>i</code> 个环的 <strong>位置</strong>，也就是位于哪根杆上（<code>'0'</code> 到 <code>'9'</code>）。</li>
</ul>

<p>例如，<code>"R3G2B1"</code> 表示：共有 <code>n == 3</code> 个环，红色的环在编号为 3 的杆上，绿色的环在编号为 2 的杆上，蓝色的环在编号为 1 的杆上。</p>

<p>找出所有集齐 <strong>全部三种颜色</strong> 环的杆，并返回这种杆的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 258px; height: 130px;" src="https://assets.leetcode.com/uploads/2021/11/23/ex1final.png" alt="">
<pre><strong>输入：</strong>rings = "B0B6G0R6R0R6G9"
<strong>输出：</strong>1
<strong>解释：</strong>
- 编号 0 的杆上有 3 个环，集齐全部颜色：红、绿、蓝。
- 编号 6 的杆上有 3 个环，但只有红、蓝两种颜色。
- 编号 9 的杆上只有 1 个绿色环。
因此，集齐全部三种颜色环的杆的数目为 1 。
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 266px; height: 130px;" src="https://assets.leetcode.com/uploads/2021/11/23/ex2final.png" alt="">
<pre><strong>输入：</strong>rings = "B0R0G0R9R0B0G0"
<strong>输出：</strong>1
<strong>解释：</strong>
- 编号 0 的杆上有 6 个环，集齐全部颜色：红、绿、蓝。
- 编号 9 的杆上只有 1 个红色环。
因此，集齐全部三种颜色环的杆的数目为 1 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>rings = "G4"
<strong>输出：</strong>0
<strong>解释：</strong>
只给了一个环，因此，不存在集齐全部三种颜色环的杆。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>rings.length == 2 * n</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li>如 <code>i</code> 是 <strong>偶数</strong> ，则&nbsp;<code>rings[i]</code> 的值可以取 <code>'R'</code>、<code>'G'</code> 或 <code>'B'</code>（下标从 <strong>0</strong> 开始计数）</li>
	<li>如 <code>i</code> 是 <strong>奇数</strong> ，则&nbsp;<code>rings[i]</code> 的值可以取 <code>'0'</code> 到 <code>'9'</code> 中的一个数字（下标从 <strong>0</strong> 开始计数）</li>
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
    int countPoints(string rings) {
        unordered_set<int> ans;
        unordered_map<char, int> change = { {'R', 0}, {'G', 1}, {'B', 2} };
        vector<vector<int>> t(10, vector<int>(3, 0));
        for (int i = 0; i < rings.size(); i += 2) {
            int idx = rings[i + 1] - '0';
            t[idx][change[rings[i]]]++;
            if ((t[idx][0] >= 1) && (t[idx][1] >= 1) && (t[idx][2] >= 1)) {
                ans.insert(idx);
            }
        }
        return ans.size();
    }
};
```




