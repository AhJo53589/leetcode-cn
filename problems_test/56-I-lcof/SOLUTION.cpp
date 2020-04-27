
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    //输入: [1,2,1,3,2,5]
    //输出: [3,5]
    vector<int> singleNumbers(vector<int>& nums) {
        int s = 0;
        for (int num : nums) {
            s ^= num;
        }
        //s是只出现一次的2个数字的^ 记做数字a,b
        //既然a,b 不一样，那么s肯定不是0，那么s的二进制肯定至少有1位（第n位）是1，只有0^1才等于1
        //所以a,b 在第n位，要么a是0，b是1 ，要么b是0，a是1    ---->A
        //s = 3 ^ 5; 0011 ^ 0101 = 0110 = 6
        //假设int是8位
        //-6  原码1000 0110
        //    反码1111 1001
        //    补码1111 1010
        //s & (-s) 
        //  0000 0110
        //& 1111 1010
        //  0000 0010
        //所以k = s & (-s) 就是保留s的最后一个1，并且将其他位变为0  也就是s最后一个1是倒数第二位   --->B
        //由于s & (-s)很方便找到一个1 所以用他了，其实找到任何一个1都可以
        //根据A和B  我们可以确定 3 和 5 必定可以分到 不同的组里
        //同理 1和1 由于二进制完全相同，所有必定分到相同的组里
        int k = s & (-s);
        //1  0001  第一组
        //2  0010  第二组
        //1  0001  第一组
        //3  0011  第二组
        //2  0010  第二组
        //5  0101  第一组
        //第一组 1 1 5  第二组 2 3 2 这样我们就将2个只有一个的数 分到了2个数组里了
        vector<int> rs(2, 0);
        for (int num : nums) {
            if (num & k) {
                //第二组
                rs[0] ^= num;
            }
            else {
                //第一组
                rs[1] ^= num;
            }
        }
        return rs;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.singleNumbers(nums);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
