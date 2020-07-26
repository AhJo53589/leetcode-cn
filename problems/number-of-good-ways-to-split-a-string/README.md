# `（中等）` [5458.number-of-good-ways-to-split-a-string 字符串的好分割数目](https://leetcode-cn.com/problems/number-of-good-ways-to-split-a-string/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-31/problems/number-of-good-ways-to-split-a-string/)

### 题目描述
<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，一个分割被称为 「好分割」&nbsp;当它满足：将&nbsp;<code>s</code>&nbsp;分割成 2 个字符串&nbsp;<code>p</code> 和&nbsp;<code>q</code>&nbsp;，它们连接起来等于&nbsp;<code>s</code>&nbsp;且 <code>p</code>&nbsp;和 <code>q</code>&nbsp;中不同字符的数目相同。</p>

<p>请你返回 <code>s</code>&nbsp;中好分割的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "aacaba"
<strong>输出：</strong>2
<strong>解释：</strong>总共有 5 种分割字符串 <code>"aacaba"</code> 的方法，其中 2 种是好分割。
("a", "acaba") 左边字符串和右边字符串分别包含 1 个和 3 个不同的字符。
("aa", "caba") 左边字符串和右边字符串分别包含 1 个和 3 个不同的字符。
("aac", "aba") 左边字符串和右边字符串分别包含 2 个和 2 个不同的字符。这是一个好分割。
("aaca", "ba") 左边字符串和右边字符串分别包含 2 个和 2 个不同的字符。这是一个好分割。
("aacab", "a") 左边字符串和右边字符串分别包含 3 个和 1 个不同的字符。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abcd"
<strong>输出：</strong>1
<strong>解释：</strong>好分割为将字符串分割成 ("ab", "cd") 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "aaaaa"
<strong>输出：</strong>4
<strong>解释：</strong>所有分割都是好分割。</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = "acbadbaada"
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
	<li><code>1 <= s.length <= 10^5</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/number-of-good-ways-to-split-a-string/solution/number-of-good-ways-by-ikaruga/)

### 答题
``` C++
    int numSplits(string s) {
        int ans = 0;

        vector<int> l_dic(26, 0);
        vector<int> r_dic(26, 0);
        int left = 0;
        int right = 0;

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            right += (r_dic[c] == 0);
            r_dic[c]++;
        }

        for (int i = 0; i < s.size() - 1; i++) {
            int c = s[i] - 'a';
            left += (l_dic[c] == 0);
            l_dic[c]++;
            r_dic[c]--;
            right -= (r_dic[c] == 0);
            ans += (left == right);
        }

        return ans;
    }
```




