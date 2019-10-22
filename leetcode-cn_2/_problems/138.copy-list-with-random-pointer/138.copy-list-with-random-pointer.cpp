// 138.copy-list-with-random-pointer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};


Node* copyRandomList(Node* head)
{
	map<Node *, Node *> visited;
	visited[NULL] = NULL;

	Node *pPrev = NULL;
	Node *pNode = head;
	while (pNode != NULL)
	{
		Node *pNew = new Node();
		visited[pNode] = pNew;
		pNode = pNode->next;
	}
	pNode = head;
	while (pNode != NULL)
	{
		Node *pNew = visited[pNode];
		pNew->val = pNode->val;
		pNew->random = visited[pNode->random];
		pNew->next = NULL;
		if (pPrev != NULL)
		{
			visited[pPrev]->next = pNew;
		}
		pPrev = pNode;
		pNode = pNode->next;
	}
	return visited[head];
}



int main()
{
}
