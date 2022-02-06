
//////////////////////////////////////////////////////////////////////////
class Bitset {
public:
    Bitset(int size) : m_size(size) {

    }

    void fix(int idx) {
        if (!m_flip) {
            fixed.insert(idx);
        }
        else {
            fixed.erase(idx);
        }
    }

    void unfix(int idx) {
        if (!m_flip) {
            fixed.erase(idx);
        }
        else {
            fixed.insert(idx);
        }
    }

    void flip() {
        m_flip = !m_flip;
    }

    bool all() {
        return count() == m_size;
    }

    bool one() {
        return count() != 0;
    }

    int count() {
        if (!m_flip) {
            return fixed.size();
        }
        else {
            return m_size - fixed.size();
        }
    }

    string toString() {
        string ans;
        for (int i = 0; i < m_size; i++) {
            ans += (!m_flip && fixed.find(i) != fixed.end()) || (m_flip && fixed.find(i) == fixed.end()) ? "1" : "0";
        }
        return ans;
    }

private:
    int m_size = 0;
    unordered_set<int> fixed;
    bool m_flip = false;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
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

    Bitset* obj = nullptr;
    for (auto i = 0; i < sf.size(); i++)
    {
        if (sf[i] == "Bitset")
        {
            TestCases stc(sp[i]);
            int size = stc.get<int>();
            obj = new Bitset(size);
            ans.push_back("null");
        }
        else if (sf[i] == "fix")
        {
            TestCases stc(sp[i]);
            int idx = stc.get<int>();
            obj->fix(idx);
            ans.push_back("null");
        }
        else if (sf[i] == "unfix")
        {
            TestCases stc(sp[i]);
            int idx = stc.get<int>();
            obj->unfix(idx);
            ans.push_back("null");
        }
        else if (sf[i] == "flip")
        {
            TestCases stc(sp[i]);
            obj->flip();
            ans.push_back("null");
        }
        else if (sf[i] == "all")
        {
            TestCases stc(sp[i]);
            bool r = obj->all();
            ans.push_back(convert<string>(r));
        }
        else if (sf[i] == "one")
        {
            TestCases stc(sp[i]);
            bool r = obj->one();
            ans.push_back(convert<string>(r));
        }
        else if (sf[i] == "count")
        {
            TestCases stc(sp[i]);
            int r = obj->count();
            ans.push_back(convert<string>(r));
        }
        else if (sf[i] == "toString")
        {
            TestCases stc(sp[i]);
            string r = obj->toString();
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
