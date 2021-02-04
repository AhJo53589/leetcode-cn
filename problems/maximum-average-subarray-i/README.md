# `（简单）` [643.maximum-average-subarray-i 子数组最大平均数 I](https://leetcode-cn.com/problems/maximum-average-subarray-i/)

### 题目描述
<p>给定 <code>n</code> 个整数，找出平均数最大且长度为 <code>k</code> 的连续子数组，并输出该最大平均数。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>[1,12,-5,-6,50,3], k = 4
<strong>输出：</strong>12.75
<strong>解释：</strong>最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>1 &lt;= <code>k</code> &lt;= <code>n</code> &lt;= 30,000。</li>
	<li>所给数据范围 [-10,000，10,000]。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        double sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                sum -= nums[i - k];
            }
            sum += nums[i];
            if (i >= k - 1) {
                ans = max(ans, sum / k);
            }
        }
        return ans;
    }
};
```




