# `（中等）` [5677.count-number-of-homogenous-substrings 统计同构子字符串的数目](https://leetcode-cn.com/problems/count-number-of-homogenous-substrings/)

[contest](https://leetcode-cn.com/contest/weekly-contest-228/problems/count-number-of-homogenous-substrings/)

### 题目描述
<div class="notranslate"><p>给你一个字符串 <code>s</code> ，返回<em> </em><code>s</code><em> </em>中 <strong>同构子字符串</strong> 的数目。由于答案可能很大，只需返回对 <code>10<sup>9</sup> + 7</code> <strong>取余 </strong>后的结果。</p>

<p><strong>同构字符串</strong> 的定义为：如果一个字符串中的所有字符都相同，那么该字符串就是同构字符串。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abbcccaa"
<strong>输出：</strong>13
<strong>解释：</strong>同构子字符串如下所列：
"a"   出现 3 次。
"aa"  出现 1 次。
"b"   出现 2 次。
"bb"  出现 1 次。
"c"   出现 3 次。
"cc"  出现 2 次。
"ccc" 出现 1 次。
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "xy"
<strong>输出：</strong>2
<strong>解释：</strong>同构子字符串是 "x" 和 "y" 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "zzzzz"
<strong>输出：</strong>15
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 由小写字符串组成</li>
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
    int countHomogenous(string s) {
        vector<map<int, int>> dic(26);
        for (int i = 0; i < s.size(); ) {
            int t = 1;
            for (int j = i + 1; j < s.size() && s[i] == s[j]; j++) {
                t++;
            }
            for (int k = t; k >= 1; k--) {
                dic[s[i] - 'a'][k] += (t - k) + 1;
            }
            i += t;
        }

        long long mod = 1e9 + 7;
        long long ans = 0;
        for (int i = 0; i < dic.size(); i++) {
            for (auto [t, cnt] : dic[i]) {
                ans += cnt;
                ans %= mod;
            }
        }
        return ans;
    }
};
```




