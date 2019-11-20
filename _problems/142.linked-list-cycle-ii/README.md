# `（中等）`  [142.linked-list-cycle-ii 环形链表](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

### 题目描述
<p>给定一个链表，返回链表开始入环的第一个节点。&nbsp;如果链表无环，则返回&nbsp;<code>null</code>。</p>

<p>为了表示给定链表中的环，我们使用整数 <code>pos</code> 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 <code>pos</code> 是 <code>-1</code>，则在该链表中没有环。</p>

<p><strong>说明：</strong>不允许修改给定的链表。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>head = [3,2,0,-4], pos = 1
<strong>输出：</strong>tail connects to node index 1
<strong>解释：</strong>链表中有一个环，其尾部连接到第二个节点。
</pre>

<p><img style="height: 97px; width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png" alt=""></p>

<p><strong>示例&nbsp;2：</strong></p>

<pre><strong>输入：</strong>head = [1,2], pos = 0
<strong>输出：</strong>tail connects to node index 0
<strong>解释：</strong>链表中有一个环，其尾部连接到第一个节点。
</pre>

<p><img style="height: 74px; width: 141px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png" alt=""></p>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>head = [1], pos = -1
<strong>输出：</strong>no cycle
<strong>解释：</strong>链表中没有环。
</pre>

<p><img style="height: 45px; width: 45px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png" alt=""></p>

<p>&nbsp;</p>

<p><strong>进阶：</strong><br>
你是否可以不用额外空间解决此题？</p>


---
### 思路
```
Floyd 算法。  
先使用快慢指针判断是否有环。  
如果有环，从链表头和相遇点使用两个慢指针。  
再次相遇时便是入口点。  
```

### 答题
``` C++
ListNode *detectCycle(ListNode *head)
{
	if (head == NULL) return NULL;

	// 步骤一：使用快慢指针判断链表是否有环
	ListNode *p = head;
	ListNode *p2 = head;
	bool hasCycle = false;
	while (p2->next != NULL && p2->next->next != NULL)
	{
		p = p->next;
		p2 = p2->next->next;
		if (p == p2)
		{
			hasCycle = true;
			break;
		}
	}

	// 步骤二：若有环，找到入环开始的节点
	if (!hasCycle) return NULL;

	ListNode *q = head;
	while (p != q)
	{
		p = p->next;
		q = q->next;
	}
	return q;
}
```
