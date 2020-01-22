# `（中等）` [117.populating-next-right-pointers-in-each-node-ii 填充每个节点的下一个右侧节点指针 II](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/)

### 题目描述
<p>给定一个二叉树</p>

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

<p><img style="height: 218px; width: 640px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/15/117_sample.png" alt=""></p>

<pre><strong>输入：</strong>{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

<strong>输出：</strong>{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}

<strong>解释：</strong>给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>你只能使用常量级额外空间。</li>
	<li>使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。</li>
</ul>


---
### 思路
```
注意要先练右子树。
```

### 答题
``` C++
Node* connect(Node* root)
{
	if (root == nullptr) return {};

	if (root->left != nullptr && root->right != nullptr) root->left->next = root->right;

	auto f = [root]()
	{
		Node *pNode = root->next;
		while (pNode != nullptr)
		{
			if (pNode->left != nullptr) return pNode->left;
			if (pNode->right != nullptr) return pNode->right;
			pNode = pNode->next;
		}
		return pNode;
	};
	Node *pNodeChild = (root->right == nullptr) ? root->left : root->right;
	Node *pNodeNextChild = f();

	if (pNodeChild != nullptr && pNodeNextChild != nullptr) pNodeChild->next = pNodeNextChild;

	connect(root->right);
    connect(root->left);
	return root;
}
```

### 其它
这个方法真的好，效率还高。
``` C++
Node* connect(Node* root) {
	if (root == NULL)
		return NULL;

	Node *dummy = new Node(-1, NULL, NULL, NULL);
	Node *pre = dummy;
	Node *head = root;

	while (root != NULL) {
		if (root->left) {
			pre->next = root->left;
			pre = pre->next;
		}

		if (root->right) {
			pre->next = root->right;
			pre = pre->next;
		}

		root = root->next;

		if (root == NULL) {
			pre = dummy;
			root = dummy->next;
			dummy->next = NULL;
		}
	}

	return head;
}
```

