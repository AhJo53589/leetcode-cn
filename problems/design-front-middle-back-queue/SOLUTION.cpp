
//////////////////////////////////////////////////////////////////////////
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        head.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        if (head.size() < tail.size()) {
            head.push_back(val);
        }
        else {
            tail.push_front(val);
        }
    }

    void pushBack(int val) {
        tail.push_back(val);
        balance();
    }

    int popFront() {
        if (tail.empty()) return -1;
        if (head.empty()) {
            int ret = tail.front();
            tail.pop_front();
            return ret;
        }

        int ret = head.front();
        head.pop_front();
        balance();
        return ret;
    }

    int popMiddle() {
        if (tail.empty()) return -1;

        if (tail.size() > head.size()) {
            int ret = tail.front();
            tail.pop_front();
            return ret;
        }

        if (head.empty()) return -1;

        int ret = head.back();
        head.pop_back();
        return ret;
    }

    int popBack() {
        if (tail.empty()) return -1;

        int ret = tail.back();
        tail.pop_back();
        balance();
        return ret;
    }

    void balance() {
        if (head.size() > tail.size()) {
            tail.push_front(head.back());
            head.pop_back();
        }
        else if (tail.size() - head.size() == 2) {
            head.push_back(tail.front());
            tail.pop_front();
        }
    }

private:
    deque<int> head;
    deque<int> tail;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
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

    FrontMiddleBackQueue* obj = nullptr;
    for (auto i = 0; i < sf.size(); i++)
    {
        if (sf[i] == "FrontMiddleBackQueue")
        {
            obj = new FrontMiddleBackQueue();
            ans.push_back("null");
        }
        else if (sf[i] == "pushFront")
        {
            TestCases stc(sp[i]);
            int val = stc.get<int>();
            obj->pushFront(val);
            ans.push_back("null");
        }
        else if (sf[i] == "pushMiddle")
        {
            TestCases stc(sp[i]);
            int val = stc.get<int>();
            obj->pushMiddle(val);
            ans.push_back("null");
        }
        else if (sf[i] == "pushBack")
        {
            TestCases stc(sp[i]);
            int val = stc.get<int>();
            obj->pushBack(val);
            ans.push_back("null");
        }
        else if (sf[i] == "popFront")
        {
            TestCases stc(sp[i]);
            int r = obj->popFront();
            ans.push_back(convert<string>(r));
        }
        else if (sf[i] == "popMiddle")
        {
            TestCases stc(sp[i]);
            int r = obj->popMiddle();
            ans.push_back(convert<string>(r));
        }
        else if (sf[i] == "popBack")
        {
            TestCases stc(sp[i]);
            int r = obj->popBack();
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
