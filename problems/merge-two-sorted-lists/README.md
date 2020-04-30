# `（简单）` [21.merge-two-sorted-lists 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

### 题目描述
<p>将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>1->2->4, 1->3->4
<strong>输出：</strong>1->1->2->3->4->4
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/merge-two-sorted-lists-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode** pp = (l1->val < l2->val) ? &l1 : &l2;
            cur->next = *pp;
            cur = cur->next;
            *pp = (*pp)->next;
        }
        cur->next = (l1 == nullptr) ? l2 : l1;

        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
}; 
```




