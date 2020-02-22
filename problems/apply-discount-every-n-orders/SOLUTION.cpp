
//////////////////////////////////////////////////////////////////////////
class Cashier {
public:
	Cashier(int n, int discount, vector<int>& products, vector<int>& prices)
		: m_cnt(0), m_n(n), m_discount(discount)
	{
		for (int i = 0; i < products.size(); i++)
		{
			m_prices[products[i]] = prices[i];
		}
	}

	double getBill(vector<int> product, vector<int> amount)
	{
		m_cnt = (m_cnt + 1) % m_n;

		double ans = 0.f;
		for (int i = 0; i < product.size(); i++)
		{
			ans += m_prices[product[i]] * amount[i];
		}

		if (m_cnt == 0)
		{
			ans = ans * (double)(100 - m_discount) / (double)100.f;
		}
		return ans;
	}

private:
	int m_cnt;
	int m_n;
	int m_discount;
	unordered_map<int, int> m_prices;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
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

	Cashier *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "Cashier")
		{
			TestCases stc(sp[i]);
			int n = stc.get<int>();
			int discount = stc.get<int>();
			vector<int> products = stc.get<vector<int>>();
			vector<int> prices = stc.get<vector<int>>();
			obj = new Cashier(n, discount, products, prices);
			ans.push_back("null");
		}
		else if (sf[i] == "getBill")
		{
			TestCases stc(sp[i]);
			vector<int> product = stc.get<vector<int>>();
			vector<int> amount = stc.get<vector<int>>();
			double r = obj->getBill(product, amount);
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
