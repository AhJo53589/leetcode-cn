# `（中等）` [820.short-encoding-of-words 单词的压缩编码](https://leetcode-cn.com/problems/short-encoding-of-words/)

### 题目描述
<p>给定一个单词列表，我们将这个列表编码成一个索引字符串&nbsp;<code>S</code>&nbsp;与一个索引列表 <code>A</code>。</p>

<p>例如，如果这个列表是 <code>["time", "me", "bell"]</code>，我们就可以将其表示为 <code>S = "time#bell#"</code> 和 <code>indexes = [0, 2, 5]</code>。</p>

<p>对于每一个索引，我们可以通过从字符串 <code>S</code>&nbsp;中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。</p>

<p>那么成功对给定单词列表进行编码的最小字符串长度是多少呢？</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入:</strong> words = <code>["time", "me", "bell"]</code>
<strong>输出:</strong> 10
<strong>说明:</strong> S = <code>"time#bell#" ， indexes = [0, 2, 5</code>] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= words.length&nbsp;<= 2000</code></li>
	<li><code>1 <=&nbsp;words[i].length&nbsp;<= 7</code></li>
	<li>每个单词都是小写字母 。</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Trie
{
public:
	Trie() : len(0) {}
	~Trie() 
	{ 
		for (int i = 0; i < 26; i++)
		{
			if (next[i] == nullptr) continue;
			delete next[i];
		}
	}

	int len;
	map<char, Trie*> next;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) 
	{
		root = new Trie();
		int ans = 0;
		for (auto& word : words)
		{
			Trie* p = root;
			int len = 1;	// len for '#'
			for (size_t i = word.size() - 1; i < word.size(); i--)
			{
				if (p->next[word[i]] == nullptr)
				{
					p->next[word[i]] = new Trie();
				}
				p = p->next[word[i]];
				len++;
				if (p->len != 0)
				{
					ans -= p->len;
					p->len = 0;
				}
			}
			if (!p->next.empty()) continue;
			p->len = len;
			ans += len;
		}
		delete root;
		return ans;
    }

private:
	Trie* root;
};
```


### 其它
``` C++
int minimumLengthEncoding(vector<string>& words)
{
	string ans;
	sort(words.rbegin(), words.rend(), [](const string& a, const string& b) { return a.size() < b.size(); });
	for (auto& word : words)
	{
		if (ans.find(word + "#") != string::npos) continue;
		ans += word + "#";
	}
	return ans.size();
}
```


