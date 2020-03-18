# `（中等）` [82.remove-duplicates-from-sorted-list-ii 删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)

### 题目描述
<p>给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中&nbsp;<em>没有重复出现&nbsp;</em>的数字。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> 1->2->3->3->4->4->5
<strong>输出:</strong> 1->2->5
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> 1->1->1->2->3
<strong>输出:</strong> 2->3</pre>


---
### 思路
```
```



### 答题
``` C++
ListNode* deleteDuplicates(ListNode* head) 
{
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pPrev = dummy;
    ListNode* pNode = head;
    while (pNode != nullptr)
    {
        ListNode* pNext = pNode->next;
        bool delFlag = false;
        while (pNext != nullptr && pNext->val == pNode->val)
        {
            delFlag = true;
            pNext = pNext->next;
        }
        if (delFlag)
        {
            pPrev->next = pNext;
            pNode = pNext;
        }
        else
        {
            pPrev = pNode;
            pNode = pNode->next;
        }
    }
    return dummy->next;
}
```




