# `（简单）` [257.binary-tree-paths 二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/)

### 题目描述
<p>给定一个二叉树，返回所有从根节点到叶子节点的路径。</p>

<p><strong>说明:</strong>&nbsp;叶子节点是指没有子节点的节点。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>

   1
 /   \
2     3
 \
  5

<strong>输出:</strong> ["1-&gt;2-&gt;5", "1-&gt;3"]

<strong>解释:</strong> 所有根节点到叶子节点的路径为: 1-&gt;2-&gt;5, 1-&gt;3</pre>


---
### 思路
```
```

### 答题
``` C++
void binaryTreePaths(TreeNode* root, string path, vector<string> &vec)
{
	path = path.empty() ? to_string(root->val) : path + "->" + to_string(root->val);
	if (root->left != nullptr)
	{
		binaryTreePaths(root->left, path, vec);
	}
	if (root->right != nullptr)
	{
		binaryTreePaths(root->right, path, vec);
	}
	if (root->left == nullptr && root->right == nullptr)
	{
		vec.push_back(path);
	}
}

vector<string> binaryTreePaths(TreeNode* root) 
{
	if (root == nullptr) return {};
	string path;
	vector<string> vec;
	binaryTreePaths(root, path, vec);
	return vec;
}
```

