# `（中等）`  [148.sort-list 排序链表](https://leetcode-cn.com/problems/sort-list/)

### 题目描述
<p>在&nbsp;<em>O</em>(<em>n</em>&nbsp;log&nbsp;<em>n</em>) 时间复杂度和常数级空间复杂度下，对链表进行排序。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 4-&gt;2-&gt;1-&gt;3
<strong>输出:</strong> 1-&gt;2-&gt;3-&gt;4
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> -1-&gt;5-&gt;3-&gt;4-&gt;0
<strong>输出:</strong> -1-&gt;0-&gt;3-&gt;4-&gt;5</pre>


---
### 思路
```
```

### 答题
``` C++
ListNode* merge(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr) return l2;
	if (l2 == nullptr) return l1;

	if (l1->val < l2->val)
	{
		l1->next = merge(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = merge(l2->next, l1);
		return l2;
	}
}

ListNode* sortList(ListNode* head) 
{
	if (!head || !head->next) return head;
	ListNode *fast = head;
	ListNode *slow = head;
	ListNode *brek = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		brek = slow;
		slow = slow->next;
	}
	brek->next = nullptr;
	ListNode *l1 = sortList(head);
	ListNode *l2 = sortList(slow);
	return merge(l1, l2);
}
```
