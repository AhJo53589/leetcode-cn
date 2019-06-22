# `（简单）`  [21.MergeTwoLists 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

### 题目描述
<p>将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>1-&gt;2-&gt;4, 1-&gt;3-&gt;4
<strong>输出：</strong>1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4
</pre>






---
### 思路
```

```


### 答题
``` C++
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	ListNode *pHead = NULL;
	ListNode *pNode = NULL;

	if (l1->val < l2->val)
	{
		pHead = l1;
		l1 = l1->next;
	}
	else
	{
		pHead = l2;
		l2 = l2->next;
	}
	pNode = pHead;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			pNode->next = l1;
			l1 = l1->next;
		}
		else
		{
			pNode->next = l2;
			l2 = l2->next;
		}
		pNode = pNode->next;
	}
	pNode->next = l1 ? l1 : l2;
	// 	if (l1 != NULL)
	// 	{
	// 		pNode->next = l1;
	// 	}
	// 	if (l2 != NULL)
	// 	{
	// 		pNode->next = l2;
	// 	}
	return pHead;
}
``` 