# `（中等）` [5325.number-of-substrings-containing-all-three-characters 包含所有三种字符的子字符串数目](https://leetcode-cn.com/problems/number-of-substrings-containing-all-three-characters/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-20/problems/number-of-substrings-containing-all-three-characters/)

### 题目描述

              <p>给你一个字符串 <code>s</code>&nbsp;，它只包含三种字符 a, b 和 c 。</p>

<p>请你返回 a，b 和 c 都&nbsp;<strong>至少&nbsp;</strong>出现过一次的子字符串数目。</p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>s = "abcabc"
<strong>输出：</strong>10
<strong>解释：</strong>包含 a，b 和 c 各至少一次的子字符串为<em> "</em>abc<em>", "</em>abca<em>", "</em>abcab<em>", "</em>abcabc<em>", "</em>bca<em>", "</em>bcab<em>", "</em>bcabc<em>", "</em>cab<em>", "</em>cabc<em>" </em>和<em> "</em>abc<em>" </em>(<strong>相同</strong><strong>字符串算多次</strong>)<em>。</em>
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>s = "aaacb"
<strong>输出：</strong>3
<strong>解释：</strong>包含 a，b 和 c 各至少一次的子字符串为<em> "</em>aaacb<em>", "</em>aacb<em>" </em>和<em> "</em>acb<em>" 。</em>
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>s = "abc"
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>3 &lt;= s.length &lt;= 5 x 10^4</code></li>
	<li><code>s</code>&nbsp;只包含字符 a，b 和 c 。</li>
</ul>

​            

---
### 思路
```

```

[发布的题解](https://leetcode-cn.com/problems/number-of-substrings-containing-all-three-characters/solution/5325-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
	bool getAll(vector<int>& vi)
	{
		for (auto n : vi)
		{
			if (n == 0) return false;
		}
		return true;
	}

    int numberOfSubstrings(string s) 
	{
		int ans = 0;
		int left = 0;
		vector<int> vi(3, 0);
		queue<int> que;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c')
			{
				//cout << endl << "[" << i << "]\t" << s[i] << endl;
				vi[s[i] - 'a']++;
				que.push(i);

				while (getAll(vi))
				{
					int a = que.front() - left + 1;
					int b = s.size() - i;
					ans += a * b;
					//cout << "a = " << a << ", b = " << b << ", a * b = " << a * b << endl;

					vi[s[que.front()] - 'a']--;
					que.pop();
					left = que.front();
					//cout << "left -> " << left << endl;
				}
			}
		}

		return ans;
    }
};
```




