# `（中等）`  [78.subsets 子集](https://leetcode-cn.com/problems/subsets/)

### 题目描述
<p>给定一组<strong>不含重复元素</strong>的整数数组&nbsp;<em>nums</em>，返回该数组所有可能的子集（幂集）。</p>

<p><strong>说明：</strong>解集不能包含重复的子集。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> nums = [1,2,3]
<strong>输出:</strong>
[
  [3],
&nbsp; [1],
&nbsp; [2],
&nbsp; [1,2,3],
&nbsp; [1,3],
&nbsp; [2,3],
&nbsp; [1,2],
&nbsp; []
]</pre>


---
### 思路
```
先生成一个数字的子集。
再像2重循环一样for (int i = 0; i < size; i++>) for (int j = i + 1; j < size; j++>)
递归去找后面的子集，用来保证不重复。
比如   1 => 1,2 => 1,2,3 => 1,2,3,4
             \\      \\
			  \\	   => 1,2,4           
			    => 1,3 => 1,3,4
				\\
				  => 1,4
```

### 答题
``` C++
void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> record, int n)
{
	if (n == nums.size()) return;
	for (int i = n; i < nums.size(); i++)
	{
		record.push_back(nums[i]);
		res.push_back(record);
		backtrack(nums, res, record, i + 1);
		record.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> record;
	res.push_back(record);
	backtrack(nums, res, record, 0);
	return res;
}
```

### 其它
``` C++
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res(1);
	for (int i = 0; i < nums.size(); i++) {
		int cnt = res.size();
		for (int j = 0; j < cnt; j++) {
			vector<int> tmp = res[j];
			tmp.push_back(nums[i]);
			res.push_back(tmp);
		}
	}
	return res;
}
```

还有用位运算的方法
[位运算](https://leetcode-cn.com/problems/subsets/solution/wei-yun-suan-by-yi-qu-xin-ci/)  
``` C++
vector<vector<int>> subsets(vector<int>& nums) {
	int S = nums.size();
	int N = (1 << S);
	vector<vector<int>> res;
	for (int i = 0; i < N; ++i) 
	{
		vector<int> v;
		for (int j = 0; j < S; ++j)
		{
			if (i & (1 << j)) v.push_back(nums[j]);
		}
		res.push_back(v);
	}
	return res;
}
```