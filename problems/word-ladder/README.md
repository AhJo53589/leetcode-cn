# `（中等）` [127.word-ladder 单词接龙](https://leetcode-cn.com/problems/word-ladder/)

### 题目描述
<p>给定两个单词（<em>beginWord&nbsp;</em>和 <em>endWord</em>）和一个字典，找到从&nbsp;<em>beginWord</em> 到&nbsp;<em>endWord</em> 的最短转换序列的长度。转换需遵循如下规则：</p>
<ol>
	<li>每次转换只能改变一个字母。</li>
	<li>转换过程中的中间单词必须是字典中的单词。</li>
</ol>

<p><strong>说明:</strong></p>
<ul>
	<li>如果不存在这样的转换序列，返回 0。</li>
	<li>所有单词具有相同的长度。</li>
	<li>所有单词只由小写字母组成。</li>
	<li>字典中不存在重复的单词。</li>
	<li>你可以假设 <em>beginWord</em> 和 <em>endWord </em>是非空的，且二者不相同。</li>
</ul>

<p><strong>示例&nbsp;1:</strong></p>
<pre><strong>输入:</strong>
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

<strong>输出: </strong>5

<strong>解释: </strong>一个最短转换序列是 "hit" -&gt; "hot" -&gt; "dot" -&gt; "dog" -&gt; "cog",
     返回它的长度 5。
</pre>

<p><strong>示例 2:</strong></p>
<pre><strong>输入:</strong>
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

<strong>输出:</strong>&nbsp;0

<strong>解释:</strong>&nbsp;<em>endWord</em> "cog" 不在字典中，所以无法进行转换。</pre>

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/word-ladder/solution/127-by-ikaruga/)

### 答题
``` C++
int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
	if (beginWord == endWord) return 1;
	bool flag = true;

	map<string, vector<string>> comboList;
	for (auto w : wordList)
	{
		if (w == endWord)
		{
			flag = false;
		}
		for (size_t i = 0; i < w.size(); i++)
		{
			auto temp = w;
			temp[i] = '*';
			comboList[temp].push_back(w);
		}
	}
	if (flag) return 0;

	unordered_map<string, int> vi[2];
	queue<string> que[2];
	que[0].push(beginWord);
	vi[0][beginWord] = 1;
	que[1].push(endWord);
	vi[1][endWord] = 1;

	while (!que[0].empty() || !que[1].empty())
	{
		int k = (que[0].size() < que[1].size()) ? 0 : 1;
		k = (que[k].size() == 0) ? (k + 1) % 2 : k;
		
		for (int i = que[k].size(); i > 0; i--)
		{
			auto q = que[k].front();
			que[k].pop();

			for (size_t i = 0; i < q.size(); i++)
			{
				auto temp = q;
				temp[i] = '*';

				for (auto w : comboList[temp])
				{
					if (vi[k].count(w) != 0) continue;
					int k2 = (k + 1) % 2;
					if (vi[k2].count(w) != 0)
					{
						return vi[k2][w] + vi[k][q];
					}

					que[k].push(w);
					vi[k][w] = vi[k][q] + 1;
				}
			}
		}
	}

	return 0;
}

```


### 其它
``` C++
int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
	unordered_set<string> wordDict(wordList.begin(), wordList.end());
	if (wordDict.find(endWord) == wordDict.end()) return 0;

	unordered_set<string> beginSet{ beginWord };
	unordered_set<string> endSet{ endWord };
	int step = 1;
	while (!beginSet.empty()) 
	{
		unordered_set<string> tempSet;
		++step;

		for (auto s : beginSet) // 对wordDict去重,避免重复计算
		{
			wordDict.erase(s);
		}

		for (auto s : beginSet) 
		{
			for (int i = 0; i < s.size(); ++i) 
			{
				string str = s;   // str是beginSet中的一个字符串
				for (char c = 'a'; c <= 'z'; ++c) 
				{
					str[i] = c;   // 此时str是beginSet中的某个字符串替换一个字符后的字符串

					if (wordDict.count(str) == 0) continue;	// wordDict中没有beginSet中的某个字符串替换一个字符后的字符串
					if (endSet.count(str) > 0) return step; // endSet中有str（即endSet中有beginSet中的某个字符串替换一个字符后的字符串）
						
					tempSet.insert(str);  // 此时的str存在于wordDict中，但是不在endSet中。（还没找到）
				}
			}
		}

		if (tempSet.size() < endSet.size()) 
		{
			beginSet = tempSet;
		}
		else
		{
			beginSet = endSet;
			endSet = tempSet;
		}
	}

	return 0;
}
```


