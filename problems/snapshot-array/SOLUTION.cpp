
//////////////////////////////////////////////////////////////////////////
class SnapshotArray {
public:
    SnapshotArray(int length) {

    }
    
    void set(int index, int val) {
		record[index][snap_times] = val;
    }
    
    int snap() {
		return snap_times++;
    }
    
    int get(int index, int snap_id) {
		return record[index].lower_bound(snap_id)->second;
    }

private:
	unordered_map<int, map<int, int, greater<int>>> record;
	int snap_times = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

//////////////////////////////////////////////////////////////////////////
//int _solution_run(int)
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<string> sp = tc.get<vector<string>>();
	vector<string> ans;

	SnapshotArray *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "SnapshotArray")
		{
			TestCases stc(sp[i]);
			int length = stc.get<int>();
			obj = new SnapshotArray(length);
			ans.push_back("null");
		}
		else if (sf[i] == "set")
		{
			TestCases stc(sp[i]);
			int index = stc.get<int>();
			int val = stc.get<int>();
			obj->set(index, val);
			ans.push_back("null");
		}
		else if (sf[i] == "snap")
		{
			TestCases stc(sp[i]);
			int r = obj->snap();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "get")
		{
			TestCases stc(sp[i]);
			int index = stc.get<int>();
			int snap_id = stc.get<int>();
			int r = obj->get(index, snap_id);
			ans.push_back(convert<string>(r));
		}
	}
	delete obj;

	return convert<string>(ans);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
