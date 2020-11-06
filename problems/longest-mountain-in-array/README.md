# `（中等）` [845.longest-mountain-in-array 数组中的最长山脉](https://leetcode-cn.com/problems/longest-mountain-in-array/)

### 题目描述
<p>我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “<em>山脉”</em>：</p>

<ul>
	<li><code>B.length &gt;= 3</code></li>
	<li>存在 <code>0 &lt; i&nbsp;&lt; B.length - 1</code> 使得 <code>B[0] &lt; B[1] &lt; ... B[i-1] &lt; B[i] &gt; B[i+1] &gt; ... &gt; B[B.length - 1]</code></li>
</ul>

<p>（注意：B 可以是 A 的任意子数组，包括整个数组 A。）</p>

<p>给出一个整数数组 <code>A</code>，返回最长 <em>“山脉”</em>&nbsp;的长度。</p>

<p>如果不含有 “<em>山脉”&nbsp;</em>则返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[2,1,4,7,3,2,5]
<strong>输出：</strong>5
<strong>解释：</strong>最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[2,2,2]
<strong>输出：</strong>0
<strong>解释：</strong>不含 “山脉”。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>0 &lt;= A.length &lt;= 10000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 10000</code></li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int longestMountain(vector<int>& A) {
		int ans = 0;
		int st = 0;
		int cnt = 1;
		for (int i = 1; i < A.size(); i++) {
			if (A[i] == A[i - 1]) {
				st = 0;
				cnt = 1;
				continue;
			}

			switch (st) {
			case 0:
				if (A[i] > A[i - 1]) {
					st = 1;
					cnt++;
				}
				break;
			case 1:
				if (A[i] < A[i - 1]) {
					st = 2;
				}
                cnt++;
				break;
			case 2:
				if (A[i] < A[i - 1]) {
					cnt++;
				}
				else {
					st = 1;
					cnt = 2;
				}
				break;
			}

			ans = (st == 2) ? max(ans, cnt) : ans;
		}
		return ans;
    }
};
```




