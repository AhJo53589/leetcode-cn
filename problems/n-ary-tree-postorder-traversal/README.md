# `（简单）` [590.n-ary-tree-postorder-traversal N叉树的后序遍历](https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/)

### 题目描述
<p>给定一个 N 叉树，返回其节点值的<em>后序遍历</em>。</p>

<p>例如，给定一个&nbsp;<code>3叉树</code>&nbsp;:</p>

<p>&nbsp;</p>

<p><img style="width: 100%; max-width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/narytreeexample.png"></p>

<p>&nbsp;</p>

<p>返回其后序遍历: <code>[5,6,3,2,4,1]</code>.</p>

<p>&nbsp;</p>

<p><strong>说明:</strong>&nbsp;递归法很简单，你可以使用迭代法完成此题吗?</p>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
	void postorder(Node* root, vector<int>& ans)
	{
		if (root == nullptr) return;
		for (auto c : root->children)
		{
			postorder(c, ans);
		}
		ans.push_back(root->val);
	}

    vector<int> postorder(Node* root) 
	{
		vector<int> ans;
		postorder(root, ans);
		return ans;
    }
};
```




