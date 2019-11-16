# `（中等）` [5110.synonymous-sentences 近义词句子](https://leetcode-cn.com/problems/synonymous-sentences/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-13/problems/synonymous-sentences/)

### 题目描述
<p>给你一个近义词表&nbsp;<code>synonyms</code> 和一个句子&nbsp;<code>text</code>&nbsp;，&nbsp;<code>synonyms</code> 表中是一些近义词对 ，你可以将句子&nbsp;<code>text</code> 中每个单词用它的近义词来替换。</p>
<p>请你找出所有用近义词替换后的句子，按&nbsp;<strong>字典序排序</strong>&nbsp;后返回。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：
</strong>synonyms = [["happy","joy"],["sad","sorrow"],["joy","cheerful"]],
text = "I am happy today but was sad yesterday"
<strong>输出：
</strong>["I am cheerful today but was sad yesterday",
"I am cheerful today but was sorrow yesterday",
"I am happy today but was sad yesterday",
"I am happy today but was sorrow yesterday",
"I am joy today but was sad yesterday",
"I am joy today but was sorrow yesterday"]
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>0 &lt;=&nbsp;synonyms.length &lt;= 10</code></li>
	<li><code>synonyms[i].length == 2</code></li>
	<li><code>synonyms[0] != synonyms[1]</code></li>
	<li>所有单词仅包含英文字母，且长度最多为&nbsp;<code>10</code> 。</li>
	<li><code>text</code>&nbsp;最多包含&nbsp;<code>10</code> 个单词，且单词间用单个空格分隔开。</li>
</ul>

​            

---
### 思路
```

```



### 答题
``` C++
void generateSentences(vector<vector<string>>& synonyms, vector<string> words, size_t id, vector<string> &ans, unordered_set<string> us)
{
	if (id == words.size())
	{
		string temp;
		for (auto w : words)
		{
			temp += w;
			temp += " ";
		}
		temp.pop_back();
		ans.push_back(temp);
		return;
	}

	if (us.count(words[id])) return;
	us.insert(words[id]);

	for (auto vs : synonyms)
	{
		if (words[id] == vs[0])
		{
			words[id] = vs[1];
			generateSentences(synonyms, words, id, ans, us);
			words[id] = vs[0];
		}
		if (words[id] == vs[1])
		{
			words[id] = vs[0];
			generateSentences(synonyms, words, id, ans, us);
			words[id] = vs[1];
		}
	}
	us.clear();
	generateSentences(synonyms, words, id + 1, ans, us);
}

vector<string> generateSentences(vector<vector<string>>& synonyms, string text) 
{
	stringstream ss(text);
	vector<string> words;
	string temp;
	while (ss >> temp)
	{
		words.push_back(temp);
	}
	vector<string> ans;
	unordered_set<string> us;
	generateSentences(synonyms, words, 0, ans, us);
	sort(ans.begin(), ans.end());
	return ans;
}
```




