# `（简单）` [155.min-stack 最小栈](https://leetcode-cn.com/problems/min-stack/)

### 题目描述
<p>设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。</p>

<ul>
	<li>push(x)&nbsp;-- 将元素 x 推入栈中。</li>
	<li>pop()&nbsp;-- 删除栈顶的元素。</li>
	<li>top()&nbsp;-- 获取栈顶元素。</li>
	<li>getMin() -- 检索栈中的最小元素。</li>
</ul>

<p><strong>示例:</strong></p>

<pre>MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --&gt; 返回 -3.
minStack.pop();
minStack.top();      --&gt; 返回 0.
minStack.getMin();   --&gt; 返回 -2.
</pre>



---
### 思路
``` 
代码写很多，又不好调试。  
考的点又不难。  

想要实现快速查找getMin,  
就push的时候存一下。  
```


### 答题
``` C++
void push(int x) 
{
	if (cur == NULL) 
	{
		cur = new Node(x);
		head->next = cur;
		cur->pre = head;
		cur->curMin = x;
	}
	else 
	{
		cur->next = new Node(x);
		cur->next->pre = cur;
		cur = cur->next;
		cur->curMin = min(cur->pre->curMin, x);
	}
}

int getMin()
{
	return cur->curMin;
}
``` 
