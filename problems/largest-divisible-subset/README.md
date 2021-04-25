# `（中等）` [368.largest-divisible-subset 最大整除子集](https://leetcode-cn.com/problems/largest-divisible-subset/)

### 题目描述
给你一个由 <strong>无重复</strong> 正整数组成的集合 <code>nums</code> ，请你找出并返回其中最大的整除子集 <code>answer</code> ，子集中每一元素对 <code>(answer[i], answer[j])</code> 都应当满足：
<ul>
	<li><code>answer[i] % answer[j] == 0</code> ，或</li>
	<li><code>answer[j] % answer[i] == 0</code></li>
</ul>

<p>如果存在多个有效解子集，返回其中任何一个均可。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>[1,2]
<strong>解释：</strong>[1,3] 也会被视为正确答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,4,8]
<strong>输出：</strong>[1,2,4,8]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2 * 10<sup>9</sup></code></li>
	<li><code>nums</code> 中的所有整数 <strong>互不相同</strong></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        // 第 1 步：动态规划找出最大子集的个数、最大子集中的最大整数
        vector<int> dp(len, 1);
        int maxSize = 1;
        int maxVal = dp[0];
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                // 题目中说「没有重复元素」很重要
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxVal = nums[i];
            }
        }

        // 第 2 步：倒推获得最大子集
        vector<int> res;
        if (maxSize == 1) {
            res.push_back(nums[0]);
            return res;
        }

        for (int i = len - 1; i >= 0 && maxSize > 0; i--) {
            if (dp[i] == maxSize && maxVal % nums[i] == 0) {
                res.push_back(nums[i]);
                maxVal = nums[i];
                maxSize--;
            }
        }
        return res;
    }
};

```




