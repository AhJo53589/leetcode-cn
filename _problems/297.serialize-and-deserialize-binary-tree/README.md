# `（困难）`  [297.serialize-and-deserialize-binary-tree 二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)

### 题目描述
<p>序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。</p>

<p>请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。</p>

<p><strong>示例:&nbsp;</strong></p>

<pre>你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 <code>"[1,2,3,null,null,4,5]"</code></pre>

<p><strong>提示:&nbsp;</strong>这与 LeetCode 目前使用的方式一致，详情请参阅&nbsp;<a href="/faq/#binary-tree">LeetCode 序列化二叉树的格式</a>。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。</p>

<p><strong>说明:&nbsp;</strong>不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。</p>


---
### 思路
```
都是使用层序遍历，和leetcode的输出格式一致。
```

### 答题
``` C++
// Encodes a tree to a single string.
string serialize(TreeNode* root)
{
	string str;
	queue<TreeNode *> qTree;
	qTree.push(root);

	while (!qTree.empty())
	{
		TreeNode *qHead = qTree.front();
		qTree.pop();

		if (qHead == nullptr)
		{
			str += "null,";
			continue;
		}
		str += to_string(qHead->val);
		str += ",";
		qTree.push(qHead->left);
		qTree.push(qHead->right);
	}
	int len = str.size();
	while (true)
	{
		if (len > 1 && str.back() == ',') len -= 1;
		else break;
		if (len > 4 && str.substr(len - 4, 4) == "null") len -= 4;
		else break;
	}
	str = str.substr(0, len);
	return str;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data)
{
	auto split = [](string str, string pattern)
	{
		string::size_type Postion;
		vector<string> result;
		str += pattern;
		size_t size = str.size();
		for (size_t i = 0; i < size; i++)
		{
			Postion = str.find(pattern, i);
			if (Postion < size)
			{
				string s = str.substr(i, Postion - i);
				result.push_back(s);
				i = Postion + pattern.size() - 1;
			}
		}
		return result;
	};

	if (data.empty()) return nullptr;
	if (data.back() == '\n') data.pop_back();
	vector<string> splitData = split(data, ",");
	if (data == "" || splitData[0] == "null") return nullptr;

	TreeNode *root = new TreeNode(stoi(splitData[0].c_str()));
	queue<TreeNode *> qTree;
	qTree.push(root);

	int i = 1;
	while (!qTree.empty())
	{
		TreeNode *qHead = nullptr;
		while (qHead == nullptr)
		{
			if (qTree.empty()) return root;
			qHead = qTree.front();
			qTree.pop();
		}

		auto f = [&qTree](const string &s, TreeNode **p)
		{
			if (s == "null")
			{
				qTree.push(nullptr);
			}
			else
			{
				*p = new TreeNode(stoi(s.c_str()));
				qTree.push(*p);
			}
		};

		if (i == splitData.size()) return root;
		f(splitData[i], &qHead->left);
		i++;

		if (i == splitData.size()) return root;
		f(splitData[i], &qHead->right);
		i++;
	}
	return root;
}
```


