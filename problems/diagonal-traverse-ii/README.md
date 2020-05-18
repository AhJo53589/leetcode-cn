# `（中等）` [1424.diagonal-traverse-ii 对角线遍历 II](https://leetcode-cn.com/problems/diagonal-traverse-ii/)

[contest](https://leetcode-cn.com/contest/weekly-contest-186/problems/diagonal-traverse-ii/)

### 题目描述
<p>给你一个列表&nbsp;<code>nums</code>&nbsp;，里面每一个元素都是一个整数列表。请你依照下面各图的规则，按顺序返回&nbsp;<code>nums</code>&nbsp;中对角线上的整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="height: 143px; width: 158px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/23/sample_1_1784.png" alt=""></strong></p>

<pre><strong>输入：</strong>nums = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>[1,4,2,7,5,3,8,6,9]
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img style="height: 177px; width: 230px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/23/sample_2_1784.png" alt=""></strong></p>

<pre><strong>输入：</strong>nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
<strong>输出：</strong>[1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
<strong>输出：</strong>[1,4,2,5,3,8,6,9,7,10,11]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [[1,2,3,4,5,6]]
<strong>输出：</strong>[1,2,3,4,5,6]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10^5</code></li>
	<li><code>1 <= nums[i].length <=&nbsp;10^5</code></li>
	<li><code>1 <= nums[i][j] <= 10^9</code></li>
	<li><code>nums</code>&nbsp;中最多有&nbsp;<code>10^5</code>&nbsp;个数字。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/diagonal-traverse-ii/solution/diagonal-traverse-ii-by-ikaruga/)

### 答题
``` C++
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> st;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                int k = i + j;
                if (k == st.size()) {
                    st.push_back(vector<int>());
                }
                st[k].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for (auto& s : st) {
            ans.insert(ans.end(), s.rbegin(), s.rend());
        }
        return ans;
    }
```




