# `（困难）` [212.word-search-ii 单词搜索 II](https://leetcode-cn.com/problems/word-search-ii/)

### 题目描述
<p>给定一个二维网格&nbsp;<strong>board&nbsp;</strong>和一个字典中的单词列表 <strong>words</strong>，找出所有同时在二维网格和字典中出现的单词。</p>

<p>单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 
<strong>words</strong> = <code>["oath","pea","eat","rain"]</code> and <strong>board </strong>=
[
  ['<strong>o</strong>','<strong>a</strong>','a','n'],
  ['e','<strong>t</strong>','<strong>a</strong>','<strong>e</strong>'],
  ['i','<strong>h</strong>','k','r'],
  ['i','f','l','v']
]

<strong>输出:&nbsp;</strong><code>["eat","oath"]</code></pre>

<p><strong>说明:</strong><br>
你可以假设所有输入都由小写字母 <code>a-z</code>&nbsp;组成。</p>

<p><strong>提示:</strong></p>

<ul>
	<li>你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？</li>
	<li>如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： <a href="/problems/implement-trie-prefix-tree/description/">实现Trie（前缀树）</a>。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Trie
{
public:
	Trie() {}
	void insert(string word)
	{
		Trie* node = this;
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

	bool search(string word)
	{
		Trie* node = this;
		for (auto c : word)
		{
			if (node->next[c - 'a'] == nullptr) return false;
			node = node->next[c - 'a'];
		}
		return node->is_string;
	}

	bool startsWith(string prefix)
	{
		Trie* node = this;
		for (auto c : prefix)
		{
			if (node->next[c - 'a'] == nullptr) return false;
			node = node->next[c - 'a'];
		}
		return true;
	}

private:
	bool is_string = false;
	Trie* next[26] = { nullptr };
};

class Solution {
public:
void find(vector<vector<char>>& board, int x, int y, string fstr, set<vector<int>> &vi, set<string>& ret, Trie& trie, vector<vector<int>>& dd)
{
	if (vi.count({ x, y }) != 0) return;
	if (x < 0 || x >= board.size()) return;
	if (y < 0 || y >= board[0].size()) return;
	fstr += board[x][y];
	if (trie.search(fstr))
	{
		ret.insert(fstr);
	}
	if (!trie.startsWith(fstr)) return;

	vi.insert({ x, y });
	for (auto d : dd)
	{
		int dx = x + d[0];
		int dy = y + d[1];
		find(board, dx, dy, fstr, vi, ret, trie, dd);
	}
	vi.erase({ x, y });
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
{
	set<vector<int>> vi;
	set<string> ret;
	vector<vector<int>> dd = { {0, 1}, {0, -1}, {1,0},{-1,0} };

	Trie trie;
	for (auto w : words) trie.insert(w);

	for (int x = 0; x < board.size(); x++)
	{
		for (int y = 0; y < board[0].size(); y++)
		{
			find(board, x, y, "", vi, ret, trie, dd);
		}
	}

	vector<string> ans(ret.begin(), ret.end());
	return ans;
}
};
```




