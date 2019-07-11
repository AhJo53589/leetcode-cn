# `（中等）`  [779.k-th-symbol-in-grammar 第K个语法符号](https://leetcode-cn.com/problems/k-th-symbol-in-grammar/)

### 题目描述
<p>在第一行我们写上一个 <code>0</code>。接下来的每一行，将前一行中的<code>0</code>替换为<code>01</code>，<code>1</code>替换为<code>10</code>。</p>

<p>给定行数&nbsp;<code>N</code>&nbsp;和序数 <code>K</code>，返回第 <code>N</code> 行中第 <code>K</code>个字符。（<code>K</code>从1开始）</p>

<p><br>
<strong>例子:</strong></p>

<pre><strong>输入:</strong> N = 1, K = 1
<strong>输出:</strong> 0

<strong>输入:</strong> N = 2, K = 1
<strong>输出:</strong> 0

<strong>输入:</strong> N = 2, K = 2
<strong>输出:</strong> 1

<strong>输入:</strong> N = 4, K = 5
<strong>输出:</strong> 1

<strong>解释:</strong>
第一行: 0
第二行: 01
第三行: 0110
第四行: 01101001
</pre>

<p><br>
<strong>注意：</strong></p>

<ol>
	<li><code>N</code>&nbsp;的范围&nbsp;<code>[1, 30]</code>.</li>
	<li><code>K</code>&nbsp;的范围&nbsp;<code>[1, 2^(N-1)]</code>.</li>
</ol>


---
### 思路
```
```
[题解](https://leetcode-cn.com/problems/k-th-symbol-in-grammar/solution/di-kge-yu-fa-fu-hao-by-ikaruga-2/)

### 答题
``` C++
int kthGrammar(int N, int K) 
{
	if (N == 1) return 0;
	return (kthGrammar(N - 1, (K - 1) / 2 + 1) == 0) ? ((K - 1) % 2) : 1 - ((K - 1) % 2);
}
```

### 其它
方法 2：  
容易发现结果只取决于 K，与 N 无关。  
a[i] 由 a[i/2] 生成，i为偶数时不变，奇数时取反。  

举个例子：  
a[5]，奇数坐标，等于a[5/2]=a[2]取反，a[2]又等于a[1]，a[1]又等于a[0]取反。  
终止条件就是a[0],我们知道a[0]=0;  
只需要在折半的过程中根据奇偶进行取反即可。  


``` C++
int kthGrammar(int N, int K) 
{ 
	K--; //counting from 0 instead of 1
	bool r = 0; 
	while(K)
	{ 
		r ^= (K&1);
		K /= 2; 
	} 
	return r;
}
```


方法 3：  
当索引 K 写为二进制形式后（从 0 开始索引），后半部分的索引的第一位总是 1。

这意味着，当使用方法三中的算法时，我们翻转最终答案的次数仅仅是 K-1 的二进制表示中的 1 的个数。

```Java
public int kthGrammar(int N, int K) {
	return Integer.bitCount(K - 1) % 2;
}
```