# `（中等）` [430.flatten-a-multilevel-doubly-linked-list 扁平化多级双向链表](https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/)

### 题目描述
<p>您将获得一个双向链表，除了下一个和前一个指针之外，它还有一个子指针，可能指向单独的双向链表。这些子列表可能有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。</p>

<p>扁平化列表，使所有结点出现在单级双链表中。您将获得列表第一级的头部。</p>

<p>&nbsp;</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

<strong>输出:</strong>
1-2-3-7-8-11-12-9-10-4-5-6-NULL
</pre>

<p>&nbsp;</p>

<p><strong>以上示例的说明:</strong></p>

<p>给出以下多级双向链表:</p>

<pre><img style="width: 640px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/multilevellinkedlist.png"></pre>

<p>&nbsp;</p>

<p>我们应该返回如下所示的扁平双向链表:</p>

<pre><img style="width: 1100px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/multilevellinkedlistflattened.png"></pre>


---
### 思路
```
```

[题解](https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/solution/bian-ping-hua-duo-ji-shuang-xiang-lian-biao-zheng-/)


### 答题
``` C++
Node* flatten(Node* head)
{
	Node *pNode = head;
	while (pNode != NULL)
	{
		if (pNode->child != NULL)
		{
			Node *pNext = pNode->next;
			pNode->next = pNode->child;
			pNode->next->prev = pNode;
			pNode->child = NULL;
			flatten(pNode);
			while (pNode != NULL && pNode->next != NULL) pNode = pNode->next;
			pNode->next = pNext;
			if (pNext != NULL) pNext->prev = pNode;
		}
		pNode = pNode->next;
	}
	return head;
}
```

