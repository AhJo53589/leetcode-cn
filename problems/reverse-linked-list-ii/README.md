# `（中等）` [92.reverse-linked-list-ii 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/)

### 题目描述
<p>反转从位置 <em>m</em> 到 <em>n</em> 的链表。请使用一趟扫描完成反转。</p>

<p><strong>说明:</strong><br>
1 ≤&nbsp;<em>m</em>&nbsp;≤&nbsp;<em>n</em>&nbsp;≤ 链表长度。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL, <em>m</em> = 2, <em>n</em> = 4
<strong>输出:</strong> 1-&gt;4-&gt;3-&gt;2-&gt;5-&gt;NULL</pre>


---
### 思路
```
```



### 答题
``` C++
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	n -= m;
	if (n++ == 0) return head;

	ListNode *pH = new ListNode(0);
	pH->next = head;

	ListNode *pM = pH;
	while (--m != 0)
	{
		pM = pM->next;
	}

	ListNode *pPre = nullptr;
	ListNode *pCur = pM->next;
	ListNode *pNxt = pCur->next;
	while (n-- != 0)
	{
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNxt;
		if (pCur == nullptr) break;
		pNxt = pCur->next;
	}

	pM->next->next = pCur;
	pM->next = pPre;

	head = pH->next;
	delete pH;
	return head;
}
```




