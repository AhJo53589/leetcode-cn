# `（中等）` [1171.remove-zero-sum-consecutive-nodes-from-linked-list 从链表中删去总和值为零的连续节点](https://leetcode-cn.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)

### 题目描述
<p>给你一个链表的头节点&nbsp;<code>head</code>，请你编写代码，反复删去链表中由 <strong>总和</strong>&nbsp;值为 <code>0</code> 的连续节点组成的序列，直到不存在这样的序列为止。</p>

<p>删除完毕后，请你返回最终结果链表的头节点。</p>

<p>&nbsp;</p>

<p>你可以返回任何满足题目要求的答案。</p>

<p>（注意，下面示例中的所有序列，都是对&nbsp;<code>ListNode</code>&nbsp;对象序列化的表示。）</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>head = [1,2,-3,3,1]
<strong>输出：</strong>[3,1]
<strong>提示：</strong>答案 [1,2,1] 也是正确的。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>head = [1,2,3,-3,4]
<strong>输出：</strong>[1,2,4]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>head = [1,2,3,-3,-2]
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给你的链表中可能有 <code>1</code> 到&nbsp;<code>1000</code>&nbsp;个节点。</li>
	<li>对于链表中的每个节点，节点的值：<code>-1000 &lt;= node.val &lt;= 1000</code>.</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
ListNode* removeZeroSumSublists(ListNode* head)
{
	ListNode* dummy = new ListNode(0);
	dummy->next = head;

	ListNode* p = dummy;
	while (p->next != nullptr) 
	{
		ListNode* q = p->next;
		int sum = 0;
		while (q != nullptr)
		{
			sum += q->val;
			q = q->next;
			if (sum == 0) break;
		}

		if (sum == 0)
		{
			///////////////////////////////////////////////
			// 释放内存的做法 （leetcode传入参数delete会出错）
			//ListNode* del = nullptr;
			//while (p->next != q) 
			//{
			//	del = p->next;
			//	if (del != nullptr)
			//	{
			//		p->next = del->next;
			//		delete del;
			//	}
			//}

			///////////////////////////////////////////////
			// 不释放内存的做法
			p->next = q;
		}
		else 
		{
			p = p->next;
		}
	}
	return dummy->next;
}
```




