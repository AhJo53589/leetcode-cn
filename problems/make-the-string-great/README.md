# `（简单）` [1544.make-the-string-great 整理字符串](https://leetcode-cn.com/problems/make-the-string-great/)

[contest](https://leetcode-cn.com/contest/weekly-contest-201/problems/make-the-string-great/)

### 题目描述
<p>给你一个由大小写英文字母组成的字符串 <code>s</code> 。</p>

<p>一个整理好的字符串中，<strong>两个相邻字符</strong> <code>s[i]</code> 和 <code>s[i + 1]</code> 不会同时满足下述条件：</p>

<ul>
	<li><code>0 <= i <= s.length - 2</code></li>
	<li><code>s[i]</code> 是小写字符，但 <code>s[i + 1]</code> 是相同的大写字符；<strong>反之亦然</strong> 。</li>
</ul>

<p>请你将字符串整理好，每次你都可以从字符串中选出满足上述条件的 <strong>两个相邻</strong> 字符并删除，直到字符串整理好为止。</p>

<p>请返回整理好的 <strong>字符串</strong> 。题目保证在给出的约束条件下，测试样例对应的答案是唯一的。</p>

<p><strong>注意：</strong>空字符串也属于整理好的字符串，尽管其中没有任何字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "leEeetcode"
<strong>输出：</strong>"leetcode"
<strong>解释：</strong>无论你第一次选的是 i = 1 还是 i = 2，都会使 "leEeetcode" 缩减为 "leetcode" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abBAcC"
<strong>输出：</strong>""
<strong>解释：</strong>存在多种不同情况，但所有的情况都会导致相同的结果。例如：
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "s"
<strong>输出：</strong>"s"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 100</code></li>
	<li><code>s</code> 只包含小写和大写英文字母</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    string makeGood(string s) {
        int df = abs('A' - 'a');
        bool flag = true;
        while (flag) {
            if (s == "") break;
            flag = false;
            for (int i = 0; i < s.size() - 1; i++) {
                if (abs(s[i] - s[i + 1]) == df) {
                    s.erase(i, 2);
                    flag = true;
                    break;
                }
            }
        }
        return s;
    }
};
```




