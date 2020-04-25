# `（简单）` [953.verifying-an-alien-dictionary 验证外星语词典](https://leetcode-cn.com/problems/verifying-an-alien-dictionary/)

### 题目描述
<p>某种外星语也使用英文小写字母，但可能顺序 <code>order</code> 不同。字母表的顺序（<code>order</code>）是一些小写字母的排列。</p>

<p>给定一组用外星语书写的单词 <code>words</code>，以及其字母表的顺序 <code>order</code>，只有当给定的单词在这种外星语中按字典序排列时，返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
<strong>输出：</strong>true
<strong>解释：</strong>在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
<strong>输出：</strong>false
<strong>解释：</strong>在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
<strong>输出：</strong>false
<strong>解释：</strong>当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（<a href="https://baike.baidu.com/item/%E5%AD%97%E5%85%B8%E5%BA%8F">更多信息</a>）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= words.length <= 100</code></li>
	<li><code>1 <= words[i].length <= 20</code></li>
	<li><code>order.length == 26</code></li>
	<li>在&nbsp;<code>words[i]</code>&nbsp;和&nbsp;<code>order</code>&nbsp;中的所有字符都是英文小写字母。</li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/verifying-an-alien-dictionary/solution/verifying-an-alien-dictionary-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> dic;
        for (int i = 0; i < order.size(); i++) {
            dic[order[i]] = i;
        }

        auto f = [&dic](const string& a, const string& b) {
            for (int i = 0; i < a.size(); i++) {
                if (i == b.size()) return false;
                if (dic[a[i]] > dic[b[i]]) return false;
                if (dic[a[i]] < dic[b[i]]) return true;
            }
            return a.size() != b.size();
        };

        for (int i = 1; i < words.size(); i++) {
            if (f(words[i], words[i - 1])) return false;
        }
        return true;
    }
};
```




