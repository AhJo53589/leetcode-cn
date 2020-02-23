
//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int n, vector<int>& leftChild, vector<int>& rightChild)
{
	cout << "n = " << n << endl;
	cout << convert<string>(leftChild) << endl;
	cout << convert<string>(rightChild) << endl;
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.validateBinaryTreeNodes(n, leftChild, rightChild);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
