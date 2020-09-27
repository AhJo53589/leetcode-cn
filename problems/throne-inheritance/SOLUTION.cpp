
//////////////////////////////////////////////////////////////////////////
class ThroneInheritance {
public:
    ThroneInheritance(string kingName) : king(kingName) {
    }
    
    void birth(string parentName, string childName) {
        relation[parentName].push_back(childName);
    }
    
    void death(string name) {
        deathFlag.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(king, ans);
        return ans;
    }

private:
    void dfs(string name, vector<string>& ans) {
        if (deathFlag.find(name) == deathFlag.end()) {
            ans.push_back(name);
        }

        for (auto& child : relation[name]) {
            dfs(child, ans);
        }
    }

private:
    string king;
    unordered_map<string, vector<string>> relation;
    unordered_set<string> deathFlag;
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

	ThroneInheritance *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "ThroneInheritance")
		{
			TestCases stc(sp[i]);
			string kingName = stc.get<string>();
			obj = new ThroneInheritance(kingName);
			ans.push_back("null");
		}
		else if (sf[i] == "birth")
		{
			TestCases stc(sp[i]);
			string parentName = stc.get<string>();
			string childName = stc.get<string>();
			obj->birth(parentName, childName);
			ans.push_back("null");
		}
		else if (sf[i] == "death")
		{
			TestCases stc(sp[i]);
			string name = stc.get<string>();
			obj->death(name);
			ans.push_back("null");
		}
		else if (sf[i] == "getInheritanceOrder")
		{
			TestCases stc(sp[i]);
			vector<string> r = obj->getInheritanceOrder();
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
