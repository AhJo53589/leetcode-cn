# `（中等）` [222.count-complete-tree-nodes 完全二叉树的节点个数](https://leetcode-cn.com/problems/count-complete-tree-nodes/)

### 题目描述
<p>给出一个<strong>完全二叉树</strong>，求出该树的节点个数。</p>

<p><strong>说明：</strong></p>

<p><a href="https://baike.baidu.com/item/%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91/7773232?fr=aladdin">完全二叉树</a>的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~&nbsp;2<sup>h</sup>&nbsp;个节点。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 
    1
   / \
  2   3
 / \  /
4  5 6

<strong>输出:</strong> 6</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/count-complete-tree-nodes/solution/222-by-ikaruga/)

### 答题
``` C++
bool checkNode(TreeNode* root, int target)
{
	if (target == 1) return (root != nullptr);
	vector<int> path;
	path.push_back(target);
	while (path.back() != 2 && path.back() != 3)
	{
		path.push_back(path.back() / 2);
	}

	TreeNode *pNode = root;
	int cur = 1;
	while (!path.empty() && pNode != nullptr)
	{
		pNode = (cur * 2 == path.back()) ? pNode->left : pNode->right;
		cur = path.back();
		path.pop_back();
	}
	return (pNode != nullptr);
}

int countNodes(TreeNode* root)
{
	if (root == nullptr) return 0;
	int h = 0;
	TreeNode *pNode = root;
	while (pNode->left != nullptr)
	{
		h++;
		pNode = pNode->left;
	}

	int lo = pow(2, h);
	int hi = pow(2, h + 1);
	while (lo < hi)
	{
		int mid = lo + (hi - lo) / 2;
		if (checkNode(root, mid))
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid;
		}
	}
	return lo - 1;
}
```




