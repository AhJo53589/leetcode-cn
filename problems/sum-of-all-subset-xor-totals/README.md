# `（简单）` [5759.sum-of-all-subset-xor-totals 找出所有子集的异或总和再求和](https://leetcode-cn.com/problems/sum-of-all-subset-xor-totals/)

[contest](https://leetcode-cn.com/contest/weekly-contest-241/problems/sum-of-all-subset-xor-totals/)

### 题目描述
<div class="notranslate"><p>一个数组的<strong> 异或总和</strong> 定义为数组中所有元素按位 <code>XOR</code> 的结果；如果数组为 <strong>空</strong> ，则异或总和为 <code>0</code> 。</p>

<ul>
	<li>例如，数组&nbsp;<code>[2,5,6]</code> 的 <strong>异或总和</strong> 为 <code>2 XOR 5 XOR 6 = 1</code> 。</li>
</ul>

<p>给你一个数组 <code>nums</code> ，请你求出 <code>nums</code> 中每个 <strong>子集</strong> 的 <strong>异或总和</strong> ，计算并返回这些值相加之 <strong>和</strong> 。</p>

<p><strong>注意：</strong>在本题中，元素 <strong>相同</strong> 的不同子集应 <strong>多次</strong> 计数。</p>

<p>数组 <code>a</code> 是数组 <code>b</code> 的一个 <strong>子集</strong> 的前提条件是：从 <code>b</code> 删除几个（也可能不删除）元素能够得到 <code>a</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3]
<strong>输出：</strong>6
<strong>解释：</strong>[1,3] 共有 4 个子集：
- 空子集的异或总和是 0 。
- [1] 的异或总和为 1 。
- [3] 的异或总和为 3 。
- [1,3] 的异或总和为 1 XOR 3 = 2 。
0 + 1 + 3 + 2 = 6
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [5,1,6]
<strong>输出：</strong>28
<strong>解释：</strong>[5,1,6] 共有 8 个子集：
- 空子集的异或总和是 0 。
- [5] 的异或总和为 5 。
- [1] 的异或总和为 1 。
- [6] 的异或总和为 6 。
- [5,1] 的异或总和为 5 XOR 1 = 4 。
- [5,6] 的异或总和为 5 XOR 6 = 3 。
- [1,6] 的异或总和为 1 XOR 6 = 7 。
- [5,1,6] 的异或总和为 5 XOR 1 XOR 6 = 2 。
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,4,5,6,7,8]
<strong>输出：</strong>480
<strong>解释：</strong>每个子集的全部异或总和值之和为 480 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 12</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 20</code></li>
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
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int x = 0; x < (1 << n); x++) {
            int s = 0;
            for (int i = 0; i < nums.size(); i++) {
                if ((x & (1 << i)) == 0) continue;
                s ^= nums[i];
            }
            ans += s;
        }
        return ans;
    }
};
```




