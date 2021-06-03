# `（中等）` [525.contiguous-array 连续数组](https://leetcode-cn.com/problems/contiguous-array/)

### 题目描述
<p>给定一个二进制数组 <code>nums</code> , 找到含有相同数量的 <code>0</code> 和 <code>1</code> 的最长连续子数组，并返回该子数组的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> nums = [0,1]
<strong>输出:</strong> 2
<strong>说明:</strong> [0, 1] 是具有相同数量0和1的最长连续子数组。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> nums = [0,1,0]
<strong>输出:</strong> 2
<strong>说明:</strong> [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> 不是 <code>0</code> 就是 <code>1</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/contiguous-array/solution/contiguous-array-by-ikaruga-czmv/)

### 答题
``` C++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> um;
        um[0] = -1;

        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += (nums[i] == 0) ? -1 : 1;
            if (um.find(cnt) != um.end()) {
                ans = max(ans, i - um[cnt]);
                continue;
            }
            um[cnt] = i;
        }
        return ans;
    }
};
```




