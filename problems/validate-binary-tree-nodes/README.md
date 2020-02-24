# `（中等）` [1361.validate-binary-tree-nodes 验证二叉树](https://leetcode-cn.com/problems/validate-binary-tree-nodes/)

[contest](https://leetcode-cn.com/contest/weekly-contest-177/problems/validate-binary-tree-nodes/)

### 题目描述
<p>二叉树上有 <code>n</code>&nbsp;个节点，按从&nbsp;<code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;编号，其中节点&nbsp;<code>i</code>&nbsp;的两个子节点分别是&nbsp;<code>leftChild[i]</code>&nbsp;和&nbsp;<code>rightChild[i]</code>。</p>

<p>只有 <strong>所有</strong> 节点能够形成且 <strong>只</strong> 形成 <strong>一颗</strong>&nbsp;有效的二叉树时，返回&nbsp;<code>true</code>；否则返回 <code>false</code>。</p>

<p>如果节点&nbsp;<code>i</code>&nbsp;没有左子节点，那么&nbsp;<code>leftChild[i]</code>&nbsp;就等于&nbsp;<code>-1</code>。右子节点也符合该规则。</p>

<p>注意：节点没有值，本问题中仅仅使用节点编号。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/23/1503_ex1.png" style="height: 287px; width: 195px;"></strong></p>

<pre><strong>输入：</strong>n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/23/1503_ex2.png" style="height: 272px; width: 183px;"></strong></p>

<pre><strong>输入：</strong>n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/23/1503_ex3.png" style="height: 174px; width: 82px;"></strong></p>

<pre><strong>输入：</strong>n = 2, leftChild = [1,0], rightChild = [-1,-1]
<strong>输出：</strong>false
</pre>

<p><strong>示例 4：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/23/1503_ex4.png" style="height: 191px; width: 470px;"></strong></p>

<pre><strong>输入：</strong>n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^4</code></li>
	<li><code>leftChild.length == rightChild.length == n</code></li>
	<li><code>-1 &lt;= leftChild[i], rightChild[i] &lt;= n - 1</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
	{
		vector<int> inDegree(n, 0);
		for (int i = 0; i < leftChild.size(); i++)
		{
			if (leftChild[i] != -1)
			{
				inDegree[leftChild[i]]++;
			}
			if (rightChild[i] != -1)
			{
				inDegree[rightChild[i]]++;
			}
		}
		int root = -1;
		for (int i = 0; i < inDegree.size(); i++)
		{
			if (inDegree[i] != 0) continue;
			if (root != -1) return false;
			root = i;
		}
		if (root == -1) return false;

		vector<int> vi(n, 0);
		queue<int> que;
		que.push(root);
		vi[root] = 1;

		while (!que.empty())
		{
			auto q = que.front();
			que.pop();

			if (leftChild[q] != -1)
			{
				if (vi[leftChild[q]] == 1) return false;
				que.push(leftChild[q]);
				vi[leftChild[q]] = 1;
			}
			if (rightChild[q] != -1)
			{
				if (vi[rightChild[q]] == 1) return false;
				que.push(rightChild[q]);
				vi[rightChild[q]] = 1;
			}
		}
		return all_of(vi.begin(), vi.end(), [](const int& a) { return a == 1; });
    }
};
```




