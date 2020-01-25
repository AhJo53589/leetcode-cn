# `（中等）` [138.copy-list-with-random-pointer 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/)

### 题目描述
<p>给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。</p>

<p>要求返回这个链表的<strong><a href="https://baike.baidu.com/item/深拷贝/22785317?fr=aladdin">深拷贝</a></strong>。&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<p><strong><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/23/1470150906153-2yxeznm.png" alt=""></strong></p>

<pre><strong>输入：
</strong>{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

<strong>解释：
</strong>节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>你必须返回<strong>给定头的拷贝</strong>作为对克隆列表的引用。</li>
</ol>


---
### 思路
```
思路和 133.CloneGraph 差不多。  
利用map，将原始数据和新数据对应起来。  
```

[题解](https://leetcode-cn.com/problems/copy-list-with-random-pointer/solution/fu-zhi-dai-sui-ji-zhi-zhen-de-lian-biao-shi-yong-m/)



### 答题
``` C++
Node* copyRandomList(Node* head)
{
	map<Node *, Node *> visited;
	visited[NULL] = NULL;

	Node *pPrev = NULL;
	Node *pNode = head;
	while (pNode != NULL)
	{
		Node *pNew = new Node();
		visited[pNode] = pNew;
		pNode = pNode->next;
	}
	pNode = head;
	while (pNode != NULL)
	{
		Node *pNew = visited[pNode];
		pNew->val = pNode->val;
		pNew->random = visited[pNode->random];
		pNew->next = NULL;
		if (pPrev != NULL)
		{
			visited[pPrev]->next = pNew;
		}
		pPrev = pNode;
		pNode = pNode->next;
	}
	return visited[head];
}
```
