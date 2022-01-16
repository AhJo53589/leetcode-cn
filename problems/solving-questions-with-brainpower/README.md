# `（中等）` [5982.solving-questions-with-brainpower 解决智力问题](https://leetcode-cn.com/problems/solving-questions-with-brainpower/)

[contest](https://leetcode-cn.com/contest/weekly-contest-276/problems/solving-questions-with-brainpower/)

### 题目描述
<div class="notranslate"><p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>questions</code>&nbsp;，其中&nbsp;<code>questions[i] = [points<sub>i</sub>, brainpower<sub>i</sub>]</code>&nbsp;。</p>

<p>这个数组表示一场考试里的一系列题目，你需要 <strong>按顺序</strong>&nbsp;（也就是从问题 <code>0</code><strong>&nbsp;</strong>开始依次解决），针对每个问题选择 <strong>解决</strong>&nbsp;或者 <strong>跳过</strong>&nbsp;操作。解决问题 <code>i</code>&nbsp;将让你 <b>获得</b>&nbsp;&nbsp;<code>points<sub>i</sub></code>&nbsp;的分数，但是你将 <strong>无法</strong>&nbsp;解决接下来的&nbsp;<code>brainpower<sub>i</sub></code>&nbsp;个问题（即只能跳过接下来的 <code>brainpower<sub>i</sub></code><sub>&nbsp;</sub>个问题）。如果你跳过问题&nbsp;<code>i</code>&nbsp;，你可以对下一个问题决定使用哪种操作。</p>

<ul>
	<li>比方说，给你&nbsp;<code>questions = [[3, 2], [4, 3], [4, 4], [2, 5]]</code>&nbsp;：

	<ul>
		<li>如果问题&nbsp;<code>0</code>&nbsp;被解决了， 那么你可以获得&nbsp;<code>3</code>&nbsp;分，但你不能解决问题&nbsp;<code>1</code> 和&nbsp;<code>2</code>&nbsp;。</li>
		<li>如果你跳过问题&nbsp;<code>0</code>&nbsp;，且解决问题&nbsp;<code>1</code>&nbsp;，你将获得 <code>4</code> 分但是不能解决问题&nbsp;<code>2</code> 和&nbsp;<code>3</code>&nbsp;。</li>
	</ul>
	</li>
</ul>

<p>请你返回这场考试里你能获得的 <strong>最高</strong>&nbsp;分数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>questions = [[3,2],[4,3],[4,4],[2,5]]
<b>输出：</b>5
<b>解释：</b>解决问题 0 和 3 得到最高分。
- 解决问题 0 ：获得 3 分，但接下来 2 个问题都不能解决。
- 不能解决问题 1 和 2
- 解决问题 3 ：获得 2 分
总得分为：3 + 2 = 5 。没有别的办法获得 5 分或者多于 5 分。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
<b>输出：</b>7
<b>解释：</b>解决问题 1 和 4 得到最高分。
- 跳过问题 0
- 解决问题 1 ：获得 2 分，但接下来 2 个问题都不能解决。
- 不能解决问题 2 和 3
- 解决问题 4 ：获得 5 分
总得分为：2 + 5 = 7 。没有别的办法获得 7 分或者多于 7 分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= questions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>questions[i].length == 2</code></li>
	<li><code>1 &lt;= points<sub>i</sub>, brainpower<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/solving-questions-with-brainpower/solution/solving-questions-with-brainpower-by-ika-bnmn/)

### 答题
``` C++
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long ans = 0;
        vector<long long> dp(questions.size(), -1);
        dp[0] = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] >= 0) {
                int next = i + 1;
                long long addPoint = 0;
                if (next < dp.size()) {
                    dp[next] = max(dp[next], dp[i] + addPoint);
                    ans = max(dp[next], ans);
                }

                next = i + questions[i][1] + 1;
                addPoint = questions[i][0];
                if (next < dp.size()) {
                    dp[next] = max(dp[next], dp[i] + addPoint);
                    ans = max(dp[next], ans);
                }
                ans = max(dp[i] + addPoint, ans);
            }
        }
        return ans;
    }
};
```




