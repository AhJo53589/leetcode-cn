# `（简单）` [844.backspace-string-compare 比较含退格的字符串](https://leetcode-cn.com/problems/backspace-string-compare/)

### 题目描述
<p>给定 <code>S</code> 和 <code>T</code> 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 <code>#</code> 代表退格字符。</p>

<p><strong>注意：</strong>如果对空文本输入退格字符，文本继续为空。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>S = "ab#c", T = "ad#c"
<strong>输出：</strong>true
<strong>解释：</strong>S 和 T 都会变成 “ac”。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>S = "ab##", T = "c#d#"
<strong>输出：</strong>true
<strong>解释：</strong>S 和 T 都会变成 “”。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>S = "a##c", T = "#a#c"
<strong>输出：</strong>true
<strong>解释：</strong>S 和 T 都会变成 “c”。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>S = "a#c", T = "b"
<strong>输出：</strong>false
<strong>解释：</strong>S 会变成 “c”，但 T 仍然是 “b”。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= S.length &lt;= 200</code></li>
	<li><code>1 &lt;= T.length &lt;= 200</code></li>
	<li><code>S</code> 和 <code>T</code> 只含有小写字母以及字符 <code>'#'</code>。</li>
</ol>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以用 <code>O(N)</code> 的时间复杂度和 <code>O(1)</code> 的空间复杂度解决该问题吗？</li>
</ul>

<p>&nbsp;</p>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string ans_s;
        string ans_t;
        for (int i = 0; i < 2; i++) {
            string& ans = (i == 0) ? ans_s : ans_t;
            string& X = (i == 0) ? S : T;

            for (auto c : X) {
                if (c == '#') {
                    if (!ans.empty()) {
                        ans.pop_back();
                    }
                }
                else {
                    ans.push_back(c);
                }
            }
        }
        return ans_s == ans_t;
    }
};
```




