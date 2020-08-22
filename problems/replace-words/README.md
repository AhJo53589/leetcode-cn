# `（中等）` [648.replace-words 单词替换](https://leetcode-cn.com/problems/replace-words/)

### 题目描述
<p>在英语中，我们有一个叫做&nbsp;<code>词根</code>(root)的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为&nbsp;<code>继承词</code>(successor)。例如，词根<code>an</code>，跟随着单词&nbsp;<code>other</code>(其他)，可以形成新的单词&nbsp;<code>another</code>(另一个)。</p>

<p>现在，给定一个由许多词根组成的词典和一个句子。你需要将句子中的所有<code>继承词</code>用<code>词根</code>替换掉。如果<code>继承词</code>有许多可以形成它的<code>词根</code>，则用最短的词根替换它。</p>

<p>你需要输出替换之后的句子。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>dict(词典) = ["cat", "bat", "rat"] sentence(句子) = "the cattle was rattled by the battery"
<strong>输出：</strong>"the cat was rat by the bat"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>输入只包含小写字母。</li>
	<li><code>1 <= dict.length&nbsp;<= 1000</code></li>
	<li><code>1 <= dict[i].length <= 100</code></li>
	<li>1 <= 句中词语数 <= 1000</li>
	<li>1 <= 句中词语长度 <= 1000</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Trie {
public:
    Trie() {
        //next = vector<Trie*>(26, nullptr);
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }

    void add(string& s, int i) {
        if (i == s.size()) {
            isEnd = true;
            return;
        }

        int idx = s[i] - 'a';
        if (next[idx] == nullptr) {
            next[idx] = new Trie();
        }
        next[idx]->add(s, i + 1);
    }

    string findRoot(string& s, int i) {
        if (i == s.size()) return s;
        if (isEnd) return s.substr(0, i);
        int idx = s[i] - 'a';
        if (next[idx] == nullptr) return s;
        return next[idx]->findRoot(s, i + 1);
    }

    Trie* next[26];
    bool isEnd = false;
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        t = new Trie();
        for (auto s : dict) {
            t->add(s, 0);
        }

        string ans;
        stringstream ss(sentence);
        string temp;
        while (ss >> temp) {
            ans += t->findRoot(temp, 0);
            ans += " ";
        }
        if (ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }

private:
    Trie *t = nullptr;
};
```




