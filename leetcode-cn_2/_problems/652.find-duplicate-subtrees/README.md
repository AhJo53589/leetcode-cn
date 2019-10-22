# `（中等）`  [652.find-duplicate-subtrees 寻找重复的子树](https://leetcode-cn.com/problems/find-duplicate-subtrees/)

### 题目描述
<p>给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意<strong>一棵</strong>的根结点即可。</p>

<p>两棵树重复是指它们具有相同的结构以及相同的结点值。</p>

<p><strong>示例 1：</strong></p>

<pre>        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
</pre>

<p>下面是两个重复的子树：</p>

<pre>      2
     /
    4
</pre>

<p>和</p>

<pre>    4
</pre>

<p>因此，你需要以列表的形式返回上述重复子树的根结点。</p>


---
### 思路
```
设计哈希函数构建键值。  
就是把TreeNode翻译成String。
```

### 答题
``` C++
string TreeNodeToString(TreeNode * root)
{
	string str;
	queue<TreeNode *> qTree;
	qTree.push(root);

	while (!qTree.empty())
	{
		TreeNode *qHead = qTree.front();
		qTree.pop();

		if (qHead == NULL)
		{
			str += "NULL - ";
			continue;
		}
		str += to_string(qHead->val);
		str += " - ";
		qTree.push(qHead->left);
		qTree.push(qHead->right);
	}
	str += "\n";
	return str;
}
    
unordered_map<string, TreeNode *> m;
unordered_set<string> s;
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
{
	vector<TreeNode *> treeList;
	if (root == NULL) return treeList;

	string str = TreeNodeToString(root);
	if (!m.count(str)) m[str] = root;
	else if (!s.count(str))
	{
		s.insert(str);
		treeList.push_back(root);
	}

	vector<TreeNode *> left = findDuplicateSubtrees(root->left);
	treeList.insert(treeList.end(), left.begin(), left.end());
	vector<TreeNode *> right = findDuplicateSubtrees(root->right);
	treeList.insert(treeList.end(), right.begin(), right.end());

	return treeList;
}
```

### 其它
``` C++
    unordered_map<string,vector<TreeNode*>>treeInfo;
    vector<TreeNode*>ans;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        buildTreeMap(root);
        for(auto i : treeInfo){
            if(i.second.size()>1){
                ans.push_back(i.second.front());
            }
        }
        return ans;
    }
    string buildTreeMap(TreeNode* node){
        if(node==NULL) return "N";
        string left = buildTreeMap(node->left);
        string right = buildTreeMap(node->right);
        string s = to_string(node->val) + left + right;
        treeInfo[s].push_back(node);
        return s;
    }
```


``` C++
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
	if (root == NULL)
		return {};
	
	vector<TreeNode*> res;
	unordered_map<string, int> mp;
	dfs(root, res, mp);
	
	return res;
}

string dfs(TreeNode* root, vector<TreeNode*> &ans, unordered_map<string, int> &mp) {
	if (root == NULL) 
		return "x";

	string tmp = to_string(root->val) + dfs(root->left, ans, mp) + dfs(root->right, ans, mp);

	if (mp[tmp] == 1) 
		ans.push_back(root);

	mp[tmp]++;

	return tmp;
}
```
