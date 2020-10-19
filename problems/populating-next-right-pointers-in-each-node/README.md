# `（中等）` [116.populating-next-right-pointers-in-each-node 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)

### 题目描述
<p>给定一个<strong>完美二叉树</strong>，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：</p>

<pre>struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}</pre>

<p>填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 <code>NULL</code>。</p>

<p>初始状态下，所有&nbsp;next 指针都被设置为 <code>NULL</code>。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<p><img style="height: 218px; width: 640px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/15/116_sample.png" alt=""></p>

<pre><strong>输入：</strong>{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

<strong>输出：</strong>{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}

<strong>解释：</strong>给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>你只能使用常量级额外空间。</li>
	<li>使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/populating-next-right-pointers-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return {};

        if (root->left != nullptr && root->right != nullptr) {
            root->left->next = root->right;
        } 
        if (root->next != nullptr && root->next->left != nullptr) {
            root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);
        return root;
    }
};
```




