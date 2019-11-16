# `（中等）` [5108.encode-number 加密数字](https://leetcode-cn.com/problems/encode-number/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-13/problems/encode-number/)

### 题目描述
<p>给你一个非负整数 <code>num</code> ，返回它的「加密字符串」。</p>

<p>加密的过程是把一个整数用某个未知函数进行转化，你需要从下表推测出该转化函数：</p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/16/encode_number.png" style="height: 360px; width: 164px;"></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 23
<strong>输出：</strong>"1000"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 107
<strong>输出：</strong>"101100"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 10^9</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
string encode(int num) 
{
	if (num == 0) return "";

	int i = 1;
	while (true)
	{
		int n = 1 << i;
		if (num <= n)
		{
			num--;
			string ans = "";
			while (num != 0)
			{
				ans += to_string(num % 2);
				num /= 2;
			}
			while (ans.size() != i)
			{
				ans += "0";
			}
			reverse(ans.begin(), ans.end());
			return ans;
		}
		num -= n;
		i++;
	}
}
```




