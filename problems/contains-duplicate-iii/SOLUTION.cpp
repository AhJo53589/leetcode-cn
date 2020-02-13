
void test(int i, double d, long l, long long ll)
{
    cout.setf(ios::showpoint);
    cout.precision(12);

    cout << "//////////////////////////////////////////" << endl;
    cout << i << " - 3 = " << endl << endl;

    int to_int = d - 3;
    cout << "[double to int]: \t" << to_int << endl;
    double to_double = d - 3;
    cout << "[double to double]: \t" << to_double << endl;
    long to_long = d - 3;
    cout << "[double to long]: \t" << to_long << endl;
    long long to_longlong = d - 3;
    cout << "[double to long long]: \t" << to_longlong << endl;
    cout << endl;

    to_int = l - 3;
    cout << "[long to int]: \t" << to_int << endl;
    to_double = l - 3;
    cout << "[long to double]: \t" << to_double << endl;
    to_long = l - 3;
    cout << "[long to long]: \t" << to_long << endl;
    to_longlong = l - 3;
    cout << "[long to long long]: \t" << to_longlong << endl;
    cout << endl;

    to_int = ll - 3;
    cout << "[long long to int]: \t" << to_int << endl;
    to_double = ll - 3;
    cout << "[long long to double]: \t" << to_double << endl;
    to_long = ll - 3;
    cout << "[long long to long]: \t" << to_long << endl;
    to_longlong = ll - 3;
    cout << "[long long to long long]: \t" << to_longlong << endl;
    cout << endl;
}

bool helper(set<int>& temp, double i, int t) {
    auto m = temp.lower_bound(i - t);
    if (m != temp.end() && *m <= i + t)
        return true;
    return false;
}
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> temp;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        //int n = -2147483648;
        //test(n, n, n, n);
        if (helper(temp, nums[i], t)) {
            return true;
        }
        else {
            temp.insert(nums[i]);
        }
        if (temp.size() > k) {
            temp.erase(nums[i - k]);
        }
    }
    return false;
}

//////////////////////////////////////////////////////////////////////////
//bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
//{
//	set<double> _set;
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		auto s = _set.lower_bound((double)nums[i] - (double)t);
//		if (s != _set.end() && *s <= (double)nums[i] + (double)t) return true;
//
//		_set.insert(nums[i]);
//		if (_set.size() > k) _set.erase(nums[i - k]);
//	}
//	return false;
//}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& nums, int k, int t)
{
	return containsNearbyAlmostDuplicate(nums,k,t);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

