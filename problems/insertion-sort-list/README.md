# `（中等）` [147.insertion-sort-list 对链表进行插入排序](https://leetcode-cn.com/problems/insertion-sort-list/)

### 题目描述
<p>对链表进行插入排序。</p>

<p><img src="https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif" alt=""><br>
<small>插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。<br>
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。</small></p>

<p>&nbsp;</p>

<p><strong>插入排序算法：</strong></p>

<ol>
	<li>插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。</li>
	<li>每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。</li>
	<li>重复直到所有输入数据插入完为止。</li>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> 4->2->1->3
<strong>输出:</strong> 1->2->3->4
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre><strong>输入:</strong> -1->5->3->4->0
<strong>输出:</strong> -1->0->3->4->5
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/insertion-sort-list/solution/insertion-sort-list-by-ikaruga/)

### 答题
``` C++
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;

        ListNode* preNode = dummy;
        while (head != nullptr) {
            ListNode* curNode = head;
            head = head->next;

            if (preNode->val <= curNode->val) {
                preNode = curNode;
                continue;
            }

            preNode->next = curNode->next;
            ListNode* p = dummy;
            for (ListNode* p = dummy; p != head; p = p->next) {
                if (p->next->val < curNode->val) continue;
                curNode->next = p->next;
                p->next = curNode;
                break;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
```




