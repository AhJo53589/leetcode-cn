# `（困难）` [295.find-median-from-data-stream 数据流的中位数](https://leetcode-cn.com/problems/find-median-from-data-stream/)

### 题目描述
<p>中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。</p>

<p>例如，</p>

<p>[2,3,4]&nbsp;的中位数是 3</p>

<p>[2,3] 的中位数是 (2 + 3) / 2 = 2.5</p>

<p>设计一个支持以下两种操作的数据结构：</p>

<ul>
	<li>void addNum(int num) - 从数据流中添加一个整数到数据结构中。</li>
	<li>double findMedian() - 返回目前所有元素的中位数。</li>
</ul>

<p><strong>示例：</strong></p>

<pre>addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2</pre>

<p><strong>进阶:</strong></p>

<ol>
	<li>如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？</li>
	<li>如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？</li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/406-by-ikaruga/)

### 答题
``` C++
class MedianFinder {
	priority_queue<int> lo;                              // max heap
	priority_queue<int, vector<int>, greater<int>> hi;   // min heap

public:
	// Adds a number into the data structure.
	void addNum(int num)
	{
		if (lo.empty() || num < lo.top())
		{
			lo.push(num);
			if (lo.size() > hi.size() + 1)
			{
				hi.push(lo.top());
				lo.pop();
			}
		}
		else
		{
			hi.push(num);
			if (lo.size() < hi.size())
			{
				lo.push(hi.top());
				hi.pop();
			}
		}
	}
	//void addNum(int num)
	//{
	//	lo.push(num);                                    // Add to max heap

	//	hi.push(lo.top());                               // balancing step
	//	lo.pop();

	//	if (lo.size() < hi.size()) {                     // maintain size property
	//		lo.push(hi.top());
	//		hi.pop();
	//	}
	//}

	// Returns the median of current data stream
	double findMedian()
	{
		return lo.size() > hi.size() ? (double)lo.top() : (lo.top() + hi.top()) * 0.5;
	}
};
```




