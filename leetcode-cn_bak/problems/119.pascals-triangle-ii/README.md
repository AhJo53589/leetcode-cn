# `（简单）`  [119.pascals-triangle-ii 杨辉三角 II](https://leetcode-cn.com/problems/pascals-triangle-ii/)

### 题目描述
<p>给定一个非负索引&nbsp;<em>k</em>，其中 <em>k</em>&nbsp;≤&nbsp;33，返回杨辉三角的第 <em>k </em>行。</p>

<p><img src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif" alt=""></p>

<p><small>在杨辉三角中，每个数是它左上方和右上方的数的和。</small></p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 3
<strong>输出:</strong> [1,3,3,1]
</pre>

<p><strong>进阶：</strong></p>

<p>你可以优化你的算法到 <em>O</em>(<em>k</em>) 空间复杂度吗？</p>


---
### 思路
```
```

### 答题
``` C++
vector<int> getRow(int rowIndex) 
{
	if (rowIndex < 0)
		return vector<int>();
	vector<int> res(rowIndex + 1, 0);
	res[0] = 1;
	for (int i = 1; i <= rowIndex; ++i)
		for (int j = i; j >= 1; --j) 
		{
			res[j] += res[j - 1];
		}
	return res;
}
```

### 其它
``` C++
// 根据组合数公式C(n,i)=n!/(i!*(n-i)!)直接由C(n,i)算C(n,i+1),后者是前者的(n-i)/(i+1)倍
vector<int> getRow(int rowIndex)
{
	vector<int> res;
	if (rowIndex < 0) return res;
	res.push_back(1);
	for (int i = 0; i < rowIndex; ++i)
		res.push_back(static_cast<int>(double(res[i])*(rowIndex - i) / (i + 1))); //注意res[i]不进行类型转换会造成结果overflow 
	return res;
}
```