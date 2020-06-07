
//////////////////////////////////////////////////////////////////////////
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur = 0;
        last = cur + 1;
    }

    void visit(string url) {
        if (cur == history.size() - 1) {
            history.push_back(url);
        }
        else {
            history[cur + 1] = url;
        }
        cur += 1;
        last = cur + 1;
    }

    string back(int steps) {
        steps = min(cur, steps);
        cur -= steps;
        return history[cur];
    }

    string forward(int steps) {
        steps = min(last - cur - 1, steps);
        cur += steps;
        return history[cur];
    }

private:
    vector<string> history;
    int cur = 0;
    int last = 0;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
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

    BrowserHistory* obj = nullptr;
    for (auto i = 0; i < sf.size(); i++)
    {
        if (sf[i] == "BrowserHistory")
        {
            TestCases stc(sp[i]);
            string homepage = stc.get<string>();
            obj = new BrowserHistory(homepage);
            ans.push_back("null");
        }
        else if (sf[i] == "visit")
        {
            TestCases stc(sp[i]);
            string url = stc.get<string>();
            obj->visit(url);
            ans.push_back("null");
        }
        else if (sf[i] == "back")
        {
            TestCases stc(sp[i]);
            int steps = stc.get<int>();
            string r = obj->back(steps);
            ans.push_back(convert<string>(r));
        }
        else if (sf[i] == "forward")
        {
            TestCases stc(sp[i]);
            int steps = stc.get<int>();
            string r = obj->forward(steps);
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
//    return {};
//}
