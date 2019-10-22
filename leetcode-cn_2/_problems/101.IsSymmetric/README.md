# `（简单）`  [101.IsSymmetric 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)

### 题目描述
<p>给定一个二叉树，检查它是否是镜像对称的。</p>

<p>例如，二叉树&nbsp;<code>[1,2,2,3,4,4,3]</code> 是对称的。</p>

<pre>    1
   / \
  2   2
 / \ / \
3  4 4  3
</pre>

<p>但是下面这个&nbsp;<code>[1,2,2,null,3,null,3]</code> 则不是镜像对称的:</p>

<pre>    1
   / \
  2   2
   \   \
   3    3
</pre>

<p><strong>说明:</strong></p>

<p>如果你可以运用递归和迭代两种方法解决这个问题，会很加分。</p>



---
### 思路
```
终于之前的凑活用的初始化initTree遇到了bug。  
无法区分0和null，  
重新写了字符串方法来初始化。  

这道题本身，用之前的queue方法可以解决。  
看了题解，镜像的方式也不错，代码看着真简洁。  
分享别人mirror的方法。
```


### 答题
``` C++
// mirror
bool mirror(TreeNode *l, TreeNode *r)
{
	if (!l && !r) return true;
	if (!l && r) return false;
	if (l && !r) return false;
	if (l->val != r->val) return false;
	return mirror(l->left, r->right) && mirror(l->right, r->left);
}

bool isSymmetric(TreeNode* root)  // 4ms
{
	if (!root) return true;
	return mirror(root->left, root->right);
}
// end
``` 