# `（中等）` [1540.can-convert-string-in-k-moves K 次操作转变字符串](https://leetcode-cn.com/problems/can-convert-string-in-k-moves/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-32/problems/can-convert-string-in-k-moves/)

### 题目描述
<p>给你两个字符串&nbsp;<code>s</code>&nbsp;和&nbsp;<code>t</code>&nbsp;，你的目标是在 <code>k</code>&nbsp;次操作以内把字符串&nbsp;<code>s</code>&nbsp;转变成&nbsp;<code>t</code>&nbsp;。</p>

<p>在第 <code>i</code>&nbsp;次操作时（<code>1 <= i <= k</code>），你可以选择进行如下操作：</p>

<ul>
	<li>选择字符串 <code>s</code>&nbsp;中满足 <code>1 <= j <= s.length</code>&nbsp;且之前未被选过的任意下标 <code>j</code>&nbsp;（下标从 1 开始），并将此位置的字符切换 <code>i</code>&nbsp;次。</li>
	<li>不进行任何操作。</li>
</ul>

<p>切换 1 次字符的意思是用字母表中该字母的下一个字母替换它（字母表环状接起来，所以 <code>'z'</code>&nbsp;切换后会变成 <code>'a'</code>）。</p>

<p>请记住任意一个下标 <code>j</code>&nbsp;最多只能被操作&nbsp;1 次。</p>

<p>如果在不超过 <code>k</code>&nbsp;次操作内可以把字符串 <code>s</code>&nbsp;转变成 <code>t</code>&nbsp;，那么请你返回&nbsp;<code>true</code>&nbsp;，否则请你返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "input", t = "ouput", k = 9
<strong>输出：</strong>true
<strong>解释：</strong>第 6 次操作时，我们将 'i' 切换 6 次得到 'o' 。第 7 次操作时，我们将 'n' 切换 7 次得到 'u' 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abc", t = "bcd", k = 10
<strong>输出：</strong>false
<strong>解释：</strong>我们需要将每个字符切换 1 次才能得到 t 。我们可以在第 1 次操作时将 'a' 切换成 'b' ，但另外 2 个字母在剩余操作中无法再转变为 t 中对应字母。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "aab", t = "bbb", k = 27
<strong>输出：</strong>true
<strong>解释：</strong>第 1 次操作时，我们将第一个 'a' 切换 1 次得到 'b' 。在第 27 次操作时，我们将第二个字母 'a' 切换 27 次得到 'b' 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length, t.length <= 10^5</code></li>
	<li><code>0 <= k <= 10^9</code></li>
	<li><code>s</code>&nbsp;和&nbsp;<code>t</code>&nbsp;只包含小写英文字母。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/can-convert-string-in-k-moves/solution/can-convert-string-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) return false;
        vector<int> vi(26, 0);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans = max(ans, getCount(s[i], t[i], vi));
        }
        return ans <= k;
    }

    int getCount(char a, char b, vector<int>& vi) {
        if (a == b) return 0;
        int df = ((b - 'a' + 26) - (a - 'a')) % 26;
        int cnt = df + vi[df] * 26;
        vi[df]++;
        return cnt;
    }
};
```




