# `（困难）` [5258.maximum-score-words-formed-by-letters 得分最高的单词集合](https://leetcode-cn.com/problems/maximum-score-words-formed-by-letters/)

[contest](https://leetcode-cn.com/contest/weekly-contest-162/problems/maximum-score-words-formed-by-letters/)

### 题目描述
<p>你将会得到一份单词表&nbsp;<code>words</code>，一个字母表&nbsp;<code>letters</code>&nbsp;（可能会有重复字母），以及每个字母对应的得分情况表&nbsp;<code>score</code>。</p>

<p>请你帮忙计算玩家在单词拼写游戏中所能获得的「最高得分」：能够由&nbsp;<code>letters</code>&nbsp;里的字母拼写出的&nbsp;<strong>任意</strong>&nbsp;属于 <code>words</code>&nbsp;单词子集中，分数最高的单词集合的得分。</p>

<p>单词拼写游戏的规则概述如下：</p>

<ul>
	<li>玩家需要用字母表&nbsp;<code>letters</code> 里的字母来拼写单词表&nbsp;<code>words</code>&nbsp;中的单词。</li>
	<li>可以只使用字母表&nbsp;<code>letters</code> 中的部分字母，但是每个字母最多被使用一次。</li>
	<li>单词表 <code>words</code>&nbsp;中每个单词只能计分（使用）一次。</li>
	<li>根据字母得分情况表<code>score</code>，字母 <code>'a'</code>,&nbsp;<code>'b'</code>,&nbsp;<code>'c'</code>, ... ,&nbsp;<code>'z'</code> 对应的得分分别为 <code>score[0]</code>, <code>score[1]</code>,&nbsp;...,&nbsp;<code>score[25]</code>。</li>
	<li>本场游戏的「得分」是指：玩家所拼写出的单词集合里包含的所有字母的得分之和。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
<strong>输出：</strong>23
<strong>解释：</strong>
字母得分为  a=1, c=9, d=5, g=3, o=2
使用给定的字母表 letters，我们可以拼写单词 "dad" (5+1+5)和 "good" (3+2+2+5)，得分为 23 。
而单词 "dad" 和 "dog" 只能得到 21 分。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
<strong>输出：</strong>27
<strong>解释：</strong>
字母得分为  a=4, b=4, c=4, x=5, z=10
使用给定的字母表 letters，我们可以组成单词 "ax" (4+5)， "bx" (4+5) 和 "cx" (4+5) ，总得分为 27 。
单词 "xxxz" 的得分仅为 25 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
<strong>输出：</strong>0
<strong>解释：</strong>
字母 "e" 在字母表 letters 中只出现了一次，所以无法组成单词表 words 中的单词。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 14</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 15</code></li>
	<li><code>1 &lt;= letters.length &lt;= 100</code></li>
	<li><code>letters[i].length == 1</code></li>
	<li><code>score.length ==&nbsp;26</code></li>
	<li><code>0 &lt;= score[i] &lt;= 10</code></li>
	<li><code>words[i]</code>&nbsp;和&nbsp;<code>letters[i]</code>&nbsp;只包含小写的英文字母。</li>
</ul>

            

---
### 思路
```
```
[发布的题解](https://leetcode-cn.com/problems/maximum-score-words-formed-by-letters/solution/5258-by-ikaruga/)


### 答题
``` C++
vector<int> group(vector<string>& words, int bit)
{
    vector<int> g(26, 0);
    for (int i = 0; i < words.size(); i++)
    {
        if (bit & (1 << i))
        {
            for (auto c : words[i])
            {
                g[c - 'a']++;
            }
        }
    }
    return g;
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
{
    vector<int> l(26, 0);
    for (auto c : letters)
    {
        l[c - 'a']++;
    }

    int ans = 0;
    for (int i = 0; i < (1 << words.size()); i++)
    {
        auto g = group(words, i);
        int temp = 0;
        for (int j = 0; j < 26; j++)
        {
            if (l[j] < g[j])
            {
                temp = 0;
                break;
            }
            else
            {
                temp += g[j] * score[j];
            }
        }
        ans = max(ans, temp);
    }
    return ans;
}
```




