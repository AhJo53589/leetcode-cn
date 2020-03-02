# `（简单）` [206.reverse-linked-list 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

### 题目描述
<p>反转一个单链表。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 1->2->3->4->5->NULL
<strong>输出:</strong> 5->4->3->2->1->NULL</pre>

<p><strong>进阶:</strong><br>
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/reverse-linked-list/solution/206-by-ikaruga/)

### 答题
``` C++
ListNode* reverseList(ListNode* head)
{
    ListNode* pPrev = nullptr;
    ListNode* pCurr = head;
    while (pCurr != nullptr)
    {
        ListNode* pNext = pCurr->next;
        pCurr->next = pPrev;
        pPrev = pCurr;
        pCurr = pNext;
    }
    return pPrev;
}
```


### 其它
``` C++
ListNode* reverseList(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* p = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return p;
}
```


