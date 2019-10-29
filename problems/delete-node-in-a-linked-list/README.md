# `（简单）` [237.delete-node-in-a-linked-list 删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/)

### 题目描述
<p>请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。</p>

<p>现有一个链表 --&nbsp;head =&nbsp;[4,5,1,9]，它可以表示为:</p>

<p><img style="height: 49px; width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/01/19/237_example.png" alt=""></p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> head = [4,5,1,9], node = 5
<strong>输出:</strong> [4,1,9]
<strong>解释: </strong>给定你链表中值为&nbsp;5&nbsp;的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -&gt; 1 -&gt; 9.
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> head = [4,5,1,9], node = 1
<strong>输出:</strong> [4,5,9]
<strong>解释: </strong>给定你链表中值为&nbsp;1&nbsp;的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -&gt; 5 -&gt; 9.
</pre>

<p>&nbsp;</p>

<p><strong>说明:</strong></p>

<ul>
	<li>链表至少包含两个节点。</li>
	<li>链表中所有节点的值都是唯一的。</li>
	<li>给定的节点为非末尾节点并且一定是链表中的一个有效节点。</li>
	<li>不要从你的函数中返回任何结果。</li>
</ul>





---
### 思路
```

```


### 答题
``` C++
void deleteNode(ListNode *node)
{
	ListNode *pNext = node->next;
	node->val = pNext->val;
	node->next = pNext->next;
	delete(pNext);
	pNext = NULL;
}
``` 

### 其它
这道题比较迷，一开始没看懂题。  
还说为啥不给head。  
后来才知道传进来的node就是要删的node。  
反而很简单。
