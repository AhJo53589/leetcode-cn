# `（简单）` [104.maximum-depth-of-binary-tree 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

### 题目描述
<p>给定一个二叉树，找出其最大深度。</p>

<p>二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。</p>

<p><strong>说明:</strong>&nbsp;叶子节点是指没有子节点的节点。</p>

<p><strong>示例：</strong><br>
给定二叉树 <code>[3,9,20,null,null,15,7]</code>，</p>

<pre>    3
   / \
  9  20
    /  \
   15   7</pre>

<p>返回它的最大深度&nbsp;3 。</p>




---
### 思路
```
```


### 答题
``` C++
int maxDepth(TreeNode* root)
{
	if (root == NULL) return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
``` 

### 其它
额，这道题写初始化函数和输出函数写了1个多小时，  
还因为把queue用错了vector调试了一会儿，  
再现了vector因为push_back，  
扩大内存而导致iter失效的问题。  

然后maxDepth写了1分钟，一次过。
