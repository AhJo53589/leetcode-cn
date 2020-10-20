# `（中等）` [143.reorder-list 重排链表](https://leetcode-cn.com/problems/reorder-list/)

### 题目描述
<p>给定一个单链表&nbsp;<em>L</em>：<em>L</em><sub>0</sub>→<em>L</em><sub>1</sub>→…→<em>L</em><sub><em>n</em>-1</sub>→<em>L</em><sub>n ，</sub><br>
将其重新排列后变为： <em>L</em><sub>0</sub>→<em>L</em><sub><em>n</em></sub>→<em>L</em><sub>1</sub>→<em>L</em><sub><em>n</em>-1</sub>→<em>L</em><sub>2</sub>→<em>L</em><sub><em>n</em>-2</sub>→…</p>

<p>你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>给定链表 1-&gt;2-&gt;3-&gt;4, 重新排列为 1-&gt;4-&gt;2-&gt;3.</pre>

<p><strong>示例 2:</strong></p>

<pre>给定链表 1-&gt;2-&gt;3-&gt;4-&gt;5, 重新排列为 1-&gt;5-&gt;2-&gt;4-&gt;3.</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    void reorderList(ListNode* head) {
    }

    ListNode* reorder(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* second = head->next;
        ListNode* tail = reorderList(head->next);
        if (tail != nullptr) {
            head->next = tail;
            head->next->next = second;
        }
    }
};
```




