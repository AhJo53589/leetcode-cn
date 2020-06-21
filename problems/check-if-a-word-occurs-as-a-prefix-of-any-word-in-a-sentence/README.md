# `（简单）` [1455.check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence 检查单词是否为句中其他单词的前缀](https://leetcode-cn.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/)

[contest](https://leetcode-cn.com/contest/weekly-contest-190/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/)

### 题目描述
<p>给你一个字符串 <code>sentence</code> 作为句子并指定检索词为 <code>searchWord</code> ，其中句子由若干用 <strong>单个空格</strong> 分隔的单词组成。</p>

<p>请你检查检索词 <code>searchWord</code> 是否为句子 <code>sentence</code> 中任意单词的前缀。</p>

<ul>
	<li>如果&nbsp;<code>searchWord</code> 是某一个单词的前缀，则返回句子&nbsp;<code>sentence</code> 中该单词所对应的下标（<strong>下标从 1 开始</strong>）。</li>
	<li>如果 <code>searchWord</code> 是多个单词的前缀，则返回匹配的第一个单词的下标（<strong>最小下标</strong>）。</li>
	<li>如果 <code>searchWord</code> 不是任何单词的前缀，则返回 <strong>-1 </strong>。</li>
</ul>

<p>字符串 <code>S</code> 的 「前缀」是 <code>S</code> 的任何前导连续子字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>sentence = "i love eating burger", searchWord = "burg"
<strong>输出：</strong>4
<strong>解释：</strong>"burg" 是 "burger" 的前缀，而 "burger" 是句子中第 4 个单词。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>sentence = "this problem is an easy problem", searchWord = "pro"
<strong>输出：</strong>2
<strong>解释：</strong>"pro" 是 "problem" 的前缀，而 "problem" 是句子中第 2 个也是第 6 个单词，但是应该返回最小下标 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>sentence = "i am tired", searchWord = "you"
<strong>输出：</strong>-1
<strong>解释：</strong>"you" 不是句子中任何单词的前缀。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>sentence = "i use triple pillow", searchWord = "pill"
<strong>输出：</strong>4
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>sentence = "hello from the other side", searchWord = "they"
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 100</code></li>
	<li><code>1 &lt;= searchWord.length &lt;= 10</code></li>
	<li><code>sentence</code> 由小写英文字母和空格组成。</li>
	<li><code>searchWord</code> 由小写英文字母组成。</li>
	<li>前缀就是紧密附着于词根的语素，中间不能插入其它成分，并且它的位置是固定的——-位于词根之前。（引用自 <a href="https://baike.baidu.com/item/%E5%89%8D%E7%BC%80" target="_blank">前缀_百度百科</a> ）</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans = -1;
        int i = 0;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            if (word.size() >= searchWord.size()) {
                bool flag = true;
                for (int j = 0; j < searchWord.size(); j++) {
                    if (word[j] != searchWord[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans = i;
                    break;
                }
            }
            i++;
        }
        return ans == -1 ? ans : ans + 1;
    }
};
```




