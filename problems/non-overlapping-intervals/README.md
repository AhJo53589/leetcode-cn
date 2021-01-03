# `（中等）` [435.non-overlapping-intervals 无重叠区间](https://leetcode-cn.com/problems/non-overlapping-intervals/)

### 题目描述
<div class="notranslate"><p>给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。</p>

<p><strong>注意:</strong></p>

<ol>
	<li>可以认为区间的终点总是大于它的起点。</li>
	<li>区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。</li>
</ol>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [ [1,2], [2,3], [3,4], [1,3] ]

<strong>输出:</strong> 1

<strong>解释:</strong> 移除 [1,3] 后，剩下的区间没有重叠。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> [ [1,2], [1,2], [1,2] ]

<strong>输出:</strong> 2

<strong>解释:</strong> 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> [ [1,2], [2,3] ]

<strong>输出:</strong> 0

<strong>解释:</strong> 你不需要移除任何区间，因为它们已经是无重叠的了。
</pre>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });

        int ans = 0;
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < right) {
                ans++;
                continue;
            }
            right = intervals[i][1];

        }
        return ans;
    }
};
```




