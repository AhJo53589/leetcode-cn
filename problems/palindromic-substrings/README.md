# `（中等）` [647.palindromic-substrings 回文子串](https://leetcode-cn.com/problems/palindromic-substrings/)

### 题目描述
<p>给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。</p>

<p>具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>"abc"
<strong>输出：</strong>3
<strong>解释：</strong>三个回文子串: "a", "b", "c"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>"aaa"
<strong>输出：</strong>6
<strong>解释：</strong>6个回文子串: "a", "a", "a", "aa", "aa", "aaa"</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>输入的字符串长度不会超过 1000 。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/palindromic-substrings/solution/palindromic-substrings-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += check(s, i, i);
            if (i == s.size() - 1) continue;
            ans += check(s, i, i + 1);
        }
        return ans;
    }

    int check(string& s, int l, int r) {
        int cnt = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
            cnt++;
        }
        return cnt;
    }
};
```




