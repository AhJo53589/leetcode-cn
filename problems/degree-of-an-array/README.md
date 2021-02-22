# `（简单）` [697.degree-of-an-array 数组的度](https://leetcode-cn.com/problems/degree-of-an-array/)

### 题目描述
<p>给定一个非空且只包含非负数的整数数组&nbsp;<code>nums</code>，数组的度的定义是指数组里任一元素出现频数的最大值。</p>

<p>你的任务是在 <code>nums</code> 中找到与&nbsp;<code>nums</code>&nbsp;拥有相同大小的度的最短连续子数组，返回其长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[1, 2, 2, 3, 1]
<strong>输出：</strong>2
<strong>解释：</strong>
输入数组的度是2，因为元素1和2的出现频数最大，均为2.
连续子数组里面拥有相同度的有如下所示:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组[2, 2]的长度为2，所以返回2.
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[1,2,2,3,1,4,2]
<strong>输出：</strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length</code>&nbsp;在1到 50,000 区间范围内。</li>
	<li><code>nums[i]</code>&nbsp;是一个在 0 到 49,999 范围内的整数。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<vector<int>> cnt(50000);
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (cnt[n].empty()) {
                cnt[n] = { 1, 1, i };
            }
            else {
                cnt[n][0]++;
                cnt[n][1] = i - cnt[n][2] + 1;
            }
        }

        sort(cnt.begin(), cnt.end(), [](vector<int>& a, vector<int>& b) {
            if (a.empty() && b.empty()) return false;
            if (a.empty()) return false;
            if (b.empty()) return true;
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        return cnt.front()[1];
    }
};
```




