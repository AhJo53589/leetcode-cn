# `（中等）` [1261.find-elements-in-a-contaminated-binary-tree 在受污染的二叉树中查找元素](https://leetcode-cn.com/problems/find-elements-in-a-contaminated-binary-tree/)

[contest](https://leetcode-cn.com/contest/weekly-contest-163/problems/find-elements-in-a-contaminated-binary-tree/)

### 题目描述
<p>给出一个满足下述规则的二叉树：</p>

<ol>
	<li><code>root.val == 0</code></li>
	<li>如果 <code>treeNode.val == x</code> 且&nbsp;<code>treeNode.left != null</code>，那么&nbsp;<code>treeNode.left.val == 2 * x + 1</code></li>
	<li>如果 <code>treeNode.val == x</code> 且 <code>treeNode.right != null</code>，那么&nbsp;<code>treeNode.right.val == 2 * x + 2</code></li>
</ol>

<p>现在这个二叉树受到「污染」，所有的&nbsp;<code>treeNode.val</code>&nbsp;都变成了&nbsp;<code>-1</code>。</p>

<p>请你先还原二叉树，然后实现&nbsp;<code>FindElements</code>&nbsp;类：</p>

<ul>
	<li><code>FindElements(TreeNode* root)</code>&nbsp;用受污染的二叉树初始化对象，你需要先把它还原。</li>
	<li><code>bool find(int target)</code>&nbsp;判断目标值&nbsp;<code>target</code>&nbsp;是否存在于还原后的二叉树中并返回结果。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/16/untitled-diagram-4-1.jpg" style="height: 119px; width: 320px;"></strong></p>

<pre><strong>输入：</strong>
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
<strong>输出：</strong>
[null,false,true]
<strong>解释：</strong>
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True </pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/16/untitled-diagram-4.jpg" style="height: 198px; width: 400px;"></strong></p>

<pre><strong>输入：</strong>
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
<strong>输出：</strong>
[null,true,true,false]
<strong>解释：</strong>
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/16/untitled-diagram-4-1-1.jpg" style="height: 274px; width: 306px;"></strong></p>

<pre><strong>输入：</strong>
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
<strong>输出：</strong>
[null,true,false,false,true]
<strong>解释：</strong>
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>TreeNode.val == -1</code></li>
	<li>二叉树的高度不超过&nbsp;<code>20</code></li>
	<li>节点的总数在&nbsp;<code>[1,&nbsp;10^4]</code>&nbsp;之间</li>
	<li>调用&nbsp;<code>find()</code>&nbsp;的总次数在&nbsp;<code>[1,&nbsp;10^4]</code>&nbsp;之间</li>
	<li><code>0 &lt;= target &lt;= 10^6</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class FindElements 
{
public:
	FindElements(TreeNode* root) 
	{
		if (root == nullptr) return;
		root->val = 0;
		s.insert(0);

		queue<TreeNode*> qt;
		qt.push(root);

		while (!qt.empty())
		{
			auto p = qt.front();
			qt.pop();

			if (p->left != nullptr)
			{
				p->left->val = p->val * 2 + 1;
				qt.push(p->left);
				s.insert(p->left->val);
			}
			if (p->right != nullptr)
			{
				p->right->val = p->val * 2 + 2;
				qt.push(p->right);
				s.insert(p->right->val);
			}
		}
	}

	bool find(int target)
	{
		return s.count(target);
	}

private:
	unordered_set<int> s;
};
```




