# `（中等）` [1577.number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers 数的平方等于两数乘积的方法数](https://leetcode-cn.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/)

[contest](https://leetcode-cn.com/contest/weekly-contest-205/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/)

### 题目描述
<p>给你两个整数数组 <code>nums1</code> 和 <code>nums2</code> ，请你返回根据以下规则形成的三元组的数目（类型 1 和类型 2 ）：</p>

<ul>
	<li>类型 1：三元组 <code>(i, j, k)</code> ，如果 <code>nums1[i]<sup>2</sup>&nbsp;== nums2[j] * nums2[k]</code> 其中 <code>0 &lt;= i &lt; nums1.length</code> 且 <code>0 &lt;= j &lt; k &lt; nums2.length</code></li>
	<li>类型 2：三元组 <code>(i, j, k)</code> ，如果 <code>nums2[i]<sup>2</sup>&nbsp;== nums1[j] * nums1[k]</code> 其中 <code>0 &lt;= i &lt; nums2.length</code> 且 <code>0 &lt;= j &lt; k &lt; nums1.length</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums1 = [7,4], nums2 = [5,2,8,9]
<strong>输出：</strong>1
<strong>解释：</strong>类型 1：(1,1,2), nums1[1]^2 = nums2[1] * nums2[2] (4^2 = 2 * 8)</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums1 = [1,1], nums2 = [1,1,1]
<strong>输出：</strong>9
<strong>解释：</strong>所有三元组都符合题目要求，因为 1^2 = 1 * 1
类型 1：(0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2), nums1[i]^2 = nums2[j] * nums2[k]
类型 2：(0,0,1), (1,0,1), (2,0,1), nums2[i]^2 = nums1[j] * nums1[k]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums1 = [7,7,8,3], nums2 = [1,2,9,7]
<strong>输出：</strong>2
<strong>解释：</strong>有两个符合题目要求的三元组
类型 1：(3,0,2), nums1[3]^2 = nums2[0] * nums2[2]
类型 2：(3,0,1), nums2[3]^2 = nums1[0] * nums1[1]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums1 = [4,7,9,11,23], nums2 = [3,5,1024,12,18]
<strong>输出：</strong>0
<strong>解释：</strong>不存在符合题目要求的三元组
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10^5</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, int> um1;
        unordered_map<long long, int> um2;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = i + 1; j < nums1.size(); j++) {
                long long t = (long long)nums1[i] * (long long)nums1[j];
                um1[t]++;
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            for (int j = i + 1; j < nums2.size(); j++) {
                long long t = (long long)nums2[i] * (long long)nums2[j];
                um2[t]++;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            long long t = (long long)nums1[i] * (long long)nums1[i];
            ans += um2[t];
        }
        for (int i = 0; i < nums2.size(); i++) {
            long long t = (long long)nums2[i] * (long long)nums2[i];
            ans += um1[t];
        }
        return ans;
    }
};
```




