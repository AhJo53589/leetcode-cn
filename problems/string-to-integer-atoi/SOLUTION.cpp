
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int myAtoi(string str)
    {
        int ans = 0;
        int i = 0;
        int negative = 1;
        while (i < str.size() && str[i] == ' ')
        {
            i++;
        }

        if (i < str.size() && str[i] == '+')
        {
            i++;
        }
        else if (i < str.size() && str[i] == '-')
        {
            i++;
            negative = -1;
        }

        while (i < str.size() && isdigit(str[i]) && ans != INT_MAX)
        {
            int n = str[i] - '0';
            if (ans > (INT_MAX - n) / 10)
            {
                return negative == 1 ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + n;
            i++;
        }
        return negative * ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string str)
{
    Solution sln;
	return sln.myAtoi(str);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

