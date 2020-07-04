
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//////////////////////////////////////////////////////////////////////////
class Codec 
{
public:
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

			auto f = [&qTree](string &s, TreeNode **p)
			{
				while (s.front() == ' ') s = s.substr(1, s.size() - 1);
				while (s.back() == ' ') s.pop_back();
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
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


//////////////////////////////////////////////////////////////////////////
//string _solution_run(TreeNode* root)
//{
//	return serialize(root);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
	TreeNode* root = tc.get<TreeNode*>();
	Codec codec;
	string ans = codec.serialize(root);
	cout << "serialize -> " << ans << endl;
	TreeNode* root2 = codec.deserialize(ans);
	ans = TreeNodeToString(root2);
	cout << "deserialize -> " << ans << endl;
	return ans;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

