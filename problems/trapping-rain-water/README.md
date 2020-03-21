# `（困难）` [42.trapping-rain-water 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)

### 题目描述
<p>给定&nbsp;<em>n</em> 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。</p>
<p><img style="height: 161px; width: 412px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png"></p>
<p><small>上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。&nbsp;<strong>感谢 Marcos</strong> 贡献此图。</small></p>
<p><strong>示例:</strong></p>
<pre><strong>输入:</strong> [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>输出:</strong> 6</pre>

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/trapping-rain-water/solution/42-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int trap(vector<int>& height)
    {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++)
        {
            while (!st.empty() && height[st.top()] < height[i])
            {
                int cur = st.top();
                st.pop();
                if (st.empty()) break;
                int l = st.top();
                int r = i;
                int h = min(height[r], height[l]) - height[cur];
                ans += (r - l - 1) * h;
            }
            st.push(i);
        }
        return ans;
    }
};
```
