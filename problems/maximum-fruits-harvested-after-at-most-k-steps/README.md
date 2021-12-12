# `（困难）` [5955.maximum-fruits-harvested-after-at-most-k-steps 摘水果](https://leetcode-cn.com/problems/maximum-fruits-harvested-after-at-most-k-steps/)

[contest](https://leetcode-cn.com/contest/weekly-contest-271/problems/maximum-fruits-harvested-after-at-most-k-steps/)

### 题目描述
<div class="notranslate"><p>在一个无限的 x 坐标轴上，有许多水果分布在其中某些位置。给你一个二维整数数组 <code>fruits</code> ，其中 <code>fruits[i] = [position<sub>i</sub>, amount<sub>i</sub>]</code> 表示共有 <code>amount<sub>i</sub></code> 个水果放置在 <code>position<sub>i</sub></code> 上。<code>fruits</code> 已经按 <code>position<sub>i</sub></code> <strong>升序排列</strong> ，每个 <code>position<sub>i</sub></code> <strong>互不相同</strong> 。</p>

<p>另给你两个整数 <code>startPos</code> 和 <code>k</code> 。最初，你位于 <code>startPos</code> 。从任何位置，你可以选择 <strong>向左或者向右</strong> 走。在 x 轴上每移动 <strong>一个单位</strong> ，就记作 <strong>一步</strong> 。你总共可以走 <strong>最多</strong> <code>k</code> 步。你每达到一个位置，都会摘掉全部的水果，水果也将从该位置消失（不会再生）。</p>

<p>返回你可以摘到水果的 <strong>最大总数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 472px; height: 115px;" src="https://assets.leetcode.com/uploads/2021/11/21/1.png" alt="">
<pre><strong>输入：</strong>fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
<strong>输出：</strong>9
<strong>解释：</strong>
最佳路线为：
- 向右移动到位置 6 ，摘到 3 个水果
- 向右移动到位置 8 ，摘到 6 个水果
移动 3 步，共摘到 3 + 6 = 9 个水果
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 512px; height: 129px;" src="https://assets.leetcode.com/uploads/2021/11/21/2.png" alt="">
<pre><strong>输入：</strong>fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
<strong>输出：</strong>14
<strong>解释：</strong>
可以移动最多 k = 4 步，所以无法到达位置 0 和位置 10 。
最佳路线为：
- 在初始位置 5 ，摘到 7 个水果
- 向左移动到位置 4 ，摘到 1 个水果
- 向右移动到位置 6 ，摘到 2 个水果
- 向右移动到位置 7 ，摘到 4 个水果
移动 1 + 3 = 4 步，共摘到 7 + 1 + 2 + 4 = 14 个水果
</pre>

<p><strong>示例 3：</strong></p>
<img style="width: 476px; height: 100px;" src="https://assets.leetcode.com/uploads/2021/11/21/3.png" alt="">
<pre><strong>输入：</strong>fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
<strong>输出：</strong>0
<strong>解释：</strong>
最多可以移动 k = 2 步，无法到达任一有水果的地方
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= fruits.length &lt;= 10<sup>5</sup></code></li>
	<li><code>fruits[i].length == 2</code></li>
	<li><code>0 &lt;= startPos, position<sub>i</sub> &lt;= 2 * 10<sup>5</sup></code></li>
	<li>对于任意 <code>i &gt; 0</code> ，<code>position<sub>i-1</sub> &lt; position<sub>i</sub></code> 均成立（下标从 <strong>0</strong> 开始计数）</li>
	<li><code>1 &lt;= amount<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10<sup>5</sup></code></li>
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
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0;
        int start = 0;
        vector<int> leftFruits(k + 1, 0);
        vector<int> rightFruits(k + 1, 0);
        for (auto& f : fruits) {
            if (f[0] < startPos && f[0] >= startPos - k) {
                leftFruits[startPos - f[0]] = f[1];
            }
            else if (f[0] > startPos&& f[0] <= startPos + k) {
                rightFruits[f[0] - startPos] = f[1];
            }
            else if (f[0] == startPos) {
                start = f[1];
            }
        }

        map<int, long long> left;
        map<int, long long> right;
        long long leftSum = 0;
        long long rightSum = 0;
        for (int i = 0; i <= k; i++) {
            if (leftFruits[i] != 0) {
                leftSum += leftFruits[i];
                left[i] = leftSum;
            }
            if (rightFruits[i] != 0) {
                rightSum += rightFruits[i];
                right[i] = rightSum;
            }
        }

        check(left, right, k, ans);
        check(right, left, k, ans);
        return ans + start;
    }

    void check(map<int, long long>& a, map<int, long long>& b, int k, int& ans) {
        for (auto it : a) {
            int step = it.first;
            int sum = it.second;
            
            int cur = k - step * 2;
            if (cur >= 0 && !b.empty()) {
                //for (auto [k, v] : b) {
                //    cout << "[k, v] = " << k << ", " << v << endl;
                //}
                auto it2 = b.upper_bound(cur);
                //if (it2 != b.end()) {
                //    cout << "it2 = " << it2->first << ", " << it2->second << endl;
                //}
                it2--;
                //if (it2 == b.end()) {
                //    cout << "## it2--; it2 = end" << endl;
                //}
                //else {
                //    cout << "## it2-- it2 = " << it2->first << ", " << it2->second << endl;
                //}
                if (it2 != b.end() && it2->first <= cur) {
                    sum += it2->second;
                }
            }
            ans = max(ans, sum);
        }
    }
};
```




