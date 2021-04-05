# `（中等）` [1813.sentence-similarity-iii 句子相似性 III](https://leetcode-cn.com/problems/sentence-similarity-iii/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-49/problems/sentence-similarity-iii/)

### 题目描述
<div class="notranslate"><p>一个句子是由一些单词与它们之间的单个空格组成，且句子的开头和结尾没有多余空格。比方说，<code>"Hello World"</code>&nbsp;，<code>"HELLO"</code>&nbsp;，<code>"hello world hello world"</code>&nbsp;都是句子。每个单词都 <strong>只</strong>&nbsp;包含大写和小写英文字母。</p>

<p>如果两个句子&nbsp;<code>sentence1</code> 和&nbsp;<code>sentence2</code>&nbsp;，可以通过往其中一个句子插入一个任意的句子（<strong>可以是空句子</strong>）而得到另一个句子，那么我们称这两个句子是 <strong>相似的</strong>&nbsp;。比方说，<code>sentence1 = "Hello my name is Jane"</code> 且&nbsp;<code>sentence2 = "Hello Jane"</code>&nbsp;，我们可以往 <code>sentence2</code>&nbsp;中&nbsp;<code>"Hello"</code> 和&nbsp;<code>"Jane"</code>&nbsp;之间插入&nbsp;<code>"my name is"</code>&nbsp;得到 <code>sentence1</code>&nbsp;。</p>

<p>给你两个句子&nbsp;<code>sentence1</code> 和&nbsp;<code>sentence2</code>&nbsp;，如果<em>&nbsp;</em><code>sentence1</code> 和<em>&nbsp;</em><code>sentence2</code> 是相似的，请你返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>sentence1 = "My name is Haley", sentence2 = "My Haley"
<b>输出：</b>true
<b>解释：</b>可以往 sentence2 中 "My" 和 "Haley" 之间插入 "name is" ，得到 sentence1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>sentence1 = "of", sentence2 = "A lot of words"
<b>输出：</b>false
<strong>解释：</strong>没法往这两个句子中的一个句子只插入一个句子就得到另一个句子。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>sentence1 = "Eating right now", sentence2 = "Eating"
<b>输出：</b>true
<b>解释：</b>可以往 sentence2 的结尾插入 "right now" 得到 sentence1 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>sentence1 = "Luky", sentence2 = "Lucccky"
<b>输出：</b>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence1.length, sentence2.length &lt;= 100</code></li>
	<li><code>sentence1</code>&nbsp;和&nbsp;<code>sentence2</code>&nbsp;都只包含大小写英文字母和空格。</li>
	<li><code>sentence1</code>&nbsp;和&nbsp;<code>sentence2</code>&nbsp;中的单词都只由单个空格隔开。</li>
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
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1);
        stringstream ss2(sentence2);
        vector<string> str1;
        vector<string> str2;
        string temp;
        while (ss1 >> temp) {
            str1.push_back(temp);
        }
        while(ss2 >> temp) {
            str2.push_back(temp);
        }
        
        if (str1.size() < str2.size()) {
            swap(str1, str2);
        }
        
        if (str2.empty()) return true;
        
        int ans = 0;
        int i = 0;
        int j = (int)str2.size() - 1;
        for (int ii = 0; i < str2.size() && str2[i] == str1[ii]; i++, ii++) {
            ans++;
        }
        for (int jj = (int)str1.size() - 1; j >= 0 && str2[j] == str1[jj]; j--, jj--) {
            ans++;
        }
        // cout << ans << endl;
        return ans >= str2.size();
    }
};
```




