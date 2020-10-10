
//////////////////////////////////////////////////////////////////////////
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {

    }
    
    bool addCar(int carType) {

    }
};

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

	ParkingSystem *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "ParkingSystem")
		{
			TestCases stc(sp[i]);
			int big = stc.get<int>();
			int medium = stc.get<int>();
			int small = stc.get<int>();
			obj = new ParkingSystem(big, medium, small);
			ans.push_back("null");
		}
		else if (sf[i] == "addCar")
		{
			TestCases stc(sp[i]);
			int carType = stc.get<int>();
			bool r = obj->addCar(carType);
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
