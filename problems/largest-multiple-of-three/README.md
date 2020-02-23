# `（困难）` [5172.largest-multiple-of-three 形成三的最大倍数](https://leetcode-cn.com/problems/largest-multiple-of-three/)

[contest](https://leetcode-cn.com/contest/weekly-contest-177/problems/largest-multiple-of-three/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>digits</code>，你可以通过按任意顺序连接其中某些数字来形成 <strong>3</strong> 的倍数，请你返回所能得到的最大的 3 的倍数。</p>

<p>由于答案可能不在整数数据类型范围内，请以字符串形式返回答案。</p>

<p>如果无法得到答案，请返回一个空字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>digits = [8,1,9]
<strong>输出：</strong>"981"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>digits = [8,6,7,1,0]
<strong>输出：</strong>"8760"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>digits = [1]
<strong>输出：</strong>""
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>digits = [0,0,0,0,0,0]
<strong>输出：</strong>"0"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= digits.length &lt;= 10^4</code></li>
	<li><code>0 &lt;= digits[i] &lt;= 9</code></li>
	<li>返回的结果不应包含不必要的前导零。</li>
</ul>

            

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/largest-multiple-of-three/solution/5172-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
	bool deleteNum(vector<int>& cnt, int n)
	{
		for (int i = n; i <= 9; i += 3)
		{
			if (cnt[i] != 0)
			{
				cnt[i]--;
				return true;
			}
		}
		return false;
	}

	string largestMultipleOfThree(vector<int>& digits) 
	{
		vector<int> cnt(10, 0);
		int sum = 0;
		for (auto& d : digits)
		{
			sum += d;
			cnt[d]++;
		}

		if (cnt[0] == digits.size()) return "0";
		if (sum % 3 != 0)
		{
			int a = sum % 3;
			int b = 3 - a;
			if (!deleteNum(cnt, a))
			{
				deleteNum(cnt, b);
				deleteNum(cnt, b);
			}
		}

		string ans;
		for (int i = cnt.size() - 1; i < cnt.size(); i--)
		{
			while (cnt[i]-- != 0)
			{
				ans += to_string(i);
			}
		}
		return ans;
	}
};
```




