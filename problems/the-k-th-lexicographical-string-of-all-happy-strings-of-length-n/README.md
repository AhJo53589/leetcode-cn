# `（中等）` [5374.the-k-th-lexicographical-string-of-all-happy-strings-of-length-n 长度为 n 的开心字符串中字典序第 k 小的字符串](https://leetcode-cn.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-24/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/)

### 题目描述
<p>一个 「开心字符串」定义为：</p>

<ul>
	<li>仅包含小写字母&nbsp;<code>['a', 'b', 'c']</code>.</li>
	<li>对所有在&nbsp;<code>1</code>&nbsp;到&nbsp;<code>s.length - 1</code>&nbsp;之间的&nbsp;<code>i</code>&nbsp;，满足&nbsp;<code>s[i] != s[i + 1]</code>&nbsp;（字符串的下标从 1 开始）。</li>
</ul>

<p>比方说，字符串&nbsp;<strong>"abc"</strong>，<strong>"ac"，"b"</strong> 和&nbsp;<strong>"abcbabcbcb"</strong>&nbsp;都是开心字符串，但是&nbsp;<strong>"aa"</strong>，<strong>"baa"</strong>&nbsp;和&nbsp;<strong>"ababbc"</strong>&nbsp;都不是开心字符串。</p>

<p>给你两个整数 <code>n</code>&nbsp;和 <code>k</code>&nbsp;，你需要将长度为 <code>n</code>&nbsp;的所有开心字符串按字典序排序。</p>

<p>请你返回排序后的第 k 个开心字符串，如果长度为 <code>n</code>&nbsp;的开心字符串少于 <code>k</code>&nbsp;个，那么请你返回 <strong>空字符串</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 1, k = 3
<strong>输出：</strong>"c"
<strong>解释：</strong>列表 ["a", "b", "c"] 包含了所有长度为 1 的开心字符串。按照字典序排序后第三个字符串为 "c" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 1, k = 4
<strong>输出：</strong>""
<strong>解释：</strong>长度为 1 的开心字符串只有 3 个。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 3, k = 9
<strong>输出：</strong>"cab"
<strong>解释：</strong>长度为 3 的开心字符串总共有 12 个 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"] 。第 9 个字符串为 "cab"
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 2, k = 7
<strong>输出：</strong>""
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>n = 10, k = 100
<strong>输出：</strong>"abacbabacb"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

            

---
### 思路
```
```



### 答题
``` C++
    string getHappyString(int n, int k) 
    {
        string s(n, 'a');
        for (int i = 1; i < n; i += 2)
        {
            s[i] = 'b';
        }
        k -= 1;

        bool flag = true;
        while (k-- > 0)
        {
            for (int i = s.size() - 1; i >= 0; i--)
            {
                flag = false;
                if (s[i] == 'd') break;

                s[i]++;
                s[i] += (i > 0 && s[i - 1] == s[i]);
                flag = !(s[i] == 'd');
                if (!flag) continue;

                for (int j = i + 1; j < s.size(); j++)
                {
                    s[j] = s[j - 1] == 'a' ? 'b' : 'a';
                }
                break;
            }
        }

        return flag ? s : "";
    }
```




