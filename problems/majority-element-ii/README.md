# `（中等）` [229.majority-element-ii 求众数 II](https://leetcode-cn.com/problems/majority-element-ii/)

### 题目描述
<p>给定一个大小为&nbsp;<em>n&nbsp;</em>的整数数组，找出其中所有出现超过&nbsp;<code>⌊ n/3 ⌋</code>&nbsp;次的元素。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre><strong>输入：</strong>[3,2,3]
<strong>输出：</strong>[3]</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1]
<strong>输出：</strong>[1]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>[1,1,1,3,3,2,2,2]
<strong>输出：</strong>[1,2]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。</p>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<pair<int, int>> vote(2);
        for (auto n : nums) {
            int empty = -1;
            int match = -1;
            for (int i = 0; i < vote.size(); i++) {
                match = (vote[i].first == n && vote[i].second > 0) ? i: match;
                empty = (vote[i].second == 0) ? i : empty;
            }
            if (match != -1) {
                vote[match].second++;
                continue;
            }
            if (empty != -1) {
                vote[empty].first = n;
                vote[empty].second++;
                continue;
            }
            for (int i = 0; i < vote.size(); i++) {
                vote[i].second--;
            }
        }

        vector<int> ans;
        vector<int> cnt(2);
        for (auto n : nums) {
            for (int i = 0; i < vote.size(); i++) {
                cnt[i] += (vote[i].first == n && vote[i].second > 0);
            }
        }
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] > nums.size() / 3) {
                ans.push_back(vote[i].first);
            }
        }
        return ans;
    }
};
```




