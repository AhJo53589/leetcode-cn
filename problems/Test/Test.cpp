// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>

#include <algorithm>
#include <array>
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
#include <sstream>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.Hi"
//#include "..\Common\TreeNode.Hi"
//#include "..\Common\ListNode.Hi"
using namespace std;


//////////////////////////////////////////////////////////////////////////
//void nextPermutation(vector<int>& nums) 
//{
//	if (nums.empty()) return;
//
//	vector<int> vec;
//	for (size_t i = nums.size() - 1; i > 0;)
//	{
//		i--;
//		vec.push_back(nums[i + 1]);
//		if (nums[i] < nums[i + 1])
//		{
//			sort(vec.begin(), vec.end());
//			auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
//			swap(nums[i], *it);
//			for (size_t j = 0; j < vec.size(); j++)
//			{
//				nums[j + i + 1] = vec[j];
//			}
//			break;
//		}
//	}
//}

//////////////////////////////////////////////////////////////////////////
//int game(vector<int>& guess, vector<int>& answer)
//{
//	int ans = 0;
//	for (size_t i = 0; i < guess.size(); i++)
//	{
//		ans = (guess[i] == answer[i]) ? ans + 1 : ans;
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
//int gcd(int a, int b)
//{
//	return b == 0 ? a : gcd(b, a % b);
//}
//
//void fraction(vector<int>& cont, size_t last, vector<int>& val)
//{
//	if (last == cont.size() - 1)
//	{
//		last--;
//		val[0] = cont[last + 1];
//		val[1] = cont[last] * cont[last + 1] + 1;
//		cout << "val[0] = " << val[0] << ", val[1] = " << val[1] << endl;
//	}
//	else if (last != 0)
//	{
//		last--;
//		int temp = val[1];
//		val[1] = cont[last] * val[1] + val[0];
//		val[0] = temp;
//		cout << "val[0] = " << val[0] << ", val[1] = " << val[1] << endl;
//	}
//	int g = gcd(val[0], val[1]);
//	val[0] /= g;
//	val[1] /= g;
//	cout << "val[0] = " << val[0] << ", val[1] = " << val[1] << endl;
//	if (last == 0)
//	{
//		swap(val[0], val[1]);
//		return;
//	}
//	fraction(cont, last, val);
//}
//
//vector<int> fraction(vector<int>& cont)
//{
//	if (cont.size() == 1) return { cont[0], 1 };
//	vector<int> val(2, 0);
//	fraction(cont, cont.size() - 1, val);
//	return val;
//}

//////////////////////////////////////////////////////////////////////////
//bool robot(string command, vector<vector<int>>& obstacles, int x, int y) 
//{
//	vector<vector<int>> ob2(obstacles.begin(), obstacles.end());
//	sort(obstacles.begin(), obstacles.end(), [](const vector<int>& a, const vector<int>& b)
//	{
//		return a[0] < b[0];
//	});
//	sort(ob2.begin(), ob2.end(), [](const vector<int>& a, const vector<int>& b)
//	{
//		return a[1] < b[1];
//	});
//
//	size_t i_x = 0;
//	size_t i_y = 0;
//
//	vector<int> pos(2, 0);
//	while (true)
//	{
//		for (auto &c : command)
//		{
//			if (pos[0] == x && pos[1] == y) return true;
//			if (pos[0] > x || pos[1] > y) return false;
//
//			if (c == 'R')
//			{
//				pos[0]++;
//				if (obstacles.size() == 0) continue;
//				while (i_x < obstacles.size() && obstacles[i_x][0] < pos[0]) i_x++;
//				while (i_x < obstacles.size() && obstacles[i_x][0] == pos[0])
//				{
//					if (obstacles[i_x][1] == pos[1]) return false;
//					i_x++;
//				}
//			}
//			else if (c == 'U')
//			{
//				pos[1]++;
//				if (ob2.size() == 0) continue;
//				while (i_y < ob2.size() && ob2[i_y][1] < pos[1]) i_y++;
//				while (i_y < ob2.size() && ob2[i_y][1] == pos[1])
//				{
//					if (ob2[i_y][0] == pos[0]) return false;
//					i_y++;
//				}
//			}
//		}
//	}
//	return false;
//}

//////////////////////////////////////////////////////////////////////////
const int mod = 1000000007;

struct Person
{
	Person() : parent(nullptr), coins(0), all_coins(0) {}
	Person *parent;
	vector<Person *> childs;
	int coins;
	int all_coins;
};

void addCoins(Person *p, int coins)
{
	if (p == nullptr) return;
	p->coins += coins;
	p->coins %= mod;

	addCoinsAllUp(p, coins);
}

