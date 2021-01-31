# `（中等）` [5665.restore-the-array-from-adjacent-pairs 从相邻元素对还原数组](https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs/)

[contest](https://leetcode-cn.com/contest/weekly-contest-226/problems/restore-the-array-from-adjacent-pairs/)

### 题目描述
<div class="notranslate"><p>存在一个由 <code>n</code> 个不同元素组成的整数数组 <code>nums</code> ，但你已经记不清具体内容。好在你还记得 <code>nums</code> 中的每一对相邻元素。</p>

<p>给你一个二维整数数组 <code>adjacentPairs</code> ，大小为 <code>n - 1</code> ，其中每个 <code>adjacentPairs[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示元素 <code>u<sub>i</sub></code> 和 <code>v<sub>i</sub></code> 在 <code>nums</code> 中相邻。</p>

<p>题目数据保证所有由元素 <code>nums[i]</code> 和 <code>nums[i+1]</code> 组成的相邻元素对都存在于 <code>adjacentPairs</code> 中，存在形式可能是 <code>[nums[i], nums[i+1]]</code> ，也可能是 <code>[nums[i+1], nums[i]]</code> 。这些相邻元素对可以 <strong>按任意顺序</strong> 出现。</p>

<p>返回 <strong>原始数组</strong><em> </em><code>nums</code><em> </em>。如果存在多种解答，返回 <strong>其中任意一个</strong> 即可。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>adjacentPairs = [[2,1],[3,4],[3,2]]
<strong>输出：</strong>[1,2,3,4]
<strong>解释：</strong>数组的所有相邻元素对都在 adjacentPairs 中。
特别要注意的是，adjacentPairs[i] 只表示两个元素相邻，并不保证其 左-右 顺序。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>adjacentPairs = [[4,-2],[1,4],[-3,1]]
<strong>输出：</strong>[-2,4,1,-3]
<strong>解释：</strong>数组中可能存在负数。
另一种解答是 [-3,1,4,-2] ，也会被视作正确答案。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>adjacentPairs = [[100000,-100000]]
<strong>输出：</strong>[100000,-100000]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>adjacentPairs.length == n - 1</code></li>
	<li><code>adjacentPairs[i].length == 2</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i], u<sub>i</sub>, v<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li>题目数据保证存在一些以&nbsp;<code>adjacentPairs</code> 作为元素对的数组 <code>nums</code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs/solution/restore-the-array-by-ikaruga-vz3d/)

### 答题
``` C++
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_set<int> cnt;
        unordered_map<int, unordered_set<int>> dic;
        for (int i = 0; i < adjacentPairs.size(); i++) {
            for (int t = 0; t < 2; t++) {
                int a = adjacentPairs[i][t];
                int b = adjacentPairs[i][(t + 1) % 2];
                dic[a].insert(b);
                if (cnt.find(a) == cnt.end()) {
                    cnt.insert(a);
                }
                else {
                    cnt.erase(a);
                }
            }
        }

        vector<int> ans(dic.size());
        ans.front() = *cnt.begin();
        for (int i = 1; i < ans.size(); i++) {
            ans[i] = *(dic[ans[i - 1]].begin());
            dic[ans[i]].erase(ans[i - 1]);
        }
        return ans;
    }
};
```




