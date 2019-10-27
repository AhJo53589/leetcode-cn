# `（简单）` [206.reverse-linked-list 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

### 题目描述
<p>反转一个单链表。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL
<strong>输出:</strong> 5-&gt;4-&gt;3-&gt;2-&gt;1-&gt;NULL</pre>

<p><strong>进阶:</strong><br>
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？</p>



---
### 思路
```

```
> Solution.jpg  
![](https://raw.githubusercontent.com/AhJo53589/leetcode-cn/master/problems/206.ReverseList/Solution.jpg)



### 答题
``` C++
ListNode* ReverseIteratively(ListNode* pHead)
{
	ListNode* pReversedHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode != NULL)
	{
		// get the next node, and save it at pNext
		ListNode* pNext = pNode->m_pNext;
		// reverse the linkage between nodes
		pNode->m_pNext = pPrev;

		// move forward on the the list
		pPrev = pNode;
		pNode = pNext;
	}
	pReversedHead = pPrev;
	return pReversedHead;
}
``` 
