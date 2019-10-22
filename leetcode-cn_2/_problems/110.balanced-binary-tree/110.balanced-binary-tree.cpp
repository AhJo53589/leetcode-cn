// 110.balanced-binary-tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////
int getTreeHeight(TreeNode *pNode)
{
	if (pNode == nullptr) return 0;
	int l = getTreeHeight(pNode->left);
	int r = getTreeHeight(pNode->right);
	if (l == -1 || r == -1 || abs(l - r) > 1) return -1;
	return max(l, r) + 1;
}

bool isBalanced(TreeNode* root)
{
	return getTreeHeight(root) != -1;
}


int main()
{
	vector<TreeNode *> N;
	vector<int> K;
	vector<bool> A;

	N.push_back(StringToTreeNode("3,9,20,null,null,15,7"));
	//K.push_back(3);
	A.push_back(true);

	N.push_back(StringToTreeNode("1,2,2,3,3,null,null,4,4"));
	//K.push_back(3);
	A.push_back(false);

	N.push_back(StringToTreeNode("1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5"));
	//K.push_back(3);
	A.push_back(true);

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		cout << N[i] << endl;
		//DrawTreeNode(N[i]);

		bool ans = isBalanced(N[i]);
		cout << "isBalanced = " << endl << A[i] << endl;
		cout << "My answer = " << endl << ans << endl;
		//DrawTreeNode(ans);

	}
}