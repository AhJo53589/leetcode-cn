# `（简单）` [225.implement-stack-using-queues  用队列实现栈](https://leetcode-cn.com/problems/implement-stack-using-queues/)

### 题目描述
<p>使用队列实现栈的下列操作：</p>

<ul>
	<li>push(x) -- 元素 x 入栈</li>
	<li>pop() -- 移除栈顶元素</li>
	<li>top() -- 获取栈顶元素</li>
	<li>empty() -- 返回栈是否为空</li>
</ul>

<p><strong>注意:</strong></p>

<ul>
	<li>你只能使用队列的基本操作-- 也就是&nbsp;<code>push to back</code>, <code>peek/pop from front</code>, <code>size</code>, 和&nbsp;<code>is empty</code>&nbsp;这些操作是合法的。</li>
	<li>你所使用的语言也许不支持队列。&nbsp;你可以使用 list 或者 deque（双端队列）来模拟一个队列&nbsp;, 只要是标准的队列操作即可。</li>
	<li>你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。</li>
</ul>


---
### 思路
```
使用两个队列，其中top的队列表示最后一个push的元素。
top()时如果top队没有元素的话，就从base的队列中取。
使用m_topMark来识别哪个队列是top队列。
```

### 答题
``` C++
class MyStack 
{
public:
	/** Initialize your data structure here. */
	MyStack() 
		: m_topMark(true)
	{

	}

	/** Push element x onto stack. */
	void push(int x) 
	{
		queue<int> *pTop = m_topMark ? &m_dataA : &m_dataB;
		queue<int> *pBase = m_topMark ? &m_dataB : &m_dataA;
		if (!pTop->empty())
		{
			pBase->push(pTop->front());
			pTop->pop();
		}
		pTop->push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop()
	{
		int i = top();

		queue<int> *pTop = m_topMark ? &m_dataA : &m_dataB;

		pTop->pop();
		return i;
	}

	/** Get the top element. */
	int top()
	{
		queue<int> *pTop = m_topMark ? &m_dataA : &m_dataB;
		queue<int> *pBase = m_topMark ? &m_dataB : &m_dataA;

		if (!pTop->empty()) return pTop->front();

		for (int i = 0; i < pBase->size() - 1; i++)
		{
			pTop->push(pBase->front());
			pBase->pop();
		}
		m_topMark = !m_topMark;

		return pBase->front();
	}

	/** Returns whether the stack is empty. */
	bool empty()
	{
		return m_dataA.empty() && m_dataB.empty();
	}

private:
	queue<int> m_dataA;
	queue<int> m_dataB;
	bool m_topMark;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

### 其它
参考了别人的答案，  
可以使用一个队列，在push的时候自身push(front)，就可以将依次进入队列内容反转。
代码和效率上都要简洁很多。  


``` C++
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
		for (int i = 0; i < q.size() - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int ret = q.front();
		q.pop();
		return ret;
	}

	/** Get the top element. */
	int top() {
		return q.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
private:
	queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```
