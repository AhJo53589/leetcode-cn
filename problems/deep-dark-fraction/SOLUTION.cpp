
//////////////////////////////////////////////////////////////////////////
//long long gcd(long long x, long long y)
//{
//	return y ? gcd(y, x%y) : x;
//}
//vector<int> fraction(vector<int>& cont) {
//	long long x, y, n = cont.size(), i;
//	x = cont[n - 1];
//	y = 1;
//	for (i = n - 2; ~i; i--)
//	{
//		swap(x, y);
//		x += cont[i] * y;
//	}
//	i = gcd(x, y);
//	x /= i;
//	y /= i;
//	vector<int> ans;
//	ans.push_back(x);
//	ans.push_back(y);
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void fraction(vector<int>& cont, size_t last, vector<int>& val)
{
	if (last == cont.size() - 1)
	{
		last--;
		val[0] = cont[last + 1];
		val[1] = cont[last] * cont[last + 1] + 1;
		cout << "val[0] = " << val[0] << ", val[1] = " << val[1] << endl;
	}
	else if (last != 0)
	{
		last--;
		int temp = val[1];
		val[1] = cont[last] * val[1] + val[0];
		val[0] = temp;
		cout << "val[0] = " << val[0] << ", val[1] = " << val[1] << endl;
	}
	int g = gcd(val[0], val[1]);
	val[0] /= g;
	val[1] /= g;
	cout << "val[0] = " << val[0] << ", val[1] = " << val[1] << endl;
	if (last == 0)
	{
		swap(val[0], val[1]);
		return;
	}
	fraction(cont, last, val);
}


//////////////////////////////////////////////////////////////////////////
vector<int> fraction(vector<int>& cont)
{
	if (cont.size() == 1) return { cont[0], 1 };
	vector<int> val(2, 0);
	fraction(cont, cont.size() - 1, val);
	return val;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& cont)
{
	return fraction(cont);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

