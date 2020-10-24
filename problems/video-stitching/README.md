# `（中等）` [1024.video-stitching 视频拼接](https://leetcode-cn.com/problems/video-stitching/)

### 题目描述
<p>你将会获得一系列视频片段，这些片段来自于一项持续时长为&nbsp;<code>T</code>&nbsp;秒的体育赛事。这些片段可能有所重叠，也可能长度不一。</p>

<p>视频片段&nbsp;<code>clips[i]</code>&nbsp;都用区间进行表示：开始于&nbsp;<code>clips[i][0]</code>&nbsp;并于&nbsp;<code>clips[i][1]</code>&nbsp;结束。我们甚至可以对这些片段自由地再剪辑，例如片段&nbsp;<code>[0, 7]</code>&nbsp;可以剪切成&nbsp;<code>[0, 1] +&nbsp;[1, 3] + [3, 7]</code>&nbsp;三部分。</p>

<p>我们需要将这些片段进行再剪辑，并将剪辑后的内容拼接成覆盖整个运动过程的片段（<code>[0, T]</code>）。返回所需片段的最小数目，如果无法完成该任务，则返回&nbsp;<code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
<strong>输出：</strong>3
<strong>解释：</strong>
我们选中 [0,2], [8,10], [1,9] 这三个片段。
然后，按下面的方案重制比赛片段：
将 [1,9] 再剪辑为 [1,2] + [2,8] + [8,9] 。
现在我们手上有 [0,2] + [2,8] + [8,10]，而这些涵盖了整场比赛 [0, 10]。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>clips = [[0,1],[1,2]], T = 5
<strong>输出：</strong>-1
<strong>解释：</strong>
我们无法只用 [0,1] 和 [1,2] 覆盖 [0,5] 的整个过程。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], T = 9
<strong>输出：</strong>3
<strong>解释： </strong>
我们选取片段 [0,4], [4,7] 和 [6,9] 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>clips = [[0,4],[2,8]], T = 5
<strong>输出：</strong>2
<strong>解释：</strong>
注意，你可能录制超过比赛结束时间的视频。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= clips.length &lt;= 100</code></li>
	<li><code>0 &lt;= clips[i][0] &lt;=&nbsp;clips[i][1] &lt;= 100</code></li>
	<li><code>0 &lt;= T &lt;= 100</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/video-stitching/solution/video-stitching-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {

    }
};
```




