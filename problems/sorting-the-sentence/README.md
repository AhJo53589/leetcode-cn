# `（简单）` [1859.sorting-the-sentence 将句子排序](https://leetcode-cn.com/problems/sorting-the-sentence/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-52/problems/sorting-the-sentence/)

### 题目描述
<p>一个 <strong>句子</strong>&nbsp;指的是一个序列的单词用单个空格连接起来，且开头和结尾没有任何空格。每个单词都只包含小写或大写英文字母。</p>

<p>我们可以给一个句子添加 <strong>从 1 开始的单词位置索引 </strong>，并且将句子中所有单词&nbsp;<strong>打乱顺序</strong>&nbsp;。</p>

<ul>
	<li>比方说，句子&nbsp;<code>"This is a sentence"</code>&nbsp;可以被打乱顺序得到&nbsp;<code>"sentence4 a3 is2 This1"</code>&nbsp;或者&nbsp;<code>"is2 sentence4 This1 a3"</code>&nbsp;。</li>
</ul>

<p>给你一个 <strong>打乱顺序</strong>&nbsp;的句子&nbsp;<code>s</code>&nbsp;，它包含的单词不超过&nbsp;<code>9</code>&nbsp;个，请你重新构造并得到原本顺序的句子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "is2 sentence4 This1 a3"
<b>输出：</b>"This is a sentence"
<b>解释：</b>将 s 中的单词按照初始位置排序，得到 "This1 is2 a3 sentence4" ，然后删除数字。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "Myself2 Me1 I4 and3"
<b>输出：</b>"Me Myself and I"
<b>解释：</b>将 s 中的单词按照初始位置排序，得到 "Me1 Myself2 and3 I4" ，然后删除数字。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 200</code></li>
	<li><code>s</code>&nbsp;只包含小写和大写英文字母、空格以及从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>9</code>&nbsp;的数字。</li>
	<li><code>s</code>&nbsp;中单词数目为&nbsp;<code>1</code>&nbsp;到&nbsp;<code>9</code>&nbsp;个。</li>
	<li><code>s</code>&nbsp;中的单词由单个空格分隔。</li>
	<li><code>s</code>&nbsp;不包含任何前导或者后缀空格。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    string sortSentence(string s) {
        vector<string> str(9);
        stringstream ss(s);
        string temp;
        int n = 0;
        while (ss >> temp) {
            int idx = temp.back() - '0';
            n = max(n, idx);
            temp.pop_back();
            str[idx - 1] = temp;
        }

        string ans;
        for (int i = 0; i < n; i++) {
            ans += str[i];
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};
```




