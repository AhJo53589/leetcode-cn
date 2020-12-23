# `（简单）` [1694.reformat-phone-number 重新格式化电话号码](https://leetcode-cn.com/problems/reformat-phone-number/)

[contest](https://leetcode-cn.com/contest/weekly-contest-220/problems/reformat-phone-number/)

### 题目描述
<p>给你一个字符串形式的电话号码 <code>number</code> 。<code>number</code> 由数字、空格 <code>' '</code>、和破折号 <code>'-'</code> 组成。</p>

<p>请你按下述方式重新格式化电话号码。</p>

<ul>
	<li>首先，<strong>删除</strong> 所有的空格和破折号。</li>
	<li>其次，将数组从左到右 <strong>每 3 个一组</strong> 分块，<strong>直到 </strong>剩下 4 个或更少数字。剩下的数字将按下述规定再分块：
	<ul>
		<li>2 个数字：单个含 2 个数字的块。</li>
		<li>3 个数字：单个含 3 个数字的块。</li>
		<li>4 个数字：两个分别含 2 个数字的块。</li>
	</ul>
	</li>
</ul>

<p>最后用破折号将这些块连接起来。注意，重新格式化过程中 <strong>不应该</strong> 生成仅含 1 个数字的块，并且 <strong>最多</strong> 生成两个含 2 个数字的块。</p>

<p>返回格式化后的电话号码。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>number = "1-23-45 6"
<strong>输出：</strong>"123-456"
<strong>解释：</strong>数字是 "123456"
步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
步骤 2：剩下 3 个数字，将它们放入单个含 3 个数字的块。第 2 个块是 "456" 。
连接这些块后得到 "123-456" 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>number = "123 4-567"
<strong>输出：</strong>"123-45-67"
<strong>解释：</strong>数字是 "1234567".
步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
步骤 2：剩下 4 个数字，所以将它们分成两个含 2 个数字的块。这 2 块分别是 "45" 和 "67" 。
连接这些块后得到 "123-45-67" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>number = "123 4-5678"
<strong>输出：</strong>"123-456-78"
<strong>解释：</strong>数字是 "12345678" 。
步骤 1：第 1 个块 "123" 。
步骤 2：第 2 个块 "456" 。
步骤 3：剩下 2 个数字，将它们放入单个含 2 个数字的块。第 3 个块是 "78" 。
连接这些块后得到 "123-456-78" 。</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>number = "12"
<strong>输出：</strong>"12"
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>number = "--17-5 229 35-39475 "
<strong>输出：</strong>"175-229-353-94-75"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= number.length &lt;= 100</code></li>
	<li><code>number</code> 由数字和字符 <code>'-'</code> 及 <code>' '</code> 组成。</li>
	<li><code>number</code> 中至少含 <strong>2</strong> 个数字。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    string reformatNumber(string number) {
		string s;
		for (auto& c : number) {
			if (c == '-' || c == ' ') continue;
			s += c;
		}
		string ans;
		for (int i = 0; i < s.size();) {
			if (s.size() - i > 4) {
				ans += s.substr(i, 3);
				ans += "-";
				i += 3;
				continue;
			}

			if (s.size() - i == 2) {
				ans += s.substr(i, 2);
				i += 2;
			}
			else if (s.size() - i == 3) {
				ans += s.substr(i, 3);
				i += 3;
			}
			else {
				ans += s.substr(i, 2);
				ans += "-";
				i += 2;
			}
		}
		return ans;
    }
};
```




