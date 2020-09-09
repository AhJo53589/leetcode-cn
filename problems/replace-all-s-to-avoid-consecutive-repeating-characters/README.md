# `（简单）` [1576.replace-all-s-to-avoid-consecutive-repeating-characters 替换所有的问号](https://leetcode-cn.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/)

[contest](https://leetcode-cn.com/contest/weekly-contest-205/problems/replace-all-s-to-avoid-consecutive-repeating-characters/)

### 题目描述
<p>给你一个仅包含小写英文字母和 <code>'?'</code> 字符的字符串 <code>s</code>&lt;var&gt; &lt;/var&gt;，请你将所有的 <code>'?'</code> 转换为若干小写字母，使最终的字符串不包含任何 <strong>连续重复</strong> 的字符。</p>

<p>注意：你 <strong>不能</strong> 修改非 <code>'?'</code> 字符。</p>

<p>题目测试用例保证 <strong>除</strong> <code>'?'</code> 字符 <strong>之外</strong>，不存在连续重复的字符。</p>

<p>在完成所有转换（可能无需转换）后返回最终的字符串。如果有多个解决方案，请返回其中任何一个。可以证明，在给定的约束条件下，答案总是存在的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "?zs"
<strong>输出：</strong>"azs"
<strong>解释：</strong>该示例共有 25 种解决方案，从 "azs" 到 "yzs" 都是符合题目要求的。只有 "z" 是无效的修改，因为字符串 "zzs" 中有连续重复的两个 'z' 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "ubv?w"
<strong>输出：</strong>"ubvaw"
<strong>解释：</strong>该示例共有 24 种解决方案，只有替换成 "v" 和 "w" 不符合题目要求。因为 "ubvvw" 和 "ubvww" 都包含连续重复的字符。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "j?qg??b"
<strong>输出：</strong>"jaqgacb"
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = "??yw?ipkj?"
<strong>输出：</strong>"acywaipkja"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>
	<p><code>1 &lt;= s.length&nbsp;&lt;= 100</code></p>
	</li>
	<li>
	<p><code>s</code> 仅包含小写英文字母和 <code>'?'</code> 字符</p>
	</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '?') continue;
            
            char left = '-';
            char right = '-';
            if (i != 0) {
                left = s[i - 1];
            }
            if (i != s.size() - 1) {
                right = s[i + 1];
            }
            if (left != 'a' && right != 'a') {
                s[i] = 'a';
            }
            else if (left != 'b' && right != 'b') {
                s[i] = 'b';
            }
            else if (left != 'c' && right != 'c') {
                s[i] = 'c';
            }
        }
        return s;
    }
};
```