void addCoinsAllUp(Person *p, int coins)
{
	if (p == nullptr) return;
	p->all_coins += coins;
	p->all_coins %= mod;
	addCoinsAllUp(p->parent, coins);
}

void addCoinsDown(Person *p, int coins)
{
	if (p == nullptr) return;
	for (auto pChild : p->childs)
	{
		addCoins(pChild, coins);
	}

	p->coins += coins;
	p->coins %= mod;
}

void getCoins(Person *p, int &val)
{
	if (p == nullptr) return;
	val += p->coins;

	for (auto pChild : p->childs)
	{
		getCoins(pChild, val);
	}
}

int getChildsCount(Person *p)
{
	if (p == nullptr) return;
	int cnt = 0;
	for (auto &pChild : p->childs)
	{
		cnt += pChild->childs.size();
	}
	return cnt;
}

vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations)
{
	unordered_map<int, Person *> _map;
	unordered_map<int, int> _map_childs;
	for (int i = 1; i <= n; i++)
	{
		_map[i] = new Person();
	}
	for (auto &l : leadership)
	{
		_map[l[0]]->childs.push_back(_map[l[1]]);
		_map[l[1]]->parent = _map[l[0]];
	}
	for (int i = n; i >= 1; i--)
	{
		_map_childs[i] = getChildsCount(_map[i]);
	}


	vector<int> ans;
	for (auto &op : operations)
	{
		if (op[0] == 1)
		{
			_map[op[1]]->coins += op[2];
		}
		else if (op[0] == 2)
		{
			addCoins(_map[op[1]], op[2]);
		}
		else if (op[0] == 3)
		{
			int val = 0;
			getCoins(_map[op[1]], val);
			val %= mod;
			ans.push_back(val);
		}
	}

	return ans;
}

int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);

	auto f_time_cout = [&]()
	{
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	//vector<vector<vector<int>>> TESTS;
	////vector<int> K;
	//vector<vector<int>> ANSWERS;

	//TESTS.push_back({ 3,2,0,2 });
	//ANSWERS.push_back({ 13,4 });

	//TESTS.push_back({ 0,0,3 });
	//ANSWERS.push_back({ 3,1 });

	//TESTS.push_back({ 3 });
	//ANSWERS.push_back({ 3,1 });

	//////////////////////////////////////////////////////////////////////////
	//vector<vector<vector<int>>> TESTS;
	//vector<string> C;
	//vector<int> X;
	//vector<int> Y;
	//vector<bool> ANSWERS;

	//TESTS.push_back({  });
	//C.push_back("URR");
	//X.push_back(3);
	//Y.push_back(2);
	//ANSWERS.push_back(true);

	//TESTS.push_back({ {2,2} });
	//C.push_back("URR");
	//X.push_back(3);
	//Y.push_back(2);
	//ANSWERS.push_back(false);

	//TESTS.push_back({ {4,2} });
	//C.push_back("URR");
	//X.push_back(3);
	//Y.push_back(2);
	//ANSWERS.push_back(true);

	//////////////////////////////////////////////////////////////////////////
	vector<int> TESTS;
	vector<vector<vector<int>>> L;
	vector<vector<vector<int>>> O;
	vector<vector<int>> ANSWERS;

	TESTS.push_back(6);
	L.push_back({ {1, 2},{1, 6},{2, 3},{2, 5},{1, 4} });
	O.push_back({ {1, 1, 500},{2, 2, 50},{3, 1},{2, 6, 15},{3, 1} });
	ANSWERS.push_back({ 650, 665 });

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = bonus(TESTS[i], L[i], O[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
		//nextPermutation(TESTS[i]);
		//cout << checkAnswer<vector<int>>(TESTS[i], ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}


//////////////////////////////////////////////////////////////////////////
// TreeNode
//int main()
//{
//	vector<TreeNode *> N;
//	vector<int> K;
//	vector<bool> A;
//
//	N.push_back(StringToTreeNode("3,9,20,null,null,15,7"));
//	//K.push_back(3);
//	A.push_back(true);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,null,null,4,4"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "///////////////////////////////////////" << endl;
//		cout << N[i] << endl;
//		//DrawTreeNode(N[i]);
//
//		bool ans = isBalanced(N[i]);
//		cout << checkAnswer<bool>(ans, A[i]) << endl;
//		//DrawTreeNode(ans);
//
//	}
//}


//////////////////////////////////////////////////////////////////////////
// List Node
//int main()
//{
//	vector<ListNode *> lists;
//	ListNode *pHead = StringToListNode("[4,7,5,3]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//	for (auto i : lists)
//	{
//		cout << i << endl;
//		pHead = sortList(i);
//		cout << pHead << endl;
//		cout << endl;
//	}
//}


