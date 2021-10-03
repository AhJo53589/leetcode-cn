# `（简单）` [405.convert-a-number-to-hexadecimal 数字转换为十六进制数](https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/)

### 题目描述
<div class="notranslate"><p>给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用&nbsp;<a href="https://baike.baidu.com/item/%E8%A1%A5%E7%A0%81/6854613?fr=aladdin">补码运算</a>&nbsp;方法。</p>

<p><strong>注意:</strong></p>

<ol>
	<li>十六进制中所有字母(<code>a-f</code>)都必须是小写。</li>
	<li>十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符<code>'0'</code>来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。&nbsp;</li>
	<li>给定的数确保在32位有符号整数范围内。</li>
	<li><strong>不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。</strong></li>
</ol>

<p><strong>示例 1：</strong></p>

<pre>输入:
26

输出:
"1a"
</pre>

<p><strong>示例 2：</strong></p>

<pre>输入:
-1

输出:
"ffffffff"
</pre>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        long long lnum = (num < 0) ? (long long)pow(2, 32) + num : num;
        string ans = "";
        while (lnum > 0) {
            int x = lnum % 16;
            lnum /= 16;
            ans += (x < 10) ? '0' + x : 'a' + x - 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```




