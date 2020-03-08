# `（简单）` [5352.generate-a-string-with-characters-that-have-odd-counts 生成每种字符都是奇数个的字符串](https://leetcode-cn.com/problems/generate-a-string-with-characters-that-have-odd-counts/)

[contest](https://leetcode-cn.com/contest/weekly-contest-179/problems/generate-a-string-with-characters-that-have-odd-counts/)

### 题目描述
<p>给你一个整数 <code>n</code>，请你返回一个含<em> <code>n</code> </em>个字符的字符串，其中每种字符在该字符串中都恰好出现 <strong>奇数次</strong> <em><strong>。</strong></em></p>

<p>返回的字符串必须只含小写英文字母。如果存在多个满足题目要求的字符串，则返回其中任意一个即可。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 4
<strong>输出：</strong>"pppz"
<strong>解释：</strong>"pppz" 是一个满足题目要求的字符串，因为 'p' 出现 3 次，且 'z' 出现 1 次。当然，还有很多其他字符串也满足题目要求，比如："ohhh" 和 "love"。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>"xy"
<strong>解释：</strong>"xy" 是一个满足题目要求的字符串，因为 'x' 和 'y' 各出现 1 次。当然，还有很多其他字符串也满足题目要求，比如："ag" 和 "ur"。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 7
<strong>输出：</strong>"holasss"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
string generateTheString(int n) 
{
    string ans = (n % 2 == 0) ? "a" : "";
    n -= (n % 2 == 0);
    for (int i = 0; i < n; i++)
    {
        ans += "b";
    }
    return ans;
}
```




