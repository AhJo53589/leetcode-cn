# `（困难）` [25.reverse-nodes-in-k-group K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)

### 题目描述
<p>给你一个链表，每&nbsp;<em>k&nbsp;</em>个节点一组进行翻转，请你返回翻转后的链表。</p>

<p><em>k&nbsp;</em>是一个正整数，它的值小于或等于链表的长度。</p>

<p>如果节点总数不是&nbsp;<em>k&nbsp;</em>的整数倍，那么请将最后剩余的节点保持原有顺序。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<p>给你这个链表：<code>1->2->3->4->5</code></p>

<p>当&nbsp;<em>k&nbsp;</em>= 2 时，应当返回: <code>2->1->4->3->5</code></p>

<p>当&nbsp;<em>k&nbsp;</em>= 3 时，应当返回: <code>3->2->1->4->5</code></p>

<p>&nbsp;</p>

<p><strong>说明：</strong></p>

<ul>
	<li>你的算法只能使用常数的额外空间。</li>
	<li><strong>你不能只是单纯的改变节点内部的值</strong>，而是需要实际进行节点交换。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/25-by-ikaruga/)

### 答题
``` C++
ListNode* reverseList(ListNode* head, ListNode* tail)
{
    ListNode* pPrev = tail;
    ListNode* pCurr = head;
    while (pCurr != tail)
    {
        ListNode* pNext = pCurr->next;
        pCurr->next = pPrev;
        pPrev = pCurr;
        pCurr = pNext;
    }
    return pPrev;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pPrev = dummy;
    ListNode* pCurr = head;
    while (pCurr != nullptr)
    {
        int i = 0;
        while (i++ < k && pCurr != nullptr)
        {
            pCurr = pCurr->next;
        }
        if (i != k + 1) break;

        ListNode* pTemp = pPrev->next;
        pPrev->next = reverseList(pTemp, pCurr);
        pPrev = pTemp;
    }
    return dummy->next;
}
```




