
//////////////////////////////////////////////////////////////////////////
class NestedInteger;
std::vector<NestedInteger> getVectorNestedInteger(std::string input, char begin = '[', char end = ']', char pattern = ',');

class NestedInteger {
public:
	NestedInteger(std::string input)
	{
		if (input.find("[") != std::string::npos)
		{
			list = getVectorNestedInteger(input);
			isInt = false;
		}
		else
		{
			val = convert<int>(input);
			isInt = true;
		}
	}

	bool isInteger() const { return isInt; }
	int getInteger() const { return val; }
	const vector<NestedInteger>& getList() const { return list; }

private:
	bool isInt;
	int val;
	vector<NestedInteger> list;
};

std::vector<NestedInteger> getVectorNestedInteger(std::string input, char begin/* = '['*/, char end/* = ']'*/, char pattern/* = ','*/)
{
	std::vector<NestedInteger> output;

	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	std::vector<std::size_t> pos = stringGetSplitPos(input, begin, end, pattern);
	if (!pos.empty()) return {};

	input = input.substr(1, input.size() - 2);
	if (input.empty()) return {};
	input += pattern;
	pos = stringGetSplitPos(input, begin, end, pattern);
	if (pos.empty()) return {};

	std::size_t cur = 0;
	for (auto& i : pos)
	{
		output.push_back(NestedInteger(input.substr(cur, i - cur)));
		cur = i + 1;
	}

	return output;
}


//////////////////////////////////////////////////////////////////////////
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger>& nestedList) : pool(vector<int>()), i(0) {
        for (auto& n : nestedList)
        {
            parse(n);
        }
    }

    void parse(NestedInteger& item)
    {
        if (item.isInteger())
        {
            pool.push_back(item.getInteger());
        }
        else
        {
            auto v = item.getList();
            for (auto it = v.begin(); it != v.end(); it++)
            {
                parse(*it);
            }
        }
    }

    int next() {
        return pool[i++];
    }

    bool hasNext() {
        return i < pool.size();
    }

private:
    vector<int> pool;
    int i;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

//////////////////////////////////////////////////////////////////////////
//int _solution_run(int)
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	string sf = tc.get<string>();
    vector<NestedInteger> nestedList = getVectorNestedInteger(sf);

    vector<int> ans;
    NestedIterator i(nestedList);
    while (i.hasNext())
    {
        ans.push_back(i.next());
    }
	return convert<string>(ans);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
