# `（中等）`  [328.odd-even-linked-list 奇偶链表](https://leetcode-cn.com/problems/odd-even-linked-list/)

### 题目描述
<p>给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。</p>

<p>请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL
<strong>输出:</strong> 1-&gt;3-&gt;5-&gt;2-&gt;4-&gt;NULL
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 2-&gt;1-&gt;3-&gt;5-&gt;6-&gt;4-&gt;7-&gt;NULL 
<strong>输出:</strong> 2-&gt;3-&gt;6-&gt;7-&gt;1-&gt;5-&gt;4-&gt;NULL</pre>

<p><strong>说明:</strong></p>

<ul>
	<li>应当保持奇数节点和偶数节点的相对顺序。</li>
	<li>链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。</li>
</ul>


---
### 思路
```
多加一个偶数链表头，然后根据奇偶分开，  
最后奇数链表尾连接上偶数链表头。
```

### 答题
``` C++
ListNode* oddEvenList(ListNode* head) 
{
	if (head == NULL) return head;
	if (head->next == NULL) return head;
	if (head->next->next == NULL) return head;

	ListNode *pEvenHead = head->next;
	ListNode *pOdd = head;
	ListNode *pEven = head->next;
	ListNode *pNode = head->next->next;
	int i = 2;
	while (pNode != NULL)
	{
		if ((++i) % 2 == 1)
		{
			pOdd->next = pNode;
			pOdd = pNode;
		}
		else
		{
			pEven->next = pNode;
			pEven = pNode;
		}
		pNode = pNode->next;
	}
	pEven->next = NULL;
	pOdd->next = pEvenHead;
	return head;
}
```

### 其它
这个代码是同一个思路，用更精简的语句构成。  
``` C++
ListNode* oddEvenList(ListNode* head) 
{
	if (!head || !head->next) return head;

	ListNode* odd = head;
	ListNode* even = head->next;
	ListNode* evenHead = even;

	while (even && even->next) 
	{
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = evenHead;
	return head;
}
```

