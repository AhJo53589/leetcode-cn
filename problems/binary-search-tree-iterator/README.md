# `（中等）` [173.binary-search-tree-iterator 二叉搜索树迭代器](https://leetcode-cn.com/problems/binary-search-tree-iterator/)

### 题目描述
<p>实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。</p>

<p>调用 <code>next()</code> 将返回二叉搜索树中的下一个最小的数。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<p><strong><img style="height: 178px; width: 189px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/25/bst-tree.png" alt=""></strong></p>

<pre>BSTIterator iterator = new BSTIterator(root);
iterator.next();    // 返回 3
iterator.next();    // 返回 7
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 9
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 15
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 20
iterator.hasNext(); // 返回 false</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>next()</code>&nbsp;和&nbsp;<code>hasNext()</code>&nbsp;操作的时间复杂度是&nbsp;O(1)，并使用&nbsp;O(<em>h</em>) 内存，其中&nbsp;<em>h&nbsp;</em>是树的高度。</li>
	<li>你可以假设&nbsp;<code>next()</code>&nbsp;调用总是有效的，也就是说，当调用 <code>next()</code>&nbsp;时，BST 中至少存在一个下一个最小的数。</li>
</ul>


---
### 思路
```
使用堆栈，有左子结点时，一路加到底。  
读取完这个结点的值时，判断是否有右结点。  
如果有，把右结点的左子结点一路加到底。
```

### 答题
``` C++
class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		if (root != nullptr) stk.push(root);
		while (!stk.empty() && stk.top()->left != nullptr) stk.push(stk.top()->left);
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *pNode = stk.top();
		stk.pop();
		int res = pNode->val;
		if (pNode->right != nullptr)
		{
			stk.push(pNode->right);
			while (stk.top()->left != nullptr) stk.push(stk.top()->left);
		}
		return res;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !stk.empty();
	}

private:
	stack<TreeNode *> stk;
};
```

