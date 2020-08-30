
// ����������A��B�����ֲ����ֱ��� + 12�� - 12�� + 7�� - 7�� + 5�� - 5��
// A�������ɴβ��������B ����������2����A��B��Ҫ�����任���̣������еĲ������о���һ��·����Ҳ�������ٵĲ������� ��
// ����˼·�ʹ���

//////////////////////////////////////////////////////////////////////////
// ����� target Ϊ A �� B �Ĳ�ֵ
// vector<int> Ϊ���ֲ����Ĳ���������[0] = ��12��[1] = ��7��[2] = ��5
// �� {0,1,-1} ��ʾ��1 �� +7 �� 1 �� -5
// ���ص� int Ϊ���ٲ�������
class Solution {
public:
	int minMove(int target, vector<int>& ops) {
		queue<pair<int, vector<int>>> que;
        que.push({ op[0], {1,0,0} });
        que.push({ op[1], {0,1,0} });
        que.push({ op[2], {0,0,1} });

		while (!que.empty()) {
			for (int len = que.size() - 1; len >= 0; len--) {
				auto [t, v] = que.front();
				que.pop();

				if (t == target) {
					ops = v;
					return getTimes(v);
				}
				if (t >= data.size() || !data[t].empty()) continue;
				data[t] = v;

				for (int k = -1; k <= 1; k += 2) {
					for (int i = 0; i < op.size(); i++) {
						int temp = t + k * op[i];
						if (temp >= data.size() || temp < 0 || !data[temp].empty()) continue;
						v[i] += k;
						que.push({ temp, v });
						v[i] -= k;
					}
				}
			}
		}

		return 0;
    }

	int getTimes(vector<int>& ops) {
		return abs(ops[0]) + abs(ops[1]) + abs(ops[2]);
	}

private:
	vector<int> op = { 12,7,5 };

	vector<vector<int>> data = vector<vector<int>>(5 * 7 * 12, vector<int>());
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int target)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};
	cout << "target = " << target << endl;
	vector<int> ops = vector<int>(3, 0);
	Solution sln;
	int ans = sln.minMove(target, ops);
	cout << "explain: ";
	//cout << "\t��" << ops[0] << " �� 12��\t��" << ops[1] << " �� 7�� \t��" << ops[2] << " �� 5��" << endl;
	printVectorT(ops);
	cout << endl;
	return ans;
}

