# `（简单）` [226.invert-binary-tree 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)

### 题目描述
<p>翻转一棵二叉树。</p>

<p><strong>示例：</strong></p>

<p>输入：</p>

<pre>     4
   /   \
  2     7
 / \   / \
1   3 6   9</pre>

<p>输出：</p>

<pre>     4
   /   \
  7     2
 / \   / \
9   6 3   1</pre>

<p><strong>备注:</strong><br>
这个问题是受到 <a href="https://twitter.com/mxcl">Max Howell </a>的 <a href="https://twitter.com/mxcl/status/608682016205344768">原问题</a> 启发的 ：</p>

<blockquote>谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。</blockquote>


---
### 思路
```
```



### 答题
``` C++
TreeNode* invertTree(TreeNode* root)
{
	if (root != nullptr)
	{
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
	}
	return root;
}
```




