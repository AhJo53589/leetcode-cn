# `（简单）`  [160.intersection-of-two-linked-lists 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)

### 题目描述
<p>编写一个程序，找到两个单链表相交的起始节点。</p>

<p>如下面的两个链表<strong>：</strong></p>

<p><a href="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png"><img style="height: 130px; width: 400px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png" alt=""></a></p>

<p>在节点 c1 开始相交。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><a href="https://assets.leetcode.com/uploads/2018/12/13/160_example_1.png"><img style="height: 130px; width: 400px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_1.png" alt=""></a></p>

<pre><strong>输入：</strong>intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
<strong>输出：</strong>Reference of the node with value = 8
<strong>输入解释：</strong>相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
</pre>

<p>&nbsp;</p>

<p><strong>示例&nbsp;2：</strong></p>

<p><a href="https://assets.leetcode.com/uploads/2018/12/13/160_example_2.png"><img style="height: 136px; width: 350px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_2.png" alt=""></a></p>

<pre><strong>输入：</strong>intersectVal&nbsp;= 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
<strong>输出：</strong>Reference of the node with value = 2
<strong>输入解释：</strong>相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
</pre>

<p>&nbsp;</p>

<p><strong>示例&nbsp;3：</strong></p>

<p><a href="https://assets.leetcode.com/uploads/2018/12/13/160_example_3.png"><img style="height: 126px; width: 200px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_3.png" alt=""></a></p>

<pre><strong>输入：</strong>intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
<strong>输出：</strong>null
<strong>输入解释：</strong>从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
<strong>解释：</strong>这两个链表不相交，因此返回 null。
</pre>

<p>&nbsp;</p>

<p><strong>注意：</strong></p>

<ul>
	<li>如果两个链表没有交点，返回 <code>null</code>.</li>
	<li>在返回结果后，两个链表仍须保持原有的结构。</li>
	<li>可假定整个链表结构中没有循环。</li>
	<li>程序尽量满足 O(<em>n</em>) 时间复杂度，且仅用 O(<em>1</em>) 内存。</li>
</ul>


---
### 思路
```
使用两个指针指向两个链表头，  
先跑一圈计算长度，算出长度差。  
然后重新指向两个链表头，  
根据长度差，将较长的链表先走几步。  
后面一起前进，判断是否相等。  
```

### 答题
``` C++
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	ListNode *pA = headA;
	ListNode *pB = headB;
	if (pA == NULL || pB == NULL) return NULL;

	int iDiff = 0;
	while (pA->next != NULL)
	{
		pA = pA->next;
		iDiff--;
	}
	while (pB->next != NULL)
	{
		pB = pB->next;
		iDiff++;
	}

	pA = headA;
	pB = headB;
	if (iDiff < 0)
	{
		while (iDiff++ < 0) pA = pA->next;
	}
	else
	{
		while (iDiff-- > 0) pB = pB->next;
	}

	while (pA->next != NULL)
	{
		if (pA == pB) return pA;
		pA = pA->next;
		pB = pB->next;
	}
	if (pA == pB) return pA;
	return NULL;
}
```
