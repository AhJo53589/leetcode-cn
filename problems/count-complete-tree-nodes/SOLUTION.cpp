

//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	return countNodes(root);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

