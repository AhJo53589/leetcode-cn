
//////////////////////////////////////////////////////////////////////////
static const double EPSILON = 1e-7;
class Solution {
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        vector2 p1(start1[0], start1[1]), p2(end1[0], end1[1]), p3(start2[0], start2[1]), p4(end2[0], end2[1]);
        if (p2 < p1)swap(p1, p2);
        if (p4 < p3)swap(p3, p4);
        vector2 p1p2 = p2 - p1, p3p4 = p4 - p3, p3p1 = p1 - p3, p4p1 = p1 - p4;

        if (fabs(p1p2 ^ p3p4) < EPSILON) {//所在直线平行或重合
            if (fabs(p4p1 ^ p3p1) < EPSILON) {//所在直线重合
                if (p4 < p1 || p2 < p3)return {};//线段不重合
                else {//线段有重合
                    if (p1 < p3)return { p3.x,p3.y };
                    else return { p1.x,p1.y };
                }
            }
            else return {};
        }
        else {//所在直线有一个交点
            double ratio = (p3p1 ^ p1p2) / (p3p4 ^ p1p2);
            vector2 ans = p3 * (1 - ratio) + p4 * ratio;
            if (p1 <= ans && ans <= p2 && p3 <= ans && ans <= p4)return { ans.x,ans.y };//在线段上
            else return {};
            /*stackoverflow方法：
            double u = (p3p1 ^ p1p2) / (p3p4 ^ p1p2);
            double t=(p3p1 ^ p3p4) / (p3p4 ^ p1p2);
            if(u>=0&&u<=1&&t>=0&&t<=1){
                vector2 ans=p1+p1p2*t;
                return {ans.x,ans.y};
            }
            else return {};*/
        }
    }

    struct vector2 {
        double x, y;
        vector2(double a, double b) :x(a), y(b) {}
        vector2(const vector2& v2) :x(v2.x), y(v2.y) {}
        vector2& operator=(const vector2& v2) {
            x = v2.x;
            y = v2.y;
            return *this;
        }
        vector2 operator+(const vector2& v2) { return vector2(x + v2.x, y + v2.y); }
        vector2 operator-(const vector2& v2) { return vector2(x - v2.x, y - v2.y); }
        double operator*(const vector2& v2) { return x * v2.x + y * v2.y; }
        vector2 operator*(double n) { return vector2(x * n, y * n); }
        double operator^(const vector2& v2) { return x * v2.y - y * v2.x; }
        bool operator==(const vector2& v2) { return fabs(x - v2.x) < EPSILON && fabs(y - v2.y) < EPSILON; }
        bool operator < (const vector2& v2) {
            if (x < v2.x)return true;
            if (fabs(x - v2.x) < EPSILON)return y < v2.y;
            return false;
        }
        bool operator <= (const vector2& v2) {
            if ((*this < v2) || (*this == v2))return true;
            else return false;
        }
    };
};

//////////////////////////////////////////////////////////////////////////
vector<double> _solution_run(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.intersection(start1, end1, start2, end2);
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
