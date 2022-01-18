# `（中等）` [539.minimum-time-difference 最小时间差](https://leetcode-cn.com/problems/minimum-time-difference/)

### 题目描述
<p>给定一个 24 小时制（小时:分钟 <strong>"HH:MM"</strong>）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>timePoints = ["23:59","00:00"]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>timePoints = ["00:00","23:59","00:00"]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= timePoints &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>timePoints[i]</code> 格式为 <strong>"HH:MM"</strong></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> s(timePoints.size(), 0);
        for (int i = 0; i < s.size(); i++) {
            int hour = (timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0');
            int min = (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
            s[i] = hour * 60 + min;
        }

        int ans = INT_MAX;
        int day = 1 * 24 * 60;
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            int cur = s[i];
            int next = (i + 1 != s.size()) ? s[i + 1] : s[0];
            ans = min(abs(cur - next), ans);
            ans = min(day - abs((cur - next)), ans);
        }
        return ans;
    }
};
```




