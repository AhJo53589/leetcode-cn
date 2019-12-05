# `（中等）` [1268.search-suggestions-system 搜索推荐系统](https://leetcode-cn.com/problems/search-suggestions-system/)

[contest](https://leetcode-cn.com/contest/weekly-contest-164/problems/search-suggestions-system/)

### 题目描述
<p>给你一个产品数组&nbsp;<code>products</code>&nbsp;和一个字符串&nbsp;<code>searchWord</code>&nbsp;，<code>products</code>&nbsp; 数组中每个产品都是一个字符串。</p>

<p>请你设计一个推荐系统，在依次输入单词&nbsp;<code>searchWord</code> 的每一个字母后，推荐&nbsp;<code>products</code> 数组中前缀与&nbsp;<code>searchWord</code> 相同的最多三个产品。如果前缀相同的可推荐产品超过三个，请按字典序返回最小的三个。</p>

<p>请你以二维列表的形式，返回在输入&nbsp;<code>searchWord</code>&nbsp;每个字母后相应的推荐产品的列表。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
<strong>输出：</strong>[
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
<strong>解释：</strong>按字典序排序后的产品列表是 ["mobile","moneypot","monitor","mouse","mousepad"]
输入 m 和 mo，由于所有产品的前缀都相同，所以系统返回字典序最小的三个产品 ["mobile","moneypot","monitor"]
输入 mou， mous 和 mouse 后系统都返回 ["mouse","mousepad"]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>products = ["havana"], searchWord = "havana"
<strong>输出：</strong>[["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
<strong>输出：</strong>[["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>products = ["havana"], searchWord = "tatiana"
<strong>输出：</strong>[[],[],[],[],[],[],[]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= products.length &lt;= 1000</code></li>
	<li><code>1 &lt;= Σ products[i].length &lt;= 2 * 10^4</code></li>
	<li><code>products[i]</code>&nbsp;中所有的字符都是小写英文字母。</li>
	<li><code>1 &lt;= searchWord.length &lt;= 1000</code></li>
	<li><code>searchWord</code>&nbsp;中所有字符都是小写英文字母。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
size_t find(vector<string>& p, size_t pos, char c, size_t lo, size_t hi)
{
	while (lo < hi)
	{
		size_t md = lo + (hi - lo) / 2;
		if (p[md][pos] < c)
		{
			lo = md + 1;
		}
		else
		{
			hi = md;
		}
	}
	return lo;
}

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
{
    sort(products.begin(), products.end());

    vector<vector<string>> ans(searchWord.size(), vector<string>());
	size_t lo = 0;
	size_t hi = products.size();
    for (size_t i = 0; i < ans.size(); i++)
    {            
		lo = find(products, i, searchWord[i], lo, hi);
		hi = find(products, i, searchWord[i] + 1, lo, hi);
		for (size_t j = lo; j < hi; j++)
		{
			if (ans[i].size() == 3) break;
			ans[i].push_back(products[j]);
		}
	}
    return ans;
}
```




