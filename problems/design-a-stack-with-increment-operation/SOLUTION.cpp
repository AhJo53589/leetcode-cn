
//////////////////////////////////////////////////////////////////////////
class CustomStack {
public:
    CustomStack(int maxSize) : m_maxSize(maxSize) {

    }
    
    void push(int x) {
        if (m_data.size() == m_maxSize) return;
        m_data.push_back(x);
    }
    
    int pop() {
        if (m_data.empty()) return -1;
        int n = m_data.back();
        m_data.pop_back();
        return n;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k && i < m_data.size(); i++)
        {
            m_data[i] += val;
        }
    }
private:
    vector<int> m_data;
    int m_maxSize;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
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

    CustomStack *obj = nullptr;
    for (auto i = 0; i < sf.size(); i++)
    {
        if (sf[i] == "CustomStack")
        {
            TestCases stc(sp[i]);
            int maxSize = stc.get<int>();
            obj = new CustomStack(maxSize);
            ans.push_back("null");
        }
        else if (sf[i] == "push")
        {
            TestCases stc(sp[i]);
            int x = stc.get<int>();
            obj->push(x);
            ans.push_back("null");
        }
        else if (sf[i] == "pop")
        {
            TestCases stc(sp[i]);
            int r = obj->pop();
            ans.push_back(convert<string>(r));
        }
        else if (sf[i] == "increment")
        {
            TestCases stc(sp[i]);
            int k = stc.get<int>();
            int val = stc.get<int>();
            obj->increment(k, val);
            ans.push_back("null");
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
