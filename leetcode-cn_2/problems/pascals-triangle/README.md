# `（简单）` [118.pascals-triangle 杨辉三角](https://leetcode-cn.com/problems/pascals-triangle/)

### 题目描述
<p>给定一个非负整数&nbsp;<em>numRows，</em>生成杨辉三角的前&nbsp;<em>numRows&nbsp;</em>行。</p>

<p><img src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif" alt=""></p>

<p><small>在杨辉三角中，每个数是它左上方和右上方的数的和。</small></p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 5
<strong>输出:</strong>
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]</pre>


---
### 思路
```
```

### 答题
``` C++
vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> m;
	for (int i = 1; i <= numRows; i++)
	{
		vector<int> n;
		for (int j = 0; j < i; j++)
		{
			if (j == 0 || j == i - 1) n.push_back(1);
			else n.push_back(m[i - 2][j - 1] + m[i - 2][j]);
		}
		m.push_back(n);
	}
	return m;
}

```

### 其它
``` C++
```

