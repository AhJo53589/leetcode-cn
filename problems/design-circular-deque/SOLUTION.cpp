
//////////////////////////////////////////////////////////////////////////
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
		data = vector<int>(k, 0);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
		if (isFull()) return false;
		ptrStart = (data.size() + ptrStart - 1) % data.size();
		data[ptrStart] = value;
		emptyFlag = false;
		return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        data[ptrEnd] = value;
		ptrEnd = (ptrEnd + 1) % data.size();
        emptyFlag = false;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
		if (isEmpty()) return false;
		ptrStart = (ptrStart + 1) % data.size();
		emptyFlag = (ptrStart == ptrEnd);
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
		ptrEnd = (data.size() + ptrEnd - 1) % data.size();
        emptyFlag = (ptrStart == ptrEnd);
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
		return data[ptrStart];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
		return data[(data.size() + ptrEnd - 1) % data.size()];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
		return emptyFlag;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
		return !emptyFlag && ptrEnd == ptrStart;
    }

private:
	vector<int> data;
	int ptrStart = 0;
	int ptrEnd = 0;
	bool emptyFlag = true;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

//////////////////////////////////////////////////////////////////////////
//int _solution_run(int)
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	cout << convert<string>(sf) << endl;
	vector<string> sp = tc.get<vector<string>>();
    cout << convert<string>(sp) << endl;
	vector<string> ans;

	MyCircularDeque *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MyCircularDeque")
		{
			TestCases stc(sp[i]);
			int k = stc.get<int>();
			obj = new MyCircularDeque(k);
			ans.push_back("null");
		}
		else if (sf[i] == "insertFront")
		{
			TestCases stc(sp[i]);
			int value = stc.get<int>();
			bool r = obj->insertFront(value);
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "insertLast")
		{
			TestCases stc(sp[i]);
			int value = stc.get<int>();
			bool r = obj->insertLast(value);
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "deleteFront")
		{
			TestCases stc(sp[i]);
			bool r = obj->deleteFront();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "deleteLast")
		{
			TestCases stc(sp[i]);
			bool r = obj->deleteLast();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "getFront")
		{
			TestCases stc(sp[i]);
			int r = obj->getFront();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "getRear")
		{
			TestCases stc(sp[i]);
			int r = obj->getRear();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "isEmpty")
		{
			TestCases stc(sp[i]);
			bool r = obj->isEmpty();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "isFull")
		{
			TestCases stc(sp[i]);
			bool r = obj->isFull();
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
