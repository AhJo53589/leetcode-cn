# `（中等）` [109.convert-sorted-list-to-binary-search-tree 有序链表转换二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)

### 题目描述
<p>给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。</p>

<p>本题中，一个高度平衡二叉树是指一个二叉树<em>每个节点&nbsp;</em>的左右两个子树的高度差的绝对值不超过 1。</p>

<p><strong>示例:</strong></p>

<pre>给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
</pre>


---
### 思路
```
```



### 答题
``` C++
TreeNode* sortedListToBST(ListNode* head, ListNode* tail)
{
    if (head == tail) return nullptr;
    if (head->next == tail) return new TreeNode(head->val);

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != tail && fast->next != tail)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;

    TreeNode* node = new TreeNode(slow->val);
    node->left = sortedListToBST(head, slow);
    node->right = sortedListToBST(fast, tail);
    return node;
}

TreeNode* sortedListToBST(ListNode* head) 
{
    return sortedListToBST(head, nullptr);
}
```




