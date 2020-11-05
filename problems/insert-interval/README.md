# `（困难）` [57.insert-interval 插入区间](https://leetcode-cn.com/problems/insert-interval/)

### 题目描述
<p>给出一个<em>无重叠的 ，</em>按照区间起始端点排序的区间列表。</p>

<p>在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre><strong>输入：</strong>intervals = [[1,3],[6,9]], newInterval = [2,5]
<strong>输出：</strong>[[1,5],[6,9]]
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre><strong>输入：</strong>intervals = <code>[[1,2],[3,5],[6,7],[8,10],[12,16]]</code>, newInterval = <code>[4,8]</code>
<strong>输出：</strong>[[1,2],[3,10],[12,16]]
<strong>解释：</strong>这是因为新的区间 <code>[4,8]</code> 与 <code>[3,5],[6,7],[8,10]</code>&nbsp;重叠。
</pre>

<p>&nbsp;</p>

<p><strong>注意：</strong>输入类型已在 2019 年 4 月 15 日更改。请重置为默认代码定义以获取新的方法签名。</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/insert-interval/solution/insert-interval-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size();) {
            int t = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t) {
                t = max(t, intervals[j][1]);
                j++;
            }
            ans.push_back({ intervals[i][0], t });
            i = j;
        }

        return ans;
    }
};
```




