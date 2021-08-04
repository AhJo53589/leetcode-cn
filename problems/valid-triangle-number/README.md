# `（中等）` [611.valid-triangle-number 有效三角形的个数](https://leetcode-cn.com/problems/valid-triangle-number/)

### 题目描述
<p>给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [2,2,3,4]
<strong>输出:</strong> 3
<strong>解释:</strong>
有效的组合是: 
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li>数组长度不超过1000。</li>
	<li>数组里整数的范围为 [0, 1000]。</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int left = lower_bound(nums.begin(), nums.end(), nums[j] - nums[i] + 1) - nums.begin();
                left = max(left, j + 1);
                int right = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) - nums.begin() - 1;
                ans += max(0, right - left + 1);
            }
        }
        return ans;
    }
};
```




