# `（简单）` [876.middle-of-the-linked-list 链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/)

### 题目描述
<p>给定一个带有头结点&nbsp;<code>head</code>&nbsp;的非空单链表，返回链表的中间结点。</p>

<p>如果有两个中间结点，则返回第二个中间结点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[1,2,3,4,5]
<strong>输出：</strong>此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre><strong>输入：</strong>[1,2,3,4,5,6]
<strong>输出：</strong>此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给定链表的结点数介于&nbsp;<code>1</code>&nbsp;和&nbsp;<code>100</code>&nbsp;之间。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
ListNode* middleNode(ListNode* head) 
{
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        head = head->next;
    }
    return head;
}
```


### 其它
``` C++
ListNode* middleNode(ListNode* head) 
{
    vector<ListNode*> nodes;
    while (head != nullptr)
    {
        nodes.push_back(head);
        head = head->next;
    }
    return nodes[nodes.size() / 2];
}
```


