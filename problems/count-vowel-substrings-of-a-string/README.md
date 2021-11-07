# `（简单）` [5918.count-vowel-substrings-of-a-string 统计字符串中的元音子字符串](https://leetcode-cn.com/problems/count-vowel-substrings-of-a-string/)

[contest](https://leetcode-cn.com/contest/weekly-contest-266/problems/count-vowel-substrings-of-a-string/)

### 题目描述
<div class="notranslate"><p><strong>子字符串</strong> 是字符串中的一个连续（非空）的字符序列。</p>

<p><strong>元音子字符串</strong> 是 <strong>仅</strong> 由元音（<code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code> 和 <code>'u'</code>）组成的一个子字符串，且必须包含 <strong>全部五种</strong> 元音。</p>

<p>给你一个字符串 <code>word</code> ，统计并返回 <code>word</code> 中 <strong>元音子字符串的数目</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>word = "aeiouu"
<strong>输出：</strong>2
<strong>解释：</strong>下面列出 word 中的元音子字符串（斜体加粗部分）：
- "<em><strong>aeiou</strong></em>u"
- "<strong><em>aeiouu</em></strong>"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>word = "unicornarihan"
<strong>输出：</strong>0
<strong>解释：</strong>word 中不含 5 种元音，所以也不会存在元音子字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>word = "cuaieuouac"
<strong>输出：</strong>7
<strong>解释：</strong>下面列出 word 中的元音子字符串（斜体加粗部分）：
- "c<em><strong>uaieuo</strong></em>uac"
- "c<em><strong>uaieuou</strong></em>ac"
- "c<em><strong>uaieuoua</strong></em>c"
- "cu<em><strong>aieuo</strong></em>uac"
- "cu<em><strong>aieuou</strong></em>ac"
- "cu<em><strong>aieuoua</strong></em>c"
- "cua<em><strong>ieuoua</strong></em>c"</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>word = "bbaeixoubb"
<strong>输出：</strong>0
<strong>解释：</strong>所有包含全部五种元音的子字符串都含有辅音，所以不存在元音子字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code> 仅由小写英文字母组成</li>
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
    int countVowelSubstrings(string word) {
        unordered_map<char, int> ci;
        ci['a'] = 0;
        ci['e'] = 1;
        ci['i'] = 2;
        ci['o'] = 3;
        ci['u'] = 4;

        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            if (ci.find(word[i]) == ci.end()) continue;
            bitset<5> vb;
            for (int j = i; j < word.size(); j++) {
                if (ci.find(word[j]) == ci.end()) break;
                vb.set(ci[word[j]], 1);
                ans += vb.count() == 5;
            }
        }
        return ans;
    }
};
```




