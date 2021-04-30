# `（困难）` [65.valid-number 有效数字](https://leetcode-cn.com/problems/valid-number/)

### 题目描述
<p><strong>有效数字</strong>（按顺序）可以分成以下几个部分：</p>

<ol>
	<li>一个 <strong>小数</strong> 或者 <strong>整数</strong></li>
	<li>（可选）一个 <code>'e'</code> 或 <code>'E'</code> ，后面跟着一个 <strong>整数</strong></li>
</ol>

<p><strong>小数</strong>（按顺序）可以分成以下几个部分：</p>

<ol>
	<li>（可选）一个符号字符（<code>'+'</code> 或 <code>'-'</code>）</li>
	<li>下述格式之一：
	<ol>
		<li>至少一位数字，后面跟着一个点 <code>'.'</code></li>
		<li>至少一位数字，后面跟着一个点 <code>'.'</code> ，后面再跟着至少一位数字</li>
		<li>一个点 <code>'.'</code> ，后面跟着至少一位数字</li>
	</ol>
	</li>
</ol>

<p><strong>整数</strong>（按顺序）可以分成以下几个部分：</p>

<ol>
	<li>（可选）一个符号字符（<code>'+'</code> 或 <code>'-'</code>）</li>
	<li>至少一位数字</li>
</ol>

<p>部分有效数字列举如下：</p>

<ul>
	<li><code>["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]</code></li>
</ul>

<p>部分无效数字列举如下：</p>

<ul>
	<li><code>["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]</code></li>
</ul>

<p>给你一个字符串 <code>s</code> ，如果 <code>s</code> 是一个 <strong>有效数字</strong> ，请返回 <code>true</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "0"
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "e"
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "."
<strong>输出：</strong>false
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = ".1"
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>s</code> 仅含英文字母（大写和小写），数字（<code>0-9</code>），加号 <code>'+'</code> ，减号 <code>'-'</code> ，或者点 <code>'.'</code> 。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/valid-number/solution/valid-number-by-ikaruga-z4ap/)

### 答题
``` C++
class Solution {
public:
    bool isNumber(string s) {
        int st = 0;
        for (auto c : s) {
            EType t = getType(c);
            if (t == E_Err) return false;
            switch (st) {
            case 0:
                st = t == E_E ? -1 : st;
                st = t == E_Op ? 1 : st;
                st = t == E_Dot ? 3 : st;
                st = t == E_Digit ? 2 : st;
                break;
            case 1:
                st = t == E_E ? -1 : st;
                st = t == E_Op ? -1 : st;
                st = t == E_Dot ? 3 : st;
                st = t == E_Digit ? 2 : st;
                break;
            case 2:
                st = t == E_E ? 5 : st;
                st = t == E_Op ? -1 : st;
                st = t == E_Dot ? 4 : st;
                st = t == E_Digit ? 2 : st;
                break;
            case 3:
                st = t == E_E ? -1 : st;
                st = t == E_Op ? -1 : st;
                st = t == E_Dot ? -1 : st;
                st = t == E_Digit ? 4 : st;
                break;
            case 4:
                st = t == E_E ? 5 : st;
                st = t == E_Op ? -1 : st;
                st = t == E_Dot ? -1 : st;
                st = t == E_Digit ? 4 : st;
                break;
            case 5:
                st = t == E_E ? -1 : st;
                st = t == E_Op ? 6 : st;
                st = t == E_Dot ? -1 : st;
                st = t == E_Digit ? 7 : st;
                break;
            case 6:
            case 7:
                st = t == E_E ? -1 : st;
                st = t == E_Op ? -1 : st;
                st = t == E_Dot ? -1 : st;
                st = t == E_Digit ? 7 : st;
                break;
            }
            if (st == -1) return false;
        }

        return st == 2 || st == 4 || st == 7;
    }

    enum EType {
        E_Err = 0,
        E_E = 1,
        E_Op = 2,
        E_Dot = 3,
        E_Digit = 4
    };

    EType getType(char c) {
        if (c == 'e' || c == 'E') return E_E;
        if (c == '+' || c == '-') return E_Op;
        if (c == '.') return E_Dot;
        if (isdigit(c)) return E_Digit;
        return E_Err;
    }
};
```




