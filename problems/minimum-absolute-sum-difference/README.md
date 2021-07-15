# `（中等）` [1818.minimum-absolute-sum-difference 绝对差值和](https://leetcode-cn.com/problems/minimum-absolute-sum-difference/)

### 题目描述
<p>给你两个正整数数组 <code>nums1</code> 和 <code>nums2</code> ，数组的长度都是 <code>n</code> 。</p>

<p>数组 <code>nums1</code> 和 <code>nums2</code> 的 <strong>绝对差值和</strong> 定义为所有 <code>|nums1[i] - nums2[i]|</code>（<code>0 &lt;= i &lt; n</code>）的 <strong>总和</strong>（<strong>下标从 0 开始</strong>）。</p>

<p>你可以选用 <code>nums1</code> 中的 <strong>任意一个</strong> 元素来替换 <code>nums1</code> 中的 <strong>至多</strong> 一个元素，以 <strong>最小化</strong> 绝对差值和。</p>

<p>在替换数组 <code>nums1</code> 中最多一个元素 <strong>之后</strong> ，返回最小绝对差值和。因为答案可能很大，所以需要对 <code>10<sup>9</sup> + 7</code> <strong>取余 </strong>后返回。</p>

<p><code>|x|</code> 定义为：</p>

<ul>
	<li>如果 <code>x &gt;= 0</code> ，值为 <code>x</code> ，或者</li>
	<li>如果 <code>x &lt;= 0</code> ，值为 <code>-x</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums1 = [1,7,5], nums2 = [2,3,5]
<strong>输出：</strong>3
<strong>解释：</strong>有两种可能的最优方案：
- 将第二个元素替换为第一个元素：[1,<strong>7</strong>,5] =&gt; [1,<strong>1</strong>,5] ，或者
- 将第二个元素替换为第三个元素：[1,<strong>7</strong>,5] =&gt; [1,<strong>5</strong>,5]
两种方案的绝对差值和都是 <code>|1-2| + (|1-3| 或者 |5-3|) + |5-5| = </code>3
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
<strong>输出：</strong>0
<strong>解释：</strong>nums1 和 nums2 相等，所以不用替换元素。绝对差值和为 0
</pre>

<p><strong>示例 3</strong><strong>：</strong></p>

<pre><strong>输入：</strong>nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
<strong>输出：</strong>20
<strong>解释：</strong>将第一个元素替换为第二个元素：[<strong>1</strong>,10,4,4,2,7] =&gt; [<strong>10</strong>,10,4,4,2,7]
绝对差值和为 <code>|10-9| + |10-3| + |4-5| + |4-1| + |2-7| + |7-4| = 20</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length</code></li>
	<li><code>n == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10<sup>5</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int mod = 1e9 +7;
        vector<int> s(nums1);
        sort(s.begin(), s.end());

        int ans = 0;
        int maxDiff = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int diff = abs(nums1[i] - nums2[i]);
            ans += diff;
            ans %= mod;

            int j = lower_bound(s.begin(), s.end(), nums2[i]) - s.begin();
            maxDiff = (j < nums1.size()) ? max(maxDiff, diff - (s[j] - nums2[i])) : maxDiff;
            maxDiff = (j > 0) ? max(maxDiff, diff - (nums2[i] - s[j - 1])) : maxDiff;
        }

        return (ans - maxDiff + mod) % mod;
    }
};
```




