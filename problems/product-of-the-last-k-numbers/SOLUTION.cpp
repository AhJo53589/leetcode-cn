
//////////////////////////////////////////////////////////////////////////
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
		nums.push_back(num);
    }
    
    int getProduct(int k) {
		int p = 1;
		for (auto i = nums.size() - k; i < nums.size(); i++)
		{
			p *= nums[i];
		}
		return p;
    }
private:
	vector<int> nums;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
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

	ProductOfNumbers *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "ProductOfNumbers")
		{
			obj = new ProductOfNumbers();
			ans.push_back("null");
		}
		else if (sf[i] == "add")
		{
			TestCases stc(sp[i]);
			int num = stc.get<int>();
			obj->add(num);
			ans.push_back("null");
		}
		else if (sf[i] == "getProduct")
		{
			TestCases stc(sp[i]);
			int k = stc.get<int>();
			int r = obj->getProduct(k);
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
