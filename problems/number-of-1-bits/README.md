# `（简单）` [191.number-of-1-bits 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)

### 题目描述
<p>编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’&nbsp;的个数（也被称为<a href="https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E9%87%8D%E9%87%8F">汉明重量</a>）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>00000000000000000000000000001011
<strong>输出：</strong>3
<strong>解释：</strong>输入的二进制串 <code><strong>00000000000000000000000000001011</strong>&nbsp;中，共有三位为 '1'。</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>00000000000000000000000010000000
<strong>输出：</strong>1
<strong>解释：</strong>输入的二进制串 <strong>00000000000000000000000010000000</strong>&nbsp;中，共有一位为 '1'。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>11111111111111111111111111111101
<strong>输出：</strong>31
<strong>解释：</strong>输入的二进制串 <strong>11111111111111111111111111111101</strong> 中，共有 31 位为 '1'。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。</li>
	<li>在 Java 中，编译器使用<a href="https://baike.baidu.com/item/二进制补码/5295284">二进制补码</a>记法来表示有符号整数。因此，在上面的&nbsp;<strong>示例 3</strong>&nbsp;中，输入表示有符号整数 <code>-3</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶</strong>:<br>
如果多次调用这个函数，你将如何优化你的算法？</p>


---
### 思路
```
n &= (n - 1);
会将最后一个1的位从1变为0。
```

### 答题
``` C++
int hammingWeight(uint32_t n)
{
	int sum = 0;
	while (n != 0)
	{
		n &= (n - 1);
		sum++;
	}
	return sum;
}
```

