# `（中等）`  [384.Shuffle 打乱数组](https://leetcode-cn.com/problems/shuffle-an-array/)

### 题目描述
<p>打乱一个没有重复元素的数组。</p>

<p><strong>示例:</strong></p>

<pre>// 以数字集合 1, 2 和 3 初始化数组。
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
solution.shuffle();

// 重设数组到它的初始状态[1,2,3]。
solution.reset();

// 随机返回数组[1,2,3]打乱后的结果。
solution.shuffle();
</pre>



---
### 思路
``` 
```


### 答题
``` C++
class Solution 
{
public:
	Solution(vector<int>& nums) : m_nums(nums)
	{
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset()
	{
		return m_nums;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() 
	{
		vector<int> ans = m_nums;
		for (int i = 1; i < ans.size(); i++)
		{
			swap(ans[rand() % (i + 1)], ans[i]);
		}
		return ans;
	}

private:
	vector<int> m_nums;
};
``` 
