# `（简单）`  [202.happy-number 快乐数](https://leetcode-cn.com/problems/happy-number/)

### 题目描述
<p>编写一个算法来判断一个数是不是“快乐数”。</p>

<p>一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。</p>

<p><strong>示例:&nbsp;</strong></p>

<pre><strong>输入:</strong> 19
<strong>输出:</strong> true
<strong>解释: 
</strong>1<sup>2</sup> + 9<sup>2</sup> = 82
8<sup>2</sup> + 2<sup>2</sup> = 68
6<sup>2</sup> + 8<sup>2</sup> = 100
1<sup>2</sup> + 0<sup>2</sup> + 0<sup>2</sup> = 1
</pre>


---
### 思路
```
使用set来检测循环。  
```

### 答题
``` C++
unordered_set<int> visited;
bool isHappy(int n) 
{
	if (visited.count(n)) return false;
	visited.insert(n);

	int s = 0;
	while (n > 0)
	{
		s += pow((n % 10), 2);
		n /= 10;
	}
	if (s == 1) return true;
	return isHappy(s);
}
```


