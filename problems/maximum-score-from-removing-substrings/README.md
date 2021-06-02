# `（中等）` [1717.maximum-score-from-removing-substrings 删除子字符串的最大得分](https://leetcode-cn.com/problems/maximum-score-from-removing-substrings/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-43/problems/maximum-score-from-removing-substrings/)

### 题目描述
<p>给你一个字符串&nbsp;<code>s</code>&nbsp;和两个整数&nbsp;<code>x</code> 和&nbsp;<code>y</code>&nbsp;。你可以执行下面两种操作任意次。</p>

<ul>
	<li>删除子字符串&nbsp;<code>"ab"</code>&nbsp;并得到&nbsp;<code>x</code>&nbsp;分。

	<ul>
		<li>比方说，从&nbsp;<code>"c<strong>ab</strong>xbae"</code>&nbsp;删除 <code>ab</code>&nbsp;，得到&nbsp;<code>"cxbae"</code>&nbsp;。</li>
	</ul>
	</li>
	<li>删除子字符串<code>"ba"</code>&nbsp;并得到&nbsp;<code>y</code>&nbsp;分。
	<ul>
		<li>比方说，从&nbsp;<code>"cabx<strong>ba</strong>e"</code>&nbsp;删除 <code>ba</code>&nbsp;，得到&nbsp;<code>"cabxe"</code>&nbsp;。</li>
	</ul>
	</li>
</ul>

<p>请返回对 <code>s</code>&nbsp;字符串执行上面操作若干次能得到的最大得分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "cdbcbbaaabab", x = 4, y = 5
<b>输出：</b>19
<strong>解释：</strong>
- 删除 "cdbcbbaaa<strong>ba</strong>b" 中加粗的 "ba" ，得到 s = "cdbcbbaaab" ，加 5 分。
- 删除 "cdbcbbaa<strong>ab</strong>" 中加粗的 "ab" ，得到 s = "cdbcbbaa" ，加 4 分。
- 删除 "cdbcb<strong>ba</strong>a" 中加粗的 "ba" ，得到 s = "cdbcba" ，加 5 分。
- 删除 "cdbc<strong>ba</strong>" 中加粗的 "ba" ，得到 s = "cdbc" ，加 5 分。
总得分为 5 + 4 + 5 + 5 = 19 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "aabbaaxybbaabb", x = 5, y = 4
<b>输出：</b>20
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x, y &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-score-from-removing-substrings/solution/maximum-score-from-removing-substrings-b-e2c4/)

### 答题
``` C++
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }

        int ans = 0;
        ans += calc(s, 'a', 'b', x);
        ans += calc(s, 'b', 'a', y);
        return ans;
    }

    int calc(string& s, char first, char second, int sc) {
        int score = 0;
        string st;
        for (auto c : s) {
            if (!st.empty() && st.back() == first && c == second) {
                score += sc;
                st.pop_back();
                continue;
            }
            st += c;
        }
        s = st;
        return score;
    }
};
```




