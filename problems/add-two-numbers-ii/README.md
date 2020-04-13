# `（中等）` [445.add-two-numbers-ii 两数相加 II](https://leetcode-cn.com/problems/add-two-numbers-ii/)

### 题目描述
<p>给你两个 <strong>非空 </strong>链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。</p>

<p>你可以假设除了数字 0 之外，这两个数字都不会以零开头。</p>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<p>如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>(7 -&gt; 2 -&gt; 4 -&gt; 3) + (5 -&gt; 6 -&gt; 4)
<strong>输出：</strong>7 -&gt; 8 -&gt; 0 -&gt; 7
</pre>


---
### 思路
```
```



### 答题
``` C++
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> s1;
        stack<int> s2;
        while (l1 != nullptr)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* dummy = new ListNode(0);
        int inc = 0;
        while (!s1.empty() || !s2.empty() || inc != 0)
        {
            int n1 = 0;
            int n2 = 0;
            if (!s1.empty())
            {
                n1 = s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                n2 = s2.top();
                s2.pop();
            }
            int val = n1 + n2 + inc;
            inc = val / 10;
            ListNode* node = new ListNode(val % 10);
            node->next = dummy->next;
            dummy->next = node;
        }
        return dummy->next;
    }
```




