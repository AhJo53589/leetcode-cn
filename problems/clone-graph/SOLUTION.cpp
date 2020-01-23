
/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
*/


//////////////////////////////////////////////////////////////////////////
//Node* cloneGraph(Node* node) {
//	unordered_map<Node*, Node*> toCopy;
//	return clone(node, toCopy);
//}
//Node* clone(Node* root, unordered_map<Node*, Node*>& toCopy) {
//	if (toCopy.find(root) != toCopy.end()) return toCopy[root];
//	Node* res = new Node(root->val, vector<Node*>({}));
//	toCopy.insert({ root, res });
//	for (Node* p : root->neighbors)
//		res->neighbors.push_back(clone(p, toCopy));
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
Node* cloneGraph(Node* node)
{
	if (node == NULL) return NULL;

	map<Node*, Node*> visited;
	stack<Node*> s;

	s.push(node);
	while (!s.empty())
	{
		Node* cur = s.top();
		s.pop();
		if (visited.count(cur) == 0)
		{
			Node* pNew = new Node();
			visited[cur] = pNew;
			for (auto n : cur->neighbors)
			{
				s.push(n);
			}
		}
	}

	for (auto i = visited.begin(); i != visited.end(); i++)
	{
		(i->second)->val = (i->first)->val;
		for (auto n : (i->first)->neighbors)
		{
			(i->second)->neighbors.push_back(visited[n]);
		}
	}

	return visited[node];
}


//////////////////////////////////////////////////////////////////////////
//Node* _solution_run(Node* root)
//{
//	return connect(root);
//}


//#define NODE_DEFINE_EXCULDE_DEFAULT
//#define LEETCODE_PROBLEM_133

#define USE_SOLUTION_CUSTOM
//Node* _solution_custom(TestCases& tc)
string _solution_custom(TestCases& tc)
{
	Node* root = StringToNode(tc.get<string>());
	Node* ret = cloneGraph(root);
	string ans = NodeToString(ret);
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/clone-graph/tests.txt";
}

