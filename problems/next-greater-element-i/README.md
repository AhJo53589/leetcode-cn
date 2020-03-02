# `（简单）` [496.next-greater-element-i 下一个更大元素 I](https://leetcode-cn.com/problems/next-greater-element-i/)

### 题目描述
<p>给定两个<strong>没有重复元素</strong>的数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;，其中<code>nums1</code>&nbsp;是&nbsp;<code>nums2</code>&nbsp;的子集。找到&nbsp;<code>nums1</code>&nbsp;中每个元素在&nbsp;<code>nums2</code>&nbsp;中的下一个比其大的值。</p>

<p><code>nums1</code>&nbsp;中数字&nbsp;<strong>x</strong>&nbsp;的下一个更大元素是指&nbsp;<strong>x</strong>&nbsp;在&nbsp;<code>nums2</code>&nbsp;中对应位置的右边的第一个比&nbsp;<strong>x&nbsp;</strong>大的元素。如果不存在，对应位置输出-1。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <strong>nums1</strong> = [4,1,2], <strong>nums2</strong> = [1,3,4,2].
<strong>输出:</strong> [-1,3,-1]
<strong>解释:</strong>
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> <strong>nums1</strong> = [2,4], <strong>nums2</strong> = [1,2,3,4].
<strong>输出:</strong> [3,-1]
<strong>解释:</strong>
&nbsp;   对于num1中的数字2，第二个数组中的下一个较大数字是3。
    对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 -1。
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li><code>nums1</code>和<code>nums2</code>中所有元素是唯一的。</li>
	<li><code>nums1</code>和<code>nums2</code>&nbsp;的数组大小都不超过1000。</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
    nums2.push_back(INT_MAX);
    unordered_map<int, int> um;
    stack<int> st;
    for (auto& n : nums2)
    {
        while (!st.empty() && st.top() < n)
        {
            um[st.top()] = n;
            st.pop();
        }
        st.push(n);
    }

    vector<int> ans;
    for (auto& n : nums1)
    {
        ans.push_back(um[n]);
        ans.back() = (ans.back() == INT_MAX) ? -1 : ans.back();
    }
    return ans;
}
```




