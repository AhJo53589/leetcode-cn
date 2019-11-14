# `（中等）` [61.rotate-list 旋转链表](https://leetcode-cn.com/problems/rotate-list/)

### 题目描述
<p>给定一个链表，旋转链表，将链表每个节点向右移动&nbsp;<em>k&nbsp;</em>个位置，其中&nbsp;<em>k&nbsp;</em>是非负数。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL, k = 2
<strong>输出:</strong> 4-&gt;5-&gt;1-&gt;2-&gt;3-&gt;NULL
<strong>解释:</strong>
向右旋转 1 步: 5-&gt;1-&gt;2-&gt;3-&gt;4-&gt;NULL
向右旋转 2 步: 4-&gt;5-&gt;1-&gt;2-&gt;3-&gt;NULL
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> 0-&gt;1-&gt;2-&gt;NULL, k = 4
<strong>输出:</strong> <code>2-&gt;0-&gt;1-&gt;NULL</code>
<strong>解释:</strong>
向右旋转 1 步: 2-&gt;0-&gt;1-&gt;NULL
向右旋转 2 步: 1-&gt;2-&gt;0-&gt;NULL
向右旋转 3 步:&nbsp;<code>0-&gt;1-&gt;2-&gt;NULL</code>
向右旋转 4 步:&nbsp;<code>2-&gt;0-&gt;1-&gt;NULL</code></pre>


---
### 思路
```
先测量链表长度。  
顺便把结尾连上头，串成一个环。  
算一下到底要移动多少步，走过去切断。  
```

### 答题
``` C++
ListNode* rotateRight(ListNode* head, int k)
{
	if (head == NULL) return head;
	if (head->next == NULL) return head;

	ListNode *pNode = head;
	int len = 0;
	while (pNode != NULL)
	{
		len++;
		if (pNode->next == NULL)
		{
			pNode->next = head;
			break;
		}
		pNode = pNode->next;
	}
	k = len - (k % len);
	pNode = head;
	while (k-- > 1) pNode = pNode->next;
	ListNode *pNewHead = pNode->next;
	pNode->next = NULL;

	return pNewHead;
}
```

