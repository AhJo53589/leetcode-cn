# `（中等）` [LCP_12.xiao-zhang-shua-ti-ji-hua 小张刷题计划](https://leetcode-cn.com/problems/xiao-zhang-shua-ti-ji-hua/)
[contest](https://leetcode-cn.com/contest/season/2020-spring/problems/xiao-zhang-shua-ti-ji-hua/)

### 题目描述
<p>为了提高自己的代码能力，小张制定了 <code>LeetCode</code> 刷题计划，他选中了 <code>LeetCode</code> 题库中的 <code>n</code> 道题，编号从 <code>0</code> 到 <code>n-1</code>，并计划在 <code>m</code> 天内<strong>按照题目编号顺序</strong>刷完所有的题目（注意，小张不能用多天完成同一题）。</p>

<p>在小张刷题计划中，小张需要用 <code>time[i]</code> 的时间完成编号 <code>i</code> 的题目。此外，小张还可以使用场外求助功能，通过询问他的好朋友小杨题目的解法，可以省去该题的做题时间。为了防止“小张刷题计划”变成“小杨刷题计划”，小张每天最多使用一次求助。</p>

<p>我们定义 <code>m</code> 天中做题时间最多的一天耗时为 <code>T</code>（小杨完成的题目不计入做题总时间）。请你帮小张求出最小的 <code>T</code>是多少。</p>

<p><strong>示例 1：</strong></p>

<blockquote>
<p>输入：<code>time = [1,2,3,3], m = 2</code></p>

<p>输出：<code>3</code></p>

<p>解释：第一天小张完成前三题，其中第三题找小杨帮忙；第二天完成第四题，并且找小杨帮忙。这样做题时间最多的一天花费了 3 的时间，并且这个值是最小的。</p>
</blockquote>

<p><strong>示例 2：</strong></p>

<blockquote>
<p>输入：<code>time = [999,999,999], m = 4</code></p>

<p>输出：<code>0</code></p>

<p>解释：在前三天中，小张每天求助小杨一次，这样他可以在三天内完成所有的题目并不花任何时间。</p>
</blockquote>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<ul>
	<li><code>1 <= time.length <= 10^5</code></li>
	<li><code>1 <= time[i] <= 10000</code></li>
	<li><code>1 <= m <= 1000</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/xiao-zhang-shua-ti-ji-hua/solution/xiao-zhang-shua-ti-ji-hua-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int minTime(vector<int>& time, int m) {
        if (time.size() <= m) return 0;

        int l = 0;
        int r = INT_MAX;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (canSplit(time, m, mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }

    bool canSplit(vector<int>& time, int m, int split_sum) {
        int cnt = 0;
        int sum = 0;
        int maxT = 0;
        for (auto& t : time) {
            sum += t;
            maxT = max(maxT, t);
            if (sum - maxT > split_sum) {
                if (++cnt == m) return false;
                sum = t;
                maxT = t;
            }
        }
        return true;
    }
};
```




