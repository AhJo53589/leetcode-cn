# `（中等）` [5316.print-words-vertically 竖直打印单词](https://leetcode-cn.com/problems/print-words-vertically/)

[contest](https://leetcode-cn.com/contest/weekly-contest-172/problems/print-words-vertically/)

### 题目描述
<p>给你一个字符串&nbsp;<code>s</code>。请你按照单词在 <code>s</code> 中的出现顺序将它们全部竖直返回。<br>
单词应该以字符串列表的形式返回，必要时用空格补位，但输出尾部的空格需要删除（不允许尾随空格）。<br>
每个单词只能放在一列上，每一列中也只能有一个单词。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "HOW ARE YOU"
<strong>输出：</strong>["HAY","ORO","WEU"]
<strong>解释：</strong>每个单词都应该竖直打印。 
 "HAY"
&nbsp;"ORO"
&nbsp;"WEU"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "TO BE OR NOT TO BE"
<strong>输出：</strong>["TBONTB","OEROOE","   T"]
<strong>解释：</strong>题目允许使用空格补位，但不允许输出末尾出现空格。
"TBONTB"
"OEROOE"
"   T"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "CONTEST IS COMING"
<strong>输出：</strong>["CIC","OSO","N M","T I","E N","S G","T"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 200</code></li>
	<li><code>s</code>&nbsp;仅含大写英文字母。</li>
	<li>题目数据保证两个单词之间只有一个空格。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
void trimR(string& input)
{
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

vector<string> printVertically(string s)
{
	stringstream ss(s);
	vector<string> aa;
	string temp;
	while (ss >> temp)
	{
		aa.push_back(temp);
	}
	vector<string> ans;

	bool flag = true;
	size_t i = 0;
	while (flag)
	{
		flag = false;
		temp = "";
		for (auto& a : aa)
		{
			if (i >= a.size())
			{
				temp += " ";
			}
			else
			{
				flag = true;
				temp += a[i];
			}
		}
		trimR(temp);
		ans.push_back(temp);
		i++;
	}
	ans.pop_back();
	return ans;
}
```




