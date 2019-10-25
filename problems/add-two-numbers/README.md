# `（中等）` [2.add-two-numbers 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)

### 题目描述
<p>给出两个&nbsp;<strong>非空</strong> 的链表用来表示两个非负的整数。其中，它们各自的位数是按照&nbsp;<strong>逆序</strong>&nbsp;的方式存储的，并且它们的每个节点只能存储&nbsp;<strong>一位</strong>&nbsp;数字。</p>

<p>如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。</p>

<p>您可以假设除了数字 0 之外，这两个数都不会以 0&nbsp;开头。</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>(2 -&gt; 4 -&gt; 3) + (5 -&gt; 6 -&gt; 4)
<strong>输出：</strong>7 -&gt; 0 -&gt; 8
<strong>原因：</strong>342 + 465 = 807
</pre>


---
### 思路
```
与字符串相加思路大体相同。
```

### 答题
``` C++
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	ListNode *pSum = new ListNode(0);
	ListNode *pNode = pSum;
	int iCarry = 0;
	while (l1 != NULL || l2 != NULL || iCarry != 0)
	{
		int i1 = (l1 != NULL) ? l1->val : 0;
		int i2 = (l2 != NULL) ? l2->val : 0;
		if (l1 != NULL) l1 = l1->next;
		if (l2 != NULL) l2 = l2->next;
		int val = (i1 + i2 + iCarry) % 10;
		iCarry = (i1 + i2 + iCarry) / 10;
		ListNode *pNew = new ListNode(val);
		pNode->next = pNew;
		pNode = pNew;
	}
	return pSum->next;
}
```
