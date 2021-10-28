# `（简单）` [496.next-greater-element-i 下一个更大元素 I](https://leetcode-cn.com/problems/next-greater-element-i/)

### 题目描述
<p>给你两个<strong> 没有重复元素</strong> 的数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;，其中<code>nums1</code>&nbsp;是&nbsp;<code>nums2</code>&nbsp;的子集。</p>

<p>请你找出 <code>nums1</code>&nbsp;中每个元素在&nbsp;<code>nums2</code>&nbsp;中的下一个比其大的值。</p>

<p><code>nums1</code>&nbsp;中数字&nbsp;<code>x</code>&nbsp;的下一个更大元素是指&nbsp;<code>x</code>&nbsp;在&nbsp;<code>nums2</code>&nbsp;中对应位置的右边的第一个比&nbsp;<code>x</code><strong>&nbsp;</strong>大的元素。如果不存在，对应位置输出 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> nums1 = [4,1,2], nums2 = [1,3,4,2].
<strong>输出:</strong> [-1,3,-1]
<strong>解释:</strong>
    对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
    对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
    对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> nums1 = [2,4], nums2 = [1,2,3,4].
<strong>输出:</strong> [3,-1]
<strong>解释:</strong>
&nbsp;   对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length &lt;= nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums1</code>和<code>nums2</code>中所有整数 <strong>互不相同</strong></li>
	<li><code>nums1</code> 中的所有整数同样出现在 <code>nums2</code> 中</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以设计一个时间复杂度为 <code>O(nums1.length + nums2.length)</code> 的解决方案吗？</p>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> st;
        for (auto n : nums2) {
            while (!st.empty() && st.back() < n) {
                mp[st.back()] = n;
                st.pop_back();
            }
            st.push_back(n);
        }

        vector<int> ans(nums1.size());
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = (mp.find(nums1[i]) == mp.end()) ? -1 : mp[nums1[i]];
        }
        return ans;
    }
};
```




