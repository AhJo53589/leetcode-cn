# `（简单）` [5867.reverse-prefix-of-word 反转单词前缀](https://leetcode-cn.com/problems/reverse-prefix-of-word/)

[contest](https://leetcode-cn.com/contest/weekly-contest-258/problems/reverse-prefix-of-word/)

### 题目描述
<div class="notranslate"><p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>word</code> 和一个字符 <code>ch</code> 。找出 <code>ch</code> 第一次出现的下标 <code>i</code> ，<strong>反转 </strong><code>word</code> 中从下标 <code>0</code> 开始、直到下标 <code>i</code> 结束（含下标 <code>i</code> ）的那段字符。如果 <code>word</code> 中不存在字符 <code>ch</code> ，则无需进行任何操作。</p>

<ul>
	<li>例如，如果 <code>word = "abcdefd"</code> 且 <code>ch = "d"</code> ，那么你应该 <strong>反转</strong> 从下标 0 开始、直到下标 <code>3</code> 结束（含下标 <code>3</code> ）。结果字符串将会是 <code>"<em><strong>dcba</strong></em>efd"</code> 。</li>
</ul>

<p>返回 <strong>结果字符串</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>word = "<em><strong>abcd</strong></em>efd", ch = "d"
<strong>输出：</strong>"<em><strong>dcba</strong></em>efd"
<strong>解释：</strong>"d" 第一次出现在下标 3 。 
反转从下标 0 到下标 3（含下标 3）的这段字符，结果字符串是 "dcbaefd" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>word = "<em><strong>xyxz</strong></em>xe", ch = "z"
<strong>输出：</strong>"<em><strong>zxyx</strong></em>xe"
<strong>解释：</strong>"z" 第一次也是唯一一次出现是在下标 3 。
反转从下标 0 到下标 3（含下标 3）的这段字符，结果字符串是 "zxyxxe" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>word = "abcd", ch = "z"
<strong>输出：</strong>"abcd"
<strong>解释：</strong>"z" 不存在于 word 中。
无需执行反转操作，结果字符串是 "abcd" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 250</code></li>
	<li><code>word</code> 由小写英文字母组成</li>
	<li><code>ch</code> 是一个小写英文字母</li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    string reversePrefix(string word, char ch) {
        bool find = false;
        string ans;
        for (auto c : word) {
            if (!find) {
                ans += c;
                if (c == ch) {
                    find = true;
                    reverse(ans.begin(), ans.end());
                }
            }
            else {
                ans += c;
            }
        }
        return ans;
    }
};
```




