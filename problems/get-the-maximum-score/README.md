# `（困难）` [1537.get-the-maximum-score 最大得分](https://leetcode-cn.com/problems/get-the-maximum-score/)

[contest](https://leetcode-cn.com/contest/weekly-contest-200/problems/get-the-maximum-score/)

### 题目描述
<p>你有两个 <strong>有序</strong>&nbsp;且数组内元素互不相同的数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;。</p>

<p>一条&nbsp;<strong>合法路径</strong>&nbsp;定义如下：</p>

<ul>
	<li>选择数组 nums1 或者 nums2 开始遍历（从下标 0 处开始）。</li>
	<li>从左到右遍历当前数组。</li>
	<li>如果你遇到了 <code>nums1</code>&nbsp;和 <code>nums2</code>&nbsp;中都存在的值，那么你可以切换路径到另一个数组对应数字处继续遍历（但在合法路径中重复数字只会被统计一次）。</li>
</ul>

<p>得分定义为合法路径中不同数字的和。</p>

<p>请你返回所有可能合法路径中的最大得分。</p>

<p>由于答案可能很大，请你将它对 10^9 + 7 取余后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="height: 163px; width: 538px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/02/sample_1_1893.png" alt=""></strong></p>

<pre><strong>输入：</strong>nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
<strong>输出：</strong>30
<strong>解释：</strong>合法路径包括：
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],（从 nums1 开始遍历）
[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]  （从 nums2 开始遍历）
最大得分为上图中的绿色路径 <strong>[2,4,6,8,10]</strong>&nbsp;。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums1 = [1,3,5,7,9], nums2 = [3,5,100]
<strong>输出：</strong>109
<strong>解释：</strong>最大得分由路径 <strong>[1,3,5,100]</strong> 得到。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
<strong>输出：</strong>40
<strong>解释：</strong>nums1 和 nums2 之间无相同数字。
最大得分由路径 <strong>[6,7,8,9,10]</strong> 得到。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums1 = [1,4,5,8,9,11,19], nums2 = [2,3,4,11,12]
<strong>输出：</strong>61
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums1.length <= 10^5</code></li>
	<li><code>1 <= nums2.length <= 10^5</code></li>
	<li><code>1 <= nums1[i], nums2[i] <= 10^7</code></li>
	<li><code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;都是严格递增的数组。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/get-the-maximum-score/solution/get-the-maximum-score-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        nums1.push_back(mod);
        nums2.push_back(mod);
        int ans = 0;
        int idx1 = 0;
        int idx2 = 0;
        int sum1 = 0;
        int sum2 = 0;
        int m1 = 0;
        int m2 = 0;

        while (idx1 < nums1.size() && idx2 < nums2.size()) {
            int n1 = nums1[idx1];
            int n2 = nums2[idx2];
            sum1 += (n1 <= n2) ? n1 : 0;
            sum2 += (n1 >= n2) ? n2 : 0;

            m1 += (sum1 >= mod);
            sum1 -= (sum1 >= mod) ? mod : 0;
            m2 += (sum2 >= mod);
            sum2 -= (sum2 >= mod) ? mod : 0;

            if (n1 == n2){
                if (m1 != m2) {
                    ans += (m1 > m2) ? sum1 : sum2;
                }
                else {
                    ans += max(sum1, sum2);
                }
                ans %= mod;
                sum1 = 0;
                sum2 = 0;
                m1 = 0;
                m2 = 0;
            }

            idx1 += (n1 <= n2);
            idx2 += (n1 >= n2);
        }
        return ans;
    }

private:
    const int mod = 1e9 + 7;
};

```




