
//////////////////////////////////////////////////////////////////////////
#define N 101
#define LL long long
#define INF 0xfffffff
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = ~0u >> 2;  
        
struct point{
    double x, y;
    point(double x = 0, double y = 0) :x(x), y(y) {}
}p[N];

double dis(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int dcmp(double x) {
    if (fabs(x) < eps)return 0;
    else return x < 0 ? -1 : 1;
}

point getcircle(point p1, point p2, double r) {
    point dir(p1.y - p2.y, p2.x - p1.x);
    point mid((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    double d = sqrt(r * r - dis(p1, mid) * dis(p1, mid));
    double detX = d * dir.x / sqrt(dir.x * dir.x + dir.y * dir.y);
    double detY = d * dir.y / sqrt(dir.x * dir.x + dir.y * dir.y);
    return point(mid.x + detX, mid.y + detY);
}

class Solution {
public:

    int numPoints(vector<vector<int>>& points, int ir) {
        int n = points.size();
        for (int i = 1; i <= n; i++) {
            p[i].x = points[i - 1][0];
            p[i].y = points[i - 1][1];
        }
        int maxz = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || dcmp(dis(p[i], p[j]) - 2 * ir) > 0) {
                    continue;
                }
                int tmax = 0;
                point cir = getcircle(p[i], p[j], ir);
                for (int g = 1; g <= n; g++)
                {
                    if (dcmp(dis(cir, p[g]) - ir) > 0)
                        continue;
                    tmax++;
                }
                maxz = max(maxz, tmax);
            }
        }
        return maxz;
    }
};


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& points, int r)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numPoints(points, r);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
