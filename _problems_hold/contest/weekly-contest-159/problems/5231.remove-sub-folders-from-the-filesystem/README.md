# `（中等）`  [5231.remove-sub-folders-from-the-filesystem 删除子文件夹](https://leetcode-cn.com/contest/weekly-contest-159/problems/remove-sub-folders-from-the-filesystem/)

### 题目描述
<p>你是一位系统管理员，手里有一份文件夹列表 <code>folder</code>，你的任务是要删除该列表中的所有 <strong>子文件夹</strong>，并以 <strong>任意顺序</strong> 返回剩下的文件夹。</p>

<p>我们这样定义「子文件夹」：</p>

<ul>
	<li>如果文件夹&nbsp;<code>folder[i]</code>&nbsp;位于另一个文件夹&nbsp;<code>folder[j]</code>&nbsp;下，那么&nbsp;<code>folder[i]</code>&nbsp;就是&nbsp;<code>folder[j]</code>&nbsp;的子文件夹。</li>
</ul>

<p>文件夹的「路径」是由一个或多个按以下格式串联形成的字符串：</p>

<ul>
	<li><code>/</code>&nbsp;后跟一个或者多个小写英文字母。</li>
</ul>

<p>例如，<code>/leetcode</code>&nbsp;和&nbsp;<code>/leetcode/problems</code>&nbsp;都是有效的路径，而空字符串和&nbsp;<code>/</code>&nbsp;不是。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
<strong>输出：</strong>["/a","/c/d","/c/f"]
<strong>解释：</strong>"/a/b/" 是 "/a" 的子文件夹，而 "/c/d/e" 是 "/c/d" 的子文件夹。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>folder = ["/a","/a/b/c","/a/b/d"]
<strong>输出：</strong>["/a"]
<strong>解释：</strong>文件夹 "/a/b/c" 和 "/a/b/d/" 都会被删除，因为它们都是 "/a" 的子文件夹。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>folder = ["/a/b/c","/a/b/d","/a/b/ca"]
<strong>输出：</strong>["/a/b/c","/a/b/ca","/a/b/d"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= folder.length&nbsp;&lt;= 4 * 10^4</code></li>
	<li><code>2 &lt;= folder[i].length &lt;= 100</code></li>
	<li><code>folder[i]</code>&nbsp;只包含小写字母和 <code>/</code></li>
	<li><code>folder[i]</code>&nbsp;总是以字符 <code>/</code>&nbsp;起始</li>
	<li>每个文件夹名都是唯一的</li>
</ul>



---
### 思路
```
先按照字符串长短来排序，
使用set来记录文件夹，
对一个新的文件夹按照每一个/来截断，
如果跟set里记录都不一样，
把它记录到set里。
```


### 答题
``` C++
void check(unordered_set<string> &us, string &s)
{
	string t = "/";
	size_t i = 1;
	while (i < s.size())
	{
		i = s.find('/', i);
		i = (i == s.npos) ? s.size() : i;
		if (us.count(s.substr(0, i)) != 0) return;
		i++;
	}
	us.insert(s);
}

vector<string> removeSubfolders(vector<string>& folder)
{
	sort(folder.begin(), folder.end(), [](string &a, string&b)
	{
		return a.size() < b.size();
	});
	unordered_set<string> us;
	for (auto &s : folder)
	{
		check(us, s);
	}

	vector<string> ans(us.begin(), us.end());
	return ans;
}
```
