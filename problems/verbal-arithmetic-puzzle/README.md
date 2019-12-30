# `（困难）` [1307.verbal-arithmetic-puzzle 口算难题](https://leetcode-cn.com/problems/verbal-arithmetic-puzzle/)

[contest](https://leetcode-cn.com/contest/weekly-contest-169/problems/verbal-arithmetic-puzzle/)

### 题目描述
<p>给你一个方程，左边用&nbsp;<code>words</code>&nbsp;表示，右边用&nbsp;<code>result</code> 表示。</p>

<p>你需要根据以下规则检查方程是否可解：</p>

<ul>
	<li>每个字符都会被解码成一位数字（0 - 9）。</li>
	<li>每对不同的字符必须映射到不同的数字。</li>
	<li>每个 <code>words[i]</code> 和 <code>result</code>&nbsp;都会被解码成一个没有前导零的数字。</li>
	<li>左侧数字之和（<code>words</code>）等于右侧数字（<code>result</code>）。&nbsp;</li>
</ul>

<p>如果方程可解，返回&nbsp;<code>True</code>，否则返回&nbsp;<code>False</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = ["SEND","MORE"], result = "MONEY"
<strong>输出：</strong>true
<strong>解释：</strong>映射 'S'-&gt; 9, 'E'-&gt;5, 'N'-&gt;6, 'D'-&gt;7, 'M'-&gt;1, 'O'-&gt;0, 'R'-&gt;8, 'Y'-&gt;'2'
所以 "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
<strong>输出：</strong>true
<strong>解释：</strong>映射 'S'-&gt; 6, 'I'-&gt;5, 'X'-&gt;0, 'E'-&gt;8, 'V'-&gt;7, 'N'-&gt;2, 'T'-&gt;1, 'W'-&gt;'3', 'Y'-&gt;4
所以 "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>words = ["THIS","IS","TOO"], result = "FUNNY"
<strong>输出：</strong>true
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>words = ["LEET","CODE"], result = "POINT"
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= words.length &lt;= 5</code></li>
	<li><code>1 &lt;= words[i].length,&nbsp;results.length&nbsp;&lt;= 7</code></li>
	<li><code>words[i], result</code>&nbsp;只含有大写英文字母</li>
	<li>表达式中使用的不同字符数最大为&nbsp;10</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/verbal-arithmetic-puzzle/solution/1307-by-ikaruga/)

### 答题
``` C++
bool check(vector<vector<int>>& eq, int lv, vector<int>& en, int& inc)
{
	auto& cur_eq = eq[lv];
	int sum = inc;
	for (int i = 0; i < cur_eq.size(); i++)
	{
		sum += cur_eq[i] * en[i];
	}
	inc = sum / 10;
	return (sum % 10 == 0);
}

void dfs(vector<vector<int>>& eq, vector<vector<char>>& chars, int lv, int idx, int inc, vector<char>& ne, vector<int>& en, vector<bool>& zeroFlag, bool& ans)
{
	if (ans) return;
	if (idx == chars[lv].size())
	{
		//for (size_t i = 0; i < 26; i++)
		//{
		//	if (en[i] == -1) continue;
		//	char c = i + 'A';
		//	cout << c << ": " << en[i] << "\t";
		//}
		if (!check(eq, lv, en, inc))
		{
			//cout << "check failed" << endl;
			return;
		}
		//cout << "check success!" << endl;

		if (lv == 7)
		{
			ans = true;
			return;
		}
		dfs(eq, chars, lv + 1, 0, inc, ne, en, zeroFlag, ans);
	}

	auto& cur_eq = eq[lv];
	auto& cur_ch = chars[lv];

	if (idx < 0 || idx >= cur_ch.size()) return;
	char c = cur_ch[idx];
	for (int n = 0; n < 10; n++)
	{
		if (ne[n] != 'a') continue;
		if (n == 0 && zeroFlag[c - 'A']) continue;

		en[c - 'A'] = n;
		ne[n] = c;

		dfs(eq, chars, lv, idx + 1, inc, ne, en, zeroFlag, ans);

		en[c - 'A'] = -1;
		ne[n] = 'a';
	}
}

bool isSolvable(vector<string>& words, string result) 
{
	vector<char> ne(10, 'a');
	vector<int> en(26, -1);
	vector<bool> zeroFlag(26, false);
	vector<vector<int>> equation(8, vector<int>(26, 0));
	vector<vector<char>> chars(8, vector<char>());

	words.push_back(result);
	for (size_t j = 0; j < words.size(); j++)
	{
		auto w = words[j];
		zeroFlag[w[0] - 'A'] = true;
		size_t d = 0;
		for (size_t i = w.size() - 1; i < w.size(); i--)
		{
			equation[d++][w[i] - 'A'] += (j == words.size() - 1) ? -1 : 1;
		}
	}
	unordered_set<char> us;
	for (size_t d = 0; d < 8; d++)
	{
		for (int i = 0; i < equation[d].size(); i++)
		{
			if (equation[d][i] == 0) continue;
			char c = i + 'A';
			if (us.count(c) != 0) continue;
			chars[d].push_back(c);
			us.insert(c);
		}
	}

	bool ans = false;
	dfs(equation, chars, 0, 0, 0, ne, en, zeroFlag, ans);
	return ans;
}
```




