# `（简单）` [453.minimum-moves-to-equal-array-elements 最小移动次数使数组元素相等](https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/)

### 题目描述
<p>给定一个长度为 <em>n</em> 的<strong>非空</strong>整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 <em>n</em> - 1 个元素增加 1。</p>
<p><strong>示例:</strong></p>
<pre><strong>输入:</strong>
[1,2,3]

<strong>输出:</strong>
3

<strong>解释:</strong>
只需要3次移动（注意每次移动会增加两个元素的值）：

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
</pre>

---
### 思路
```
n - 1 个元素加一 等于 1 个元素减一
```



### 答题
``` C++
class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int ans = 0;
        int n = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (n > nums[i])
            {
                ans += (i * (n - nums[i]));
                n = nums[i];
            }
            else
            {
                ans += (nums[i] - n);
            }
        }
        return ans;
    }
};

```




