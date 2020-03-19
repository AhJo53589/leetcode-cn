# `（中等）` [86.partition-list 分隔链表](https://leetcode-cn.com/problems/partition-list/)

### 题目描述
<p>给定一个链表和一个特定值<em> x</em>，对链表进行分隔，使得所有小于 <em>x</em> 的节点都在大于或等于 <em>x</em> 的节点之前。</p>

<p>你应当保留两个分区中每个节点的初始相对位置。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> head = 1->4->3->2->5->2, <em>x</em> = 3
<strong>输出:</strong> 1->2->2->4->3->5
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/partition-list/solution/86-by-ikaruga/)

### 答题
``` C++
ListNode* partition(ListNode* head, int x) 
{
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = head;
    ListNode* ins = dummy;
    ListNode* rem = dummy;
    while (fast != nullptr && fast->val < x)
    {
        fast = fast->next;
    }
    while (ins != nullptr && ins->next != fast)
    {
        ins = ins->next;
    }
    while (fast != nullptr)
    {
        if (fast->val < x)
        {
            while (rem != nullptr && rem->next != fast)
            {
                rem = rem->next;
            }
            if (rem == nullptr) break;
            ListNode* temp = ins->next;
            ins->next = rem->next;
            rem->next = rem->next->next;
            ins->next->next = temp;
            ins = ins->next;
        }
        fast = fast->next;
    }
    return dummy->next;
}
```




