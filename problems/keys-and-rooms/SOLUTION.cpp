
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

//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<vector<int>>& rooms)
{
	return canVisitAllRooms(rooms);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

