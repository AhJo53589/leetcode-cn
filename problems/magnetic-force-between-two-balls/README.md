# `（中等）` [1552.magnetic-force-between-two-balls 两球之间的磁力](https://leetcode-cn.com/problems/magnetic-force-between-two-balls/)

[contest](https://leetcode-cn.com/contest/weekly-contest-202/problems/magnetic-force-between-two-balls/)

### 题目描述
<p>在代号为 C-137 的地球上，Rick 发现如果他将两个球放在他新发明的篮子里，它们之间会形成特殊形式的磁力。Rick 有&nbsp;<code>n</code>&nbsp;个空的篮子，第&nbsp;<code>i</code>&nbsp;个篮子的位置在&nbsp;<code>position[i]</code>&nbsp;，Morty&nbsp;想把&nbsp;<code>m</code>&nbsp;个球放到这些篮子里，使得任意两球间&nbsp;<strong>最小磁力</strong>&nbsp;最大。</p>

<p>已知两个球如果分别位于&nbsp;<code>x</code>&nbsp;和&nbsp;<code>y</code>&nbsp;，那么它们之间的磁力为&nbsp;<code>|x - y|</code>&nbsp;。</p>

<p>给你一个整数数组&nbsp;<code>position</code>&nbsp;和一个整数&nbsp;<code>m</code>&nbsp;，请你返回最大化的最小磁力。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 195px; width: 562px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/16/q3v1.jpg" alt=""></p>

<pre><strong>输入：</strong>position = [1,2,3,4,7], m = 3
<strong>输出：</strong>3
<strong>解释：</strong>将 3 个球分别放入位于 1，4 和 7 的三个篮子，两球间的磁力分别为 [3, 3, 6]。最小磁力为 3 。我们没办法让最小磁力大于 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>position = [5,4,3,2,1,1000000000], m = 2
<strong>输出：</strong>999999999
<strong>解释：</strong>我们使用位于 1 和 1000000000 的篮子时最小磁力最大。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == position.length</code></li>
	<li><code>2 <= n <= 10^5</code></li>
	<li><code>1 <= position[i] <= 10^9</code></li>
	<li>所有&nbsp;<code>position</code>&nbsp;中的整数 <strong>互不相同</strong>&nbsp;。</li>
	<li><code>2 <= m <= position.length</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/magnetic-force-between-two-balls/solution/magnetic-force-between-two-balls-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1;
        int high = INT_MAX;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (check(position, m, mid)) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low - 1;
    }

    bool check(vector<int>& position, int m, int f) {
        int idx = 0;
        int cnt = 1;
        for (int j = idx + 1; j < position.size(); j++) {
            if (position[j] - position[idx] < f) continue;
            cnt++;
            idx = j;
            if (cnt == m) return true;
        }
        return false;
    }
};
```




