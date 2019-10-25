# `（中等）`  [31.next-permutation 下一个排列](https://leetcode-cn.com/problems/next-permutation/)

### 题目描述
<p>实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。</p>

<p>如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。</p>

<p>必须<strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95">原地</a></strong>修改，只允许使用额外常数空间。</p>

<p>以下是一些例子，输入位于左侧列，其相应输出位于右侧列。<br>
<code>1,2,3</code> → <code>1,3,2</code><br>
<code>3,2,1</code> → <code>1,2,3</code><br>
<code>1,1,5</code> → <code>1,5,1</code></p>


---
### 思路
```
使用vector从后往前存，
发现相邻两个数字是顺序增长时，说明从这个点开始，后面的重新开始新一轮的排列。
所以要交换这个数字和后续数字中较大的一个数值（注意会有相同数字，使用upper_bound），
以及其他的数字按顺序排列在后面。

例子：
1,2,5,4 x 3
  ↓ ↓
1,2,5 x 4,3
  ↓ ↓
1,2 x 5,4,3  ← 找到相邻两个数字顺序增长的，（2,5）
  ↓ ↓
1,2 x (3,4,5)  ← 后边的数字排序
  ↓ ↓
1,3 x (2,4,5）  ← 然后交换比2大的数字
  ↓ ↓
1,3,2,4,5  ← 剩余的数字接在后面

完成
```

看了别人的题解，发现还可以优化。  
[别人的题解](https://leetcode-cn.com/problems/next-permutation/solution/c-yi-bian-sao-miao-er-fen-cha-zhao-li-yong-upper_b/)



### 答题
``` C++
void nextPermutation(vector<int>& nums)
{
	if (nums.empty()) return;

	vector<int> vec;
	bool bEndFlag = true;
	for (size_t i = nums.size() - 1; i > 0;)
	{
		i--;
		vec.push_back(nums[i + 1]);
		if (nums[i] < nums[i + 1])
		{
			bEndFlag = false;
			sort(vec.begin(), vec.end());
			auto it = upper_bound(vec.begin(), vec.end(), nums[i]);
			swap(nums[i], *it);
			for (size_t j = 0; j < vec.size(); j++)
			{
				nums[j + i + 1] = vec[j];
			}
			break;
		}
	}

	if (bEndFlag)
	{
		sort(nums.begin(), nums.end());
	}
}
```

### 其它
直接使用next_permutation。
``` C++
void nextPermutation(vector<int>& nums)
{
	vector<int> ans = nums;
	if (next_permutation(nums.begin(), nums.end()))
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (ans[i] > nums[i])
			{
				sort(ans.begin(), ans.end());
			}
		}
	}
}
```

