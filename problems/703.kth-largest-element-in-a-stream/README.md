# `（简单）`  [703.kth-largest-element-in-a-stream 数据流中的第K大元素](https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/)

### 题目描述
<p>设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。</p>

<p>你的&nbsp;<code>KthLargest</code>&nbsp;类需要一个同时接收整数&nbsp;<code>k</code> 和整数数组<code>nums</code>&nbsp;的构造器，它包含数据流中的初始元素。每次调用&nbsp;<code>KthLargest.add</code>，返回当前数据流中第K大的元素。</p>

<p><strong>示例:</strong></p>

<pre>int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);&nbsp; &nbsp;// returns 4
kthLargest.add(5);&nbsp; &nbsp;// returns 5
kthLargest.add(10);&nbsp; // returns 5
kthLargest.add(9);&nbsp; &nbsp;// returns 8
kthLargest.add(4);&nbsp; &nbsp;// returns 8
</pre>

<p><strong>说明: </strong><br>
你可以假设&nbsp;<code>nums</code>&nbsp;的长度≥&nbsp;<code>k-1</code>&nbsp;且<code>k</code> ≥&nbsp;1。</p>


---
### 思路
```
学习priority_queue。
```

### 答题
``` C++
class KthLargest {
public:
	priority_queue<int, vector<int>, greater<int>> pq; //最小堆
	int K;
	KthLargest(int k, vector<int>& nums) {
		K = k;
		for (int& nu : nums) {
			this->add(nu);
		}
	}

	int add(int val) {
		if (pq.size() < K)
			pq.push(val);
		else if (pq.top() < val) {  //val大于堆顶，入堆
			pq.pop();
			pq.push(val);
		}
		return pq.top();  //否则直接返回堆顶
	}
};
```

### 其它
``` C++
class KthLargest {
public:
	KthLargest(int k, vector<int>& nums) {
		m_k = k;
		m_nums = nums;
		sort(m_nums.rbegin(), m_nums.rend());
	}

	int add(int val) {
		if (m_nums.size() != m_k || val > m_nums.back())
		{
			m_nums.push_back(val);
			int i = m_nums.size() - 2;
			for (; i >= 0; i--)
			{
				if (m_nums[i] < val) m_nums[i + 1] = m_nums[i];
				else break;
			}
			m_nums[i + 1] = val;
		}
		while (m_nums.size() > m_k) m_nums.pop_back();
		return (m_k > m_nums.size()) ? 0 : m_nums.back();
	}

private:
	vector<int> m_nums;
	int m_k;
};
```

