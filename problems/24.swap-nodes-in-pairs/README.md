# `（中等）`  [24.swap-nodes-in-pairs 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

### 题目描述
<p>给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。</p>

<p><strong>你不能只是单纯的改变节点内部的值</strong>，而是需要实际的进行节点交换。</p>

<p>&nbsp;</p>

<p><strong>示例:</strong></p>

<pre>给定 <code>1-&gt;2-&gt;3-&gt;4</code>, 你应该返回 <code>2-&gt;1-&gt;4-&gt;3</code>.
</pre>


---
### 思路
```
```

### 答题
``` C++
ListNode* swapPairs(ListNode* head) 
{
	if (head == nullptr) return head;
	ListNode *pNode = head;
	ListNode *pNodeNext = head->next;
	ListNode *pPrev = nullptr;
	head = (pNodeNext == nullptr) ? head : pNodeNext;
	while (pNode != nullptr && pNodeNext != nullptr)
	{
		if (pPrev != NULL) pPrev->next = pNodeNext;
		pPrev = pNode;

		ListNode *pTemp = pNodeNext->next;
		pNodeNext->next = pNode;
		pNode->next = pTemp;

		pNode = pTemp;
		pNodeNext = (pNode == nullptr) ? nullptr : pNode->next;
	}
	return head;
}
```
