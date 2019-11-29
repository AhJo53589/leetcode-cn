# `（中等）` [113.path-sum-ii 路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)

### 题目描述
<p>给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。</p>

<p><strong>说明:</strong>&nbsp;叶子节点是指没有子节点的节点。</p>

<p><strong>示例:</strong><br>
给定如下二叉树，以及目标和&nbsp;<code>sum = 22</code>，</p>

<pre>              <strong>5</strong>
             / \
            <strong>4</strong>   <strong>8</strong>
           /   / \
          <strong>11</strong>  13  <strong>4</strong>
         /  \    / \
        7    <strong>2</strong>  <strong>5</strong>   1
</pre>

<p>返回:</p>

<pre>[
   [5,4,11,2],
   [5,8,4,5]
]
</pre>


---
### 思路
```
```



### 答题
``` C++
void dfs(TreeNode *pNode, int sum, vector<int> path, vector<vector<int>>& ans)
{
	if (pNode == nullptr) return;
	sum -= pNode->val;
	path.push_back(pNode->val);

	if (pNode->left == nullptr && pNode->right == nullptr)
	{
		if (sum != 0) return;
		ans.push_back(path);
		return;
	}

	dfs(pNode->left, sum, path, ans);
	dfs(pNode->right, sum, path, ans);
}

vector<vector<int>> pathSum(TreeNode* root, int sum) 
{
	vector<vector<int>> ans;
	dfs(root, sum, vector<int>(), ans);
	return ans;
}
```




