# `（简单）` [203.remove-linked-list-elements 移除链表元素](https://leetcode-cn.com/problems/remove-linked-list-elements/)

### 题目描述
<p>删除链表中等于给定值&nbsp;<strong><em>val&nbsp;</em></strong>的所有节点。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 1-&gt;2-&gt;6-&gt;3-&gt;4-&gt;5-&gt;6, <em><strong>val</strong></em> = 6
<strong>输出:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5
</pre>


---
### 思路
```
一开始没看清题，是删除所有。  
后来看清了题，各种边界处理有问题，错了好几次。  
```

### 答题
``` C++
ListNode* removeElements(ListNode* head, int val) 
{
	if (head == NULL) return head;
	while (head != NULL && head->val == val)
	{
		ListNode *pDelete = head;
		head = head->next;
		delete pDelete;
	}
	ListNode *pPreNode = NULL;
	ListNode *pNode = head;
	while (pNode != NULL && pNode->next != NULL)
	{
		pPreNode = pNode;
		pNode = pNode->next;

		if (pNode->val == val)
		{
			pPreNode->next = pNode->next;
			delete pNode;
			pNode = pPreNode;
		}
	}
	return head;
}
```

### 其它
``` C++
```

