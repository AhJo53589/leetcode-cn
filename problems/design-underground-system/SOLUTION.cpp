//////////////////////////////////////////////////////////////////////////
class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkRecord[id] = { stationName, t };
    }
    
    void checkOut(int id, string stationName, int t) {
        string name = getStationName(checkRecord[id].first, stationName);
        t -= checkRecord[id].second;
        count[name].first += (double)t;
        count[name].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string name = getStationName(startStation, endStation);
        double ans = count[name].first / (double)count[name].second;
        return ans;
    }

private:
    string getStationName(string startStation, string endStation)
    {
        return startStation + endStation;
    }

    unordered_map<int, pair<string, int>> checkRecord;
    unordered_map<string, pair<double, int>> count;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
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

    UndergroundSystem *obj = nullptr;
    for (auto i = 0; i < sf.size(); i++)
    {
        if (sf[i] == "UndergroundSystem")
        {
            obj = new UndergroundSystem();
            ans.push_back("null");
        }
        else if (sf[i] == "checkIn")
        {
            TestCases stc(sp[i]);
            int id = stc.get<int>();
            string stationName = stc.get<string>();
            int t = stc.get<int>();
            obj->checkIn(id, stationName, t);
            ans.push_back("null");
        }
        else if (sf[i] == "checkOut")
        {
            TestCases stc(sp[i]);
            int id = stc.get<int>();
            string stationName = stc.get<string>();
            int t = stc.get<int>();
            obj->checkOut(id, stationName, t);
            ans.push_back("null");
        }
        else if (sf[i] == "getAverageTime")
        {
            TestCases stc(sp[i]);
            string startStation = stc.get<string>();
            string endStation = stc.get<string>();
            double r = obj->getAverageTime(startStation, endStation);
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
//    return {};
//}
