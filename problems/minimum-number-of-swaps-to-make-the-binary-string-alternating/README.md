# `（中等）` [5760.minimum-number-of-swaps-to-make-the-binary-string-alternating 构成交替字符串需要的最小交换次数](https://leetcode-cn.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/)

[contest](https://leetcode-cn.com/contest/weekly-contest-241/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/)

### 题目描述
<div class="notranslate"><p>给你一个二进制字符串 <code>s</code> ，现需要将其转化为一个 <strong>交替字符串</strong> 。请你计算并返回转化所需的 <strong>最小</strong> 字符交换次数，如果无法完成转化，返回<em> </em><code>-1</code><em> </em>。</p>

<p><strong>交替字符串</strong> 是指：相邻字符之间不存在相等情况的字符串。例如，字符串 <code>"010"</code> 和 <code>"1010"</code> 属于交替字符串，但 <code>"0100"</code> 不是。</p>

<p>任意两个字符都可以进行交换，<strong>不必相邻</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "111000"
<strong>输出：</strong>1
<strong>解释：</strong>交换位置 1 和 4："1<em><strong>1</strong></em>10<em><strong>0</strong></em>0" -&gt; "1<em><strong>0</strong></em>10<em><strong>1</strong></em>0" ，字符串变为交替字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "010"
<strong>输出：</strong>0
<strong>解释：</strong>字符串已经是交替字符串了，不需要交换。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "1110"
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> 的值为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/solution/minimum-number-of-swaps-by-ikaruga-xdg2/)

### 答题
``` C++
class Solution {
public:
    int minSwaps(string s) {
        vector<int> cnt(2, 0);
        for (auto c : s) {
            cnt[c - '0']++;
        }
        if (abs(cnt[0] - cnt[1]) > 1) return -1;

        int ans = 0;
        if (cnt[0] == cnt[1]) {
            ans = min(check(s, '0'), check(s, '1'));
        }
        else {
            char c = (cnt[0] < cnt[1]) ? '1' : '0';
            ans = check(s, c);
        }
        return ans / 2;
    }

    int check(string& s, char c) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt += (s[i] != c);
            c = (c == '0') ? '1' : '0';
        }
        return cnt;
    }
};
```




