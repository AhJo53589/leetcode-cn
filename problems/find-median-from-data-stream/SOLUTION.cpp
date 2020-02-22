
//////////////////////////////////////////////////////////////////////////
class MedianFinder {
	priority_queue<int> lo;                              // max heap
	priority_queue<int, vector<int>, greater<int>> hi;   // min heap

public:
	// Adds a number into the data structure.
	void addNum(int num)
	{
		if (lo.empty() || num < lo.top())
		{
			lo.push(num);
			if (lo.size() > hi.size() + 1)
			{
				hi.push(lo.top());
				lo.pop();
			}
		}
		else
		{
			hi.push(num);
			if (lo.size() < hi.size())
			{
				lo.push(hi.top());
				hi.pop();
			}
		}
	}
	//void addNum(int num)
	//{
	//	lo.push(num);                                    // Add to max heap

	//	hi.push(lo.top());                               // balancing step
	//	lo.pop();

	//	if (lo.size() < hi.size()) {                     // maintain size property
	//		lo.push(hi.top());
	//		hi.pop();
	//	}
	//}

	// Returns the median of current data stream
	double findMedian()
	{
		return lo.size() > hi.size() ? (double)lo.top() : (lo.top() + hi.top()) * 0.5;
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
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

	MedianFinder *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MedianFinder")
		{
			obj = new MedianFinder();
			ans.push_back("null");
		}
		else if (sf[i] == "addNum")
		{
			TestCases stc(sp[i]);
			int num = stc.get<int>();
			obj->addNum(num);
			ans.push_back("null");
		}
		else if (sf[i] == "findMedian")
		{
			TestCases stc(sp[i]);
			double r = obj->findMedian();
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
