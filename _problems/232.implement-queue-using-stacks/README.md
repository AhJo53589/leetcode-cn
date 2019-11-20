# `（简单）`  [232.implement-queue-using-stacks  用栈实现队列](https://leetcode-cn.com/problems/implement-queue-using-stacks/)

### 题目描述
<p>使用栈实现队列的下列操作：</p>

<ul>
	<li>push(x) -- 将一个元素放入队列的尾部。</li>
	<li>pop() -- 从队列首部移除元素。</li>
	<li>peek() -- 返回队列首部的元素。</li>
	<li>empty() -- 返回队列是否为空。</li>
</ul>

<p><strong>示例:</strong></p>

<pre>MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false</pre>

<p><strong>说明:</strong></p>

<ul>
	<li>你只能使用标准的栈操作 -- 也就是只有&nbsp;<code>push to top</code>,&nbsp;<code>peek/pop from top</code>,&nbsp;<code>size</code>, 和&nbsp;<code>is empty</code>&nbsp;操作是合法的。</li>
	<li>你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。</li>
	<li>假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。</li>
</ul>


---
### 思路
```
```

### 答题
``` C++
class MyQueue
{
public:
	/** Initialize your data structure here. */
	MyQueue(){}

	/** Push element x to the back of queue. */
	void push(int x)
	{
		m_in.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop()
	{
		int i = peek();
		m_out.pop();
		return i;
	}

	/** Get the front element. */
	int peek()
	{
		TransferData();
		return m_out.top();
	}

	/** Returns whether the queue is empty. */
	bool empty()
	{
		return m_out.empty() && m_in.empty();
	}

	void TransferData()
	{
		if (!m_out.empty()) return;
		while (!m_in.empty())
		{
			m_out.push(m_in.top());
			m_in.pop();
		}
	}

private:
	stack<int> m_out;
	stack<int> m_in;
};
```

