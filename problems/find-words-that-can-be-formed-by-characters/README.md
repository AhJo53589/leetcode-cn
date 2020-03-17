# `（简单）` [1160.find-words-that-can-be-formed-by-characters 拼写单词](https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/)

### 题目描述
<p>给你一份『词汇表』（字符串数组）&nbsp;<code>words</code>&nbsp;和一张『字母表』（字符串）&nbsp;<code>chars</code>。</p>

<p>假如你可以用&nbsp;<code>chars</code>&nbsp;中的『字母』（字符）拼写出 <code>words</code>&nbsp;中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。</p>

<p>注意：每次拼写时，<code>chars</code> 中的每个字母都只能用一次。</p>

<p>返回词汇表&nbsp;<code>words</code>&nbsp;中你掌握的所有单词的 <strong>长度之和</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = ["cat","bt","hat","tree"], chars = "atach"
<strong>输出：</strong>6
<strong>解释： </strong>
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = ["hello","world","leetcode"], chars = "welldonehoneyr"
<strong>输出：</strong>10
<strong>解释：</strong>
可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= words.length <= 1000</code></li>
	<li><code>1 <= words[i].length, chars.length&nbsp;<= 100</code></li>
	<li>所有字符串中都仅包含小写英文字母</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        unordered_map<char, int> cnt;
        for (auto c : chars)
        {
            cnt[c]++;
        }
        int ans = 0;
        for (auto w : words)
        {
            bool flag = true;
            unordered_map<char, int> cntw;
            for (auto c : w)
            {
                if (++cntw[c] > cnt[c])
                {
                    flag = false;
                    break;
                }
            }
            ans += (flag) ? w.size() : 0;
        }
        return ans;
    }
};
```




