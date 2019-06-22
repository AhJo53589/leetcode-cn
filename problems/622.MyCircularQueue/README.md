# `（中等）`  [622.MyCircularQueue 设计循环队列](https://leetcode-cn.com/problems/design-circular-queue/)

### 题目描述
<p>设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。</p>

<p>循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。</p>

<p>你的实现应该支持如下操作：</p>

<ul>
	<li><code>MyCircularQueue(k)</code>: 构造器，设置队列长度为 k 。</li>
	<li><code>Front</code>: 从队首获取元素。如果队列为空，返回 -1 。</li>
	<li><code>Rear</code>: 获取队尾元素。如果队列为空，返回 -1 。</li>
	<li><code>enQueue(value)</code>: 向循环队列插入一个元素。如果成功插入则返回真。</li>
	<li><code>deQueue()</code>: 从循环队列中删除一个元素。如果成功删除则返回真。</li>
	<li><code>isEmpty()</code>: 检查循环队列是否为空。</li>
	<li><code>isFull()</code>: 检查循环队列是否已满。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>MyCircularQueue circularQueue = new MycircularQueue(3); // 设置长度为 3

circularQueue.enQueue(1); &nbsp;// 返回 true

circularQueue.enQueue(2); &nbsp;// 返回 true

circularQueue.enQueue(3); &nbsp;// 返回 true

circularQueue.enQueue(4); &nbsp;// 返回 false，队列已满

circularQueue.Rear(); &nbsp;// 返回 3

circularQueue.isFull(); &nbsp;// 返回 true

circularQueue.deQueue(); &nbsp;// 返回 true

circularQueue.enQueue(4); &nbsp;// 返回 true

circularQueue.Rear(); &nbsp;// 返回 4
&nbsp;</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>所有的值都在 0&nbsp;至 1000 的范围内；</li>
	<li>操作数将在 1 至 1000 的范围内；</li>
	<li>请不要使用内置的队列库。</li>
</ul>



---
### 思路
``` 
使用数组即可，用head和tail两个变量来记录头尾的下标。  
再记录一下size，其他都可以通过计算得到。  
使用%操作，让数组循环起来。  
注意判断isFull的时候，也要用%。  
```


### 答题
``` C++
class MyCircularQueue
{
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k)
	{
		m_size = k > 0 ? k : 0;
		m_pData = new int[k];
		m_head = -1;
		m_tail = -1;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value)
	{
		if (isFull()) return false;

		if (isEmpty())
		{
			m_head = 0;
			m_tail = 0;
			m_pData[m_tail] = value;
		}
		else
		{
			m_tail = (m_tail + 1) % m_size;
			m_pData[m_tail] = value;
		}
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue()
	{
		if (isEmpty()) return false;

		if (m_tail == m_head)
		{
			m_head = -1;
			m_tail = -1;
		}
		else
		{
			m_head = (m_head + 1) % m_size;
		}
		return true;
	}

	/** Get the front item from the queue. */
	int Front()
	{
		if (isEmpty()) return -1;
		return m_pData[m_head];
	}

	/** Get the last item from the queue. */
	int Rear()
	{
		if (isEmpty()) return -1;
		return m_pData[m_tail];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty()
	{
		return m_head == -1;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull()
	{
		return (m_size == 0 || ((m_tail + 1) % m_size) == m_head);
	}

private:
	int *m_pData;
	int m_head;
	int m_tail;
	int m_size;
};
``` 