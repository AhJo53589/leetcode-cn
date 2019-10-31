# `（中等）` [390.elimination-game 消除游戏](https://leetcode-cn.com/problems/elimination-game/)

### 题目描述
<p>给定一个从1 到 n 排序的整数列表。<br>
首先，从左到右，从第一个数字开始，每隔一个数字进行删除，直到列表的末尾。<br>
第二步，在剩下的数字中，从右到左，从倒数第一个数字开始，每隔一个数字进行删除，直到列表开头。<br>
我们不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。<br>
返回长度为 n 的列表中，最后剩下的数字。</p>

<p><strong>示例：</strong></p>
<pre><strong>输入:</strong>
n = 9,
<u>1</u> 2 <u>3</u> 4 <u>5</u> 6 <u>7</u> 8 <u>9</u>
2 <u>4</u> 6 <u>8</u>
<u>2</u> 6
6

<strong>输出:</strong>
6</pre>

---
### 思路
```
一开始使用数组模拟过程，但是太慢了，且量级大了之后内存也不行。
陷入了找规律的泥潭。
后来看了题解发现也是模拟过程，只不过不用数组，只需计算返回的数值。
```



### 答题
``` C++
int lastRemaining(int n) 
{
	int time = 0;
	int factor = 1;
	int len = n;
	while (len != 1) 
	{
		time++;
		if (time % 2 == 0 || len % 2 == 1) 
		{
			n -= factor;
		}
		factor <<= 1;
		len >>= 1;
	}
	return n;
}
```




