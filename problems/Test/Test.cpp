// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

#include "..\Common\Common.h"
#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
using namespace std;

void visitRoom(vector<vector<int>>& rooms, int roomId, unordered_set<int>& visited)
{
	if (roomId >= rooms.size()) return;

	visited.insert(roomId);
	for (auto r : rooms[roomId])
	{
		if (!visited.count(r))
		{
			visitRoom(rooms, r, visited);
		}
	}
}

bool canVisitAllRooms(vector<vector<int>>& rooms) 
{
	unordered_set<int> visited;
	visitRoom(rooms, 0, visited);
	for (int i = 0; i < rooms.size(); i++)
	{
		if (!visited.count(i)) return false;
	}
	return true;
}

int main()
{
	//string strInit = "[[1],[2],[3],[]]";
	string strInit = "[[1,3],[3,0,1],[2],[0]]";

	vector<vector<int>> m = StringToVectorVectorInt(strInit);

	cout << canVisitAllRooms(m) << endl;

}
