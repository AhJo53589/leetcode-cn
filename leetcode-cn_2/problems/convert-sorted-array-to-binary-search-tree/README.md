# `（简单）` [108.convert-sorted-array-to-binary-search-tree 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)

### 题目描述
<p>将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。</p>

<p>本题中，一个高度平衡二叉树是指一个二叉树<em>每个节点&nbsp;</em>的左右两个子树的高度差的绝对值不超过 1。</p>

<p><strong>示例:</strong></p>

<pre>给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
</pre>




---
### 思路
```
就很迷，我这20ms的代码和8ms的代码基本一样。  

这道题基本上就是二分查找法的应用了。  
```


### 答题
``` C++
TreeNode* sortedArrayToBST(vector<int>& nums, size_t _First, size_t _Last) 
{
	if (_Last <= _First) return NULL;

	size_t _Mid = _First + (_Last - _First) / 2;
	TreeNode *pNode = new TreeNode(nums[_Mid]);
	TreeNode *pLeft = sortedArrayToBST(nums, _First, _Mid);
	TreeNode *pRight = sortedArrayToBST(nums, _Mid + 1, _Last);
	pNode->left = pLeft;
	pNode->right = pRight;
	return pNode;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
	size_t _First = 0;
	size_t _Last = nums.size();
	if (_Last == 0) return NULL;

	return sortedArrayToBST(nums, _First, _Last);
}
``` 
