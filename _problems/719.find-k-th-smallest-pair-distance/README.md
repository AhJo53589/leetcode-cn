# `（困难）`  [719.find-k-th-smallest-pair-distance 找出第 k 小的距离对](https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance/)

### 题目描述
<p>给定一个整数数组，返回所有数对之间的第 k 个最小<strong>距离</strong>。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入：</strong>
nums = [1,3,1]
k = 1
<strong>输出：0</strong> 
<strong>解释：</strong>
所有数对如下：
(1,3) -&gt; 2
(1,1) -&gt; 0
(3,1) -&gt; 2
因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。
</pre>

<p><strong>提示:</strong></p>

<ol>
	<li><code>2 &lt;= len(nums) &lt;= 10000</code>.</li>
	<li><code>0 &lt;= nums[i] &lt; 1000000</code>.</li>
	<li><code>1 &lt;= k &lt;= len(nums) * (len(nums) - 1) / 2</code>.</li>
</ol>


---
### 思路
```
```

### 答题
``` C++
//寻找距离不超过distance的个数（nums已经按照升序排序）
int findDistaceShort(vector<int>& nums, int distance) {
	//rightIndex代表的是在index左边且与nums[index]的距离不超过distanc的下标
	int numsSize = nums.size(), res = 0, rightIndex = numsSize - 1;
	for (int index = numsSize - 2; index >= 0; --index) {
		//修正index左边与与nums[index]的距离不超过distanc的下标
		while (rightIndex > index && nums[rightIndex] - nums[index] > distance) {
			--rightIndex;
		}
		res += (rightIndex - index);//则以index为一端，距离不超过distance的个数就是rightIndex - index
	}
	return res;
}

int smallestDistancePair(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());//按照升序排序
	//二分搜索的三个指针，left初始化为0，right初始化为最大的距离
	int left = 0, right = nums.back() - nums[0], mid;
	while (left < right) {
		mid = (left + right) / 2;
		int shortDisMid = findDistaceShort(nums, mid);//获取距离大小不超过k的距离对的个数
		//缩小[left, right]区间
		if (shortDisMid < k) {
			//<= mid的距离对个数小于k，则第k小的距离必定不会出现在[left, mid]
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left;
}
```

