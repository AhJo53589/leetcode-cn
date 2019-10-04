# `（简单）`  [189.rotate-array 旋转数组](https://leetcode-cn.com/problems/rotate-array/)

### 题目描述
<p>给定一个数组，将数组中的元素向右移动&nbsp;<em>k&nbsp;</em>个位置，其中&nbsp;<em>k&nbsp;</em>是非负数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> <code>[1,2,3,4,5,6,7]</code> 和 <em>k</em> = 3
<strong>输出:</strong> <code>[5,6,7,1,2,3,4]</code>
<strong>解释:</strong>
向右旋转 1 步: <code>[7,1,2,3,4,5,6]</code>
向右旋转 2 步: <code>[6,7,1,2,3,4,5]
</code>向右旋转 3 步: <code>[5,6,7,1,2,3,4]</code>
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> <code>[-1,-100,3,99]</code> 和 <em>k</em> = 2
<strong>输出:</strong> [3,99,-1,-100]
<strong>解释:</strong> 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]</pre>

<p><strong>说明:</strong></p>

<ul>
	<li>尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。</li>
	<li>要求使用空间复杂度为&nbsp;O(1) 的&nbsp;<strong>原地&nbsp;</strong>算法。</li>
</ul>


---
### 思路 20190424
```
这道简单的题，看到要求使用空间复杂度为 O(1) 的原地算法。  
就规避了使用公共算法，额外的数组等。  
想着想着就感觉走上了歪路。  
不过幸好突破了最后的难关，让这条小路顺利抵达终点。  

思路和代码：  
我就想不管k是几，就让后面的数一口气先交换获得最终结果。  
然后剩下的被交换的乱七八糟的数字，再找规律。
万幸最后找到了规律，感觉还不错。  
```
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/problems/189.rotate-array/Solution.jpg)

[发布的题解](https://leetcode-cn.com/problems/rotate-array/solution/189-by-ikaruga/)

### 答题
``` C++
void rotate(vector<int>& nums, int k)	// 28ms
{
	k = k % nums.size();

	int iLen = nums.size();
	while (k > 0 && iLen > 1 && iLen != k)
	{
		for (int i = iLen - 1; i > k - 1; i--)
		{
			swap(nums[i], nums[i - k]);
		}

		int tmp = k;
		k = k - iLen % k;
		iLen = tmp;
	}
}
```

### 思路 20191004
使用stl库方法。
``` C++
void rotate(vector<int>& nums, int k)
{
	k = nums.size() - k % nums.size();
	auto it_k = nums.begin() + k;
	std::rotate(nums.begin(), it_k, nums.end());
}
```

