# `（中等）` [208.implement-trie-prefix-tree 实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)

### 题目描述
<p>实现一个 Trie (前缀树)，包含&nbsp;<code>insert</code>,&nbsp;<code>search</code>, 和&nbsp;<code>startsWith</code>&nbsp;这三个操作。</p>

<p><strong>示例:</strong></p>

<pre>Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true</pre>

<p><strong>说明:</strong></p>

<ul>
	<li>你可以假设所有的输入都是由小写字母&nbsp;<code>a-z</code>&nbsp;构成的。</li>
	<li>保证所有输入均为非空字符串。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/208-by-ikaruga/)

### 答题
``` C++
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Trie *node = this;
        for (auto c : word)
        {
            if (node->next[c - 'a'] == nullptr)
            {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->is_string = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Trie *node = this;
        for (auto c : word)
        {
            if (node->next[c - 'a'] == nullptr) return false;
            node = node->next[c - 'a'];
        }
        return node->is_string;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        Trie *node = this;
        for (auto c : prefix)
        {
            if (node->next[c - 'a'] == nullptr) return false;
            node = node->next[c - 'a'];
        }
        return true;        
    }
    
private:
    bool is_string = false;
    Trie* next[26] = {nullptr};
};

```




