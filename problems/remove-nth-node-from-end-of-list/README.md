# `（中等）` [19.remove-nth-node-from-end-of-list 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

### 题目描述
<p>给定一个链表，删除链表的倒数第&nbsp;<em>n&nbsp;</em>个节点，并且返回链表的头结点。</p>

<p><strong>示例：</strong></p>

<pre>给定一个链表: <strong>1-&gt;2-&gt;3-&gt;4-&gt;5</strong>, 和 <strong><em>n</em> = 2</strong>.

当删除了倒数第二个节点后，链表变为 <strong>1-&gt;2-&gt;3-&gt;5</strong>.
</pre>

<p><strong>说明：</strong></p>

<p>给定的 <em>n</em>&nbsp;保证是有效的。</p>

<p><strong>进阶：</strong></p>

<p>你能尝试使用一趟扫描实现吗？</p>




---
### 思路
```
这道题按照进阶要求，一次遍历出结果。  
事后看了下评论，大家管这种叫快慢指针。  
只是我比较纠结大家为啥都不调用delete()
```


### 答题
``` C++
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head == NULL || n == 0) return NULL;
	if (head->next == NULL) return NULL;

	ListNode *pTemp = head;
	ListNode *pDeletePrev = head;
	ListNode *pDelete = NULL;
	while (n > 0)
	{
		pTemp = pTemp->next;
		--n;
	}
	if (pTemp == NULL)
	{
		pDelete = head;
		head = head->next;
		delete(pDelete);
		return head;
	}
	while (pTemp->next != NULL)
	{
		pTemp = pTemp->next;
		pDeletePrev = pDeletePrev->next;
	}
	pDelete = pDeletePrev->next;
	pDeletePrev->next = pDelete->next;
	delete(pDelete);
	return head;
}
``` 
