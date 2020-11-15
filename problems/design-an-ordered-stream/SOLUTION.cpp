
//////////////////////////////////////////////////////////////////////////
class OrderedStream {
public:
    OrderedStream(int n) {
        data = vector<string>(n);
    }

    vector<string> insert(int id, string value) {
        id--;
        data[id] = value;
        if (ptr != id) return {};
        vector<string> ans;
        for (; ptr < data.size() && data[ptr] != ""; ptr++) {
            ans.push_back(data[ptr]);
        }
        return ans;
    }

private:
    int ptr = 0;
    vector<string> data;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */

 //////////////////////////////////////////////////////////////////////////
 //int _solution_run(int)
 //{
 //}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
    vector<string> sf = tc.get<vector<string>>();
    vector<string> sp = tc.get<vector<string>>();
    vector<string> ans;

    OrderedStream* obj = nullptr;
    for (auto i = 0; i < sf.size(); i++)
    {
        if (sf[i] == "OrderedStream")
        {
            TestCases stc(sp[i]);
            int n = stc.get<int>();
            obj = new OrderedStream(n);
            ans.push_back("null");
        }
        else if (sf[i] == "insert")
        {
            TestCases stc(sp[i]);
            int id = stc.get<int>();
            string value = stc.get<string>();
            vector<string> r = obj->insert(id, value);
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
