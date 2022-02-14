# `（简单）` [6000.sort-even-and-odd-indices-independently 对奇偶下标分别排序](https://leetcode-cn.com/problems/sort-even-and-odd-indices-independently/)

[contest](https://leetcode-cn.com/contest/weekly-contest-279/problems/sort-even-and-odd-indices-independently/)

### 题目描述
<div class="notranslate"><p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。根据下述规则重排 <code>nums</code> 中的值：</p>

<ol>
	<li>按 <strong>非递增</strong> 顺序排列 <code>nums</code> <strong>奇数下标</strong> 上的所有值。

	<ul>
		<li>举个例子，如果排序前 <code>nums = [4,<em><strong>1</strong></em>,2,<em><strong>3</strong></em>]</code> ，对奇数下标的值排序后变为 <code>[4,<em><strong>3</strong></em>,2,<em><strong>1</strong></em>]</code> 。奇数下标 <code>1</code> 和 <code>3</code> 的值按照非递增顺序重排。</li>
	</ul>
	</li>
	<li>按 <strong>非递减</strong> 顺序排列 <code>nums</code> <strong>偶数下标</strong> 上的所有值。
	<ul>
		<li>举个例子，如果排序前 <code>nums = [<em><strong>4</strong></em>,1,<em><strong>2</strong></em>,3]</code> ，对偶数下标的值排序后变为 <code>[<em><strong>2</strong></em>,1,<em><strong>4</strong></em>,3]</code> 。偶数下标 <code>0</code> 和 <code>2</code> 的值按照非递减顺序重排。</li>
	</ul>
	</li>
</ol>

<p>返回重排 <code>nums</code> 的值之后形成的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [4,1,2,3]
<strong>输出：</strong>[2,3,4,1]
<strong>解释：</strong>
首先，按非递增顺序重排奇数下标（1 和 3）的值。
所以，nums 从 [4,<em><strong>1</strong></em>,2,<em><strong>3</strong></em>] 变为 [4,<em><strong>3</strong></em>,2,<em><strong>1</strong></em>] 。
然后，按非递减顺序重排偶数下标（0 和 2）的值。
所以，nums 从 [<em><strong>4</strong></em>,1,<em><strong>2</strong></em>,3] 变为 [<em><strong>2</strong></em>,3,<em><strong>4</strong></em>,1] 。
因此，重排之后形成的数组是 [2,3,4,1] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [2,1]
<strong>输出：</strong>[2,1]
<strong>解释：</strong>
由于只有一个奇数下标和一个偶数下标，所以不会发生重排。
形成的结果数组是 [2,1] ，和初始数组一样。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
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
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<vector<int>> st(2, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            st[i % 2].push_back(nums[i]);
        }
        sort(st[0].begin(), st[0].end());
        sort(st[1].rbegin(), st[1].rend());
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < st[0].size(); i++) {
            ans[i * 2] = st[0][i];
        }
        for (int i = 0; i < st[1].size(); i++) {
            ans[i * 2 + 1] = st[1][i];
        }
        return ans;
    }
};
```




