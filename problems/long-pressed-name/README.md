# `（简单）` [925.long-pressed-name 长按键入](https://leetcode-cn.com/problems/long-pressed-name/)

### 题目描述
<p>你的朋友正在使用键盘输入他的名字&nbsp;<code>name</code>。偶尔，在键入字符&nbsp;<code>c</code>&nbsp;时，按键可能会被<em>长按</em>，而字符可能被输入 1 次或多次。</p>

<p>你将会检查键盘输入的字符&nbsp;<code>typed</code>。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回&nbsp;<code>True</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>name = "alex", typed = "aaleex"
<strong>输出：</strong>true
<strong>解释：</strong>'alex' 中的 'a' 和 'e' 被长按。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>name = "saeed", typed = "ssaaedd"
<strong>输出：</strong>false
<strong>解释：</strong>'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>name = "leelee", typed = "lleeelee"
<strong>输出：</strong>true
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>name = "laiden", typed = "laiden"
<strong>输出：</strong>true
<strong>解释：</strong>长按名字中的字符并不是必要的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>name.length &lt;= 1000</code></li>
	<li><code>typed.length &lt;= 1000</code></li>
	<li><code>name</code> 和&nbsp;<code>typed</code>&nbsp;的字符都是小写字母。</li>
</ol>

<p>&nbsp;</p>

<p>&nbsp;</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/long-pressed-name/solution/long-pressed-name-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        while (i < name.size() && j < typed.size()) {
            if (name[i] == typed[j]) {
                i++;
                j++;
                continue;
            }
            if (i != 0 && name[i - 1] == typed[j]) {
                j++;
                continue;
            }
            return false;
        }
        if (i != name.size()) return false;
        while (j < typed.size()) {
            if (typed[j] != name[i - 1]) return false;
            j++;
        }
        return true;
    }
};
```




