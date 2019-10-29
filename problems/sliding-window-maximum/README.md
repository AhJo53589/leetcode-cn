# `（困难）` [239.sliding-window-maximum 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)

### 题目描述
<p>给定一个数组 <em>nums</em>，有一个大小为&nbsp;<em>k&nbsp;</em>的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 <em>k</em>&nbsp;个数字。滑动窗口每次只向右移动一位。</p>

<p>返回滑动窗口中的最大值。</p>

<p>&nbsp;</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> <em>nums</em> = <code>[1,3,-1,-3,5,3,6,7]</code>, 和 <em>k</em> = 3
<strong>输出: </strong><code>[3,3,5,5,6,7] 
<strong>解释: 
</strong></code>
  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p>你可以假设 <em>k </em>总是有效的，在输入数组不为空的情况下，1 ≤ k ≤&nbsp;输入数组的大小。</p>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<p>你能在线性时间复杂度内解决此题吗？</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/sliding-window-maximum/solution/239-by-ikaruga/)

### 答题
``` C++
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> ans;
	priority_queue<int> del_queue;
	priority_queue<int> cur_queue;

	for (size_t i = 0; i < nums.size(); i++)
	{
		cur_queue.push(nums[i]);

		if (i >= k - 1)
		{
			ans.push_back(cur_queue.top());
			del_queue.push(nums[i - k + 1]);
			while (!cur_queue.empty() && !del_queue.empty() && cur_queue.top() == del_queue.top())
			{
				cur_queue.pop();
				del_queue.pop();
			}
		}
	}
	return ans;
}
```

### 其它
使用双向队列。  
插入的时候将队列后面的值判断是否可以去掉。  
插入之后将队列前面的值判断是否可以去掉。
``` C++
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> res;
	deque<int> dq;
	for (int i = 0; i < nums.size(); i++) {
		while (!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
		dq.push_back(i);
		while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
		if (i >= k - 1) res.push_back(nums[dq.front()]);
	}
	return res;
}
```

