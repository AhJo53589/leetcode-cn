
//////////////////////////////////////////////////////////////////////////
class MKAverage {
public:
    MKAverage(int _m, int _k) : m(_m), k(_k) {

    }

    void addElement(int num) {
        que.push(num);

        if (!isReady) {
            Init(num);
            return;
        }
        
        add(num);
        remove(que.front());
        que.pop();
    }

    int calculateMKAverage() {
        if (isReady) {
            int ans = sum / (m - 2 * k);
        }
        return (!isReady) ? -1 : sum / (m - 2 * k);
    }

private:
    void Init(int num) {
        data.push_back(num);
        if (data.size() == m) {
            sort(data.begin(), data.end());
            for (int i = 0; i < data.size(); i++) {
                if (i < k) {
                    set_low.insert(data[i]);
                }
                else if (i < m - k) {
                    set_mid.insert(data[i]);
                    sum += data[i];
                }
                else {
                    set_high.insert(data[i]);
                }
            }
            isReady = true;
        }
    }

    void add(int num) {
        if (*set_low.rbegin() > num) {
            int e = *set_low.rbegin();
            moveNum(set_low, e, set_mid);
            sum += e;

            set_low.insert(num);
        }
        else if (*set_high.begin() < num) {
            int e = *set_high.begin();
            moveNum(set_high, e, set_mid);
            sum += e;

            set_high.insert(num);
        }
        else {
            set_mid.insert(num);
            sum += num;
        }
    }

    void remove(int num) {
        if (set_mid.find(num) != set_mid.end()) {
            set_mid.erase(set_mid.find(num));
            sum -= num;
        }
        else if (set_low.find(num) != set_low.end()) {
            set_low.erase(set_low.find(num));
            int e = *set_mid.begin();
            moveNum(set_mid, e, set_low);
            sum -= e;
        }
        else {
            set_high.erase(set_high.find(num));
            int e = *set_mid.rbegin();
            moveNum(set_mid, e, set_high);
            sum -= e;
        }
    }

    void moveNum(multiset<int>& a_set, int a, multiset<int>& b_set) {
        b_set.insert(a);
        a_set.erase(a_set.find(a));
    }

private:
    int m;
    int k;

    bool isReady = false;

    queue<int> que;
    vector<int> data;
    multiset<int> set_low;
    multiset<int> set_mid;
    multiset<int> set_high;
    long long sum = 0;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
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

    MKAverage* obj = nullptr;
    for (auto i = 0; i < sf.size(); i++)
    {
        if (sf[i] == "MKAverage")
        {
            TestCases stc(sp[i]);
            int m = stc.get<int>();
            int k = stc.get<int>();
            obj = new MKAverage(m, k);
            ans.push_back("null");
        }
        else if (sf[i] == "addElement")
        {
            TestCases stc(sp[i]);
            int num = stc.get<int>();
            obj->addElement(num);
            ans.push_back("null");
        }
        else if (sf[i] == "calculateMKAverage")
        {
            TestCases stc(sp[i]);
            int r = obj->calculateMKAverage();
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
