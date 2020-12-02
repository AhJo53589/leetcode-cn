# `（困难）` [321.create-maximum-number 拼接最大数](https://leetcode-cn.com/problems/create-maximum-number/)

### 题目描述
<p>给定长度分别为&nbsp;<code>m</code>&nbsp;和&nbsp;<code>n</code>&nbsp;的两个数组，其元素由&nbsp;<code>0-9</code>&nbsp;构成，表示两个自然数各位上的数字。现在从这两个数组中选出 <code>k (k &lt;= m + n)</code>&nbsp;个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。</p>

<p>求满足该条件的最大数。结果返回一个表示该最大数的长度为&nbsp;<code>k</code>&nbsp;的数组。</p>

<p><strong>说明: </strong>请尽可能地优化你算法的时间和空间复杂度。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong>
nums1 = <code>[3, 4, 6, 5]</code>
nums2 = <code>[9, 1, 2, 5, 8, 3]</code>
k = <code>5</code>
<strong>输出:</strong>
<code>[9, 8, 6, 5, 3]</code></pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong>
nums1 = <code>[6, 7]</code>
nums2 = <code>[6, 0, 4]</code>
k = <code>5</code>
<strong>输出:</strong>
<code>[6, 7, 6, 0, 4]</code></pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong>
nums1 = <code>[3, 9]</code>
nums2 = <code>[8, 9]</code>
k = <code>3</code>
<strong>输出:</strong>
<code>[9, 8, 9]</code></pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k, 0);
        
        for (int s = max(0, k - (int)nums2.size()); s <= min(k, (int)nums1.size()); s++) {
            vector<int> temp;
            vector<int> temp1 = maxKsequence(nums1, s);
            vector<int> temp2 = maxKsequence(nums2, k - s);
            
            auto iter1 = temp1.begin();
            auto iter2 = temp2.begin();
            while (iter1 != temp1.end() || iter2 != temp2.end()){
                temp.push_back(lexicographical_compare(iter1, temp1.end(), iter2, temp2.end()) ? *iter2++ : *iter1++);
            }
            
            ans = lexicographical_compare(ans.begin(), ans.end(), temp.begin(), temp.end()) ? temp : ans;
        }
        return ans;
    }

    vector<int> maxKsequence(vector<int> v, int k) {
        if (v.size() <= k) return v;
        vector<int> ans;
        int pop = v.size() - k;
        for (int i = 0; i < v.size(); i++) {
            while (!ans.empty() && v[i] > ans.back() && pop-- > 0) {
                ans.pop_back();
            }
            ans.push_back(v[i]);
        }
        ans.resize(k);
        return ans;
    }
};
```




