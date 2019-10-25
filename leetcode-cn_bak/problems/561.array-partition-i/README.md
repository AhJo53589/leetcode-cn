# `（简单）`  [561.array-partition-i 数组拆分 I](https://leetcode-cn.com/problems/array-partition-i/)

### 题目描述
<p>给定长度为&nbsp;<strong>2n&nbsp;</strong>的数组, 你的任务是将这些数分成&nbsp;<strong>n </strong>对, 例如 (a<sub>1</sub>, b<sub>1</sub>), (a<sub>2</sub>, b<sub>2</sub>), ..., (a<sub>n</sub>, b<sub>n</sub>) ，使得从1 到&nbsp;n 的 min(a<sub>i</sub>, b<sub>i</sub>) 总和最大。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [1,4,3,2]

<strong>输出:</strong> 4
<strong>解释:</strong> n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
</pre>

<p><strong>提示:</strong></p>

<ol>
	<li><strong>n</strong>&nbsp;是正整数,范围在 [1, 10000].</li>
	<li>数组中的元素范围在 [-10000, 10000].</li>
</ol>


---
### 思路
```
```

### 答题
``` C++
int arrayPairSum(vector<int>& nums)
{
	int sum = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i += 2)
	{
		sum += min(nums[i], nums[i + 1]);
	}
	return sum;
}

```
