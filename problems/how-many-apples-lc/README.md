# `（中等）` [100264.how-many-apples-lc 分苹果](https://leetcode-cn.com/problems/how-many-apples-lc/)

[contest](https://leetcode-cn.com/contest/sf-2020/problems/how-many-apples-lc/)

### 题目描述
<p>有一堆苹果，将这堆苹果平分成<code>n</code>份之后，多了<code>k</code>个苹果，从<code>n</code>份中了取走<code>k</code>份并取走平分后多的<code>k</code>个苹果。</p>

<p>上述操作重复了<code>n</code>次之后，发现最后剩余的苹果依然可以平分成<code>n</code>份并剩余<code>k</code>个。请你返回这堆苹果最少可能有多少个。</p>

<p>注意：</p>

<ol>
	<li>答案需要取模&nbsp;<code>1e9 + 7 (1000000007)</code>，如：计算初始结果为：<code>1000000008</code>，请返回&nbsp;<code>1</code></li>
	<li>数量<code>k</code>可以被分成<code>n</code>份并剩余<code>k</code>个，每份是<code>0</code>.</li>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2, k = 1
<strong>输出：</strong>7
<strong>解释：</strong>第一次把 7 分成 [3,3,1] ，取走了3+1
第二次把 3 分成 [1,1,1] ，取走了1+1
最后把 1 还可以分成 [0,0,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 3, k = 1
<strong>输出：</strong>79
<strong>解释：</strong>第一次把 7 分成 [26,26,26,1] ，取走了26+1
第二次把 52 分成 [17,17,17,1] ，取走了17+1
第三次把 34 分成 [11,11,11,1] ，取走了11+1
最后把 22 还可以分成 [7,7,7,1]</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 4, k = 2
<strong>输出：</strong>62
<strong>解释：</strong>第一次把 62 分成 [15,15,15,15,2] ，取走了15+15+2
第二次把 30 分成 [7,7,7,7,2] ，取走了7+7+2
第三次把 14 分成 [3,3,3,3,2] ，取走了3+3+2
第四次把 6 还可以分成 [1,1,1,1,2]， 取走了1+1+2
最后把 2 分成 [0,0,0,0,2]
</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt; n</code></li>
</ul>

<p>&nbsp;</p>

            

---
### 思路
```
```



### 答题
``` C++
const int MOD = 1e9 + 7;
class Solution {
public:
	long long power_mod(long long a, int n) {
		long long ret = 1;
		for (; n; n >>= 1) {
			if (n & 1) ret = ret * a % MOD;
			a = a * a % MOD;
		}
		return ret;
	}
	int findNum(int n, int k) {
		int u = n / gcd(n, k);
		int ret = power_mod(u, n) * n % MOD;
		ret = (ret + MOD + k - n) % MOD;
		return ret;
	}
};
```




