# `（中等）` [11.container-with-most-water 盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)

### 题目描述
<p>给定 <em>n</em> 个非负整数 <em>a</em><sub>1</sub>，<em>a</em><sub>2，</sub>...，<em>a</em><sub>n，</sub>每个数代表坐标中的一个点&nbsp;(<em>i</em>,&nbsp;<em>a<sub>i</sub></em>) 。在坐标内画 <em>n</em> 条垂直线，垂直线 <em>i</em>&nbsp;的两个端点分别为&nbsp;(<em>i</em>,&nbsp;<em>a<sub>i</sub></em>) 和 (<em>i</em>, 0)。找出其中的两条线，使得它们与&nbsp;<em>x</em>&nbsp;轴共同构成的容器可以容纳最多的水。</p>

<p><strong>说明：</strong>你不能倾斜容器，且&nbsp;<em>n</em>&nbsp;的值至少为 2。</p>

<p><img style="height: 287px; width: 600px;" src="https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg" alt=""></p>

<p><small>图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为&nbsp;49。</small></p>

<p>&nbsp;</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> [1,8,6,2,5,4,8,3,7]
<strong>输出:</strong> 49</pre>


---
### 思路
```
使用对撞指针。  
从外到内，只有短的一边变长，才有可能增大面积。  
调整短的一边，尝试计算新的面积。  
```

### 答题
``` C++
int maxArea(vector<int>& nums) 
{
	auto getArea = [nums](int low, int high) { return min(nums[low], nums[high]) * abs(low - high); };
	vector<int> left;
	vector<int> right;
	int iMax = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > iMax) left.push_back(i);
		iMax = max(iMax, nums[i]);
	}
	iMax = 0;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		if (nums[i] > iMax) right.push_back(i);
		iMax = max(iMax, nums[i]);
	}
	iMax = 0;
	int i = 0;
	int j = 0;
	while (i < left.size() && j < right.size() && left[i] < right[j])
	{
		iMax = max(iMax, getArea(left[i], right[j]));
		nums[left[i]] < nums[right[j]] ? i++ : j++;
	}
	return iMax;
}
```

### 其它
看别人的代码直接算就行。
``` C++
int maxArea(vector<int>& height) {
	int start=0,end=height.size()-1,op=0;
	while(start<end)
	{
		op=max(op,min(height[start],height[end])*(end-start));
		height[start]<height[end]?++start:--end;
	}
	return op;
}
```

